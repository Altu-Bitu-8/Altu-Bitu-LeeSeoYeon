#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

const int EMPTY = 0; //��ĭ
const int APPLE = 1;// ����� �ִ� ĭ
const int SNAKE = 2; //������ �ִ� ĭ

/**
 * ������ �� �ʿ� �������� ����Ѵ�.
*/
int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    // ��(��), ��(��), ��(��), ��(��)
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    // �ʱ�ȭ
    deque<ci> snake; // ���� ��ġ ����
    snake.push_front({ 1, 1 }); //�ʱ���ġ (1,1)
    board[1][1] = SNAKE;

    int time = 0; // ���� �ð�
    int dir = 0;  // ���� ����
    while (true) {
        // ���� ��ȯ ������ �ִٸ�
        if (cmd[time] == 'L') { // ���� ȸ��
            dir = (dir + 1) % 4;
        }
        else if (cmd[time] == 'D') { // ������ ȸ��
            dir = (dir + 3) % 4;
        }

        // �ð� ����
        time++;

        // ������ ���� �Ӹ��� ��ġ�ϰ� �� ĭ
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // ���� ���� ����: ���� �ε����ų�, �ڱ��ڽ��� ���� �ε���
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) {
            break;
        }

        // �̵�
        snake.push_front({ nx, ny }); // �Ӹ��� ���� ĭ�� ��ġ��Ŵ
        if (board[nx][ny] != APPLE) { // �̵��� ĭ�� ����� ���ٸ�(�����̰� �״�ζ��) ������ ���� ĭ�� ��ġ��Ŵ
            ci tail = snake.back(); //���� ��ǥ ����
            board[tail.first][tail.second] = EMPTY; //���� ��ġ ����
            snake.pop_back(); //���� ����
        }
        board[nx][ny] = SNAKE; //�� ��ġ ǥ��
    }
    return time;
}

int main() {
    int n, k, x, y, l, time;
    char command;

    //�Է�
    cin >> n >> k;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY)); //���� ����
    while (k--) {
        cin >> x >> y;
        board[x][y] = APPLE; // ����� ��ġ ǥ��
    }
    cin >> l;
    map<int, char> cmd;
    while (l--) {
        cin >> time >> command; // ���� ���� ��ȯ ����
        cmd[time] = command;
    }

    // ���� �� ���
    cout << playGame(n, board, cmd);
    return 0;
}