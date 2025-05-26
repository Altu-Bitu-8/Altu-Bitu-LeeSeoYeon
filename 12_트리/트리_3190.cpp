#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

const int EMPTY = 0; //빈칸
const int APPLE = 1;// 사과가 있는 칸
const int SNAKE = 2; //몸통이 있는 칸

/**
 * 게임이 몇 초에 끝나는지 계산한다.
*/
int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    // 동(→), 남(↓), 서(←), 북(↑)
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    // 초기화
    deque<ci> snake; // 뱀의 위치 정보
    snake.push_front({ 1, 1 }); //초기위치 (1,1)
    board[1][1] = SNAKE;

    int time = 0; // 현재 시간
    int dir = 0;  // 현재 방향
    while (true) {
        // 방향 변환 정보가 있다면
        if (cmd[time] == 'L') { // 왼쪽 회전
            dir = (dir + 1) % 4;
        }
        else if (cmd[time] == 'D') { // 오른쪽 회전
            dir = (dir + 3) % 4;
        }

        // 시간 증가
        time++;

        // 다음에 뱀의 머리가 위치하게 될 칸
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 게임 종료 조건: 벽에 부딪히거나, 자기자신의 몸에 부딪힘
        if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == SNAKE) {
            break;
        }

        // 이동
        snake.push_front({ nx, ny }); // 머리를 다음 칸에 위치시킴
        if (board[nx][ny] != APPLE) { // 이동한 칸에 사과가 없다면(몸길이가 그대로라면) 꼬리를 다음 칸에 위치시킴
            ci tail = snake.back(); //꼬리 좌표 저장
            board[tail.first][tail.second] = EMPTY; //꼬리 위치 비우기
            snake.pop_back(); //꼬리 제거
        }
        board[nx][ny] = SNAKE; //새 위치 표시
    }
    return time;
}

int main() {
    int n, k, x, y, l, time;
    char command;

    //입력
    cin >> n >> k;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, EMPTY)); //보드 생성
    while (k--) {
        cin >> x >> y;
        board[x][y] = APPLE; // 사과의 위치 표시
    }
    cin >> l;
    map<int, char> cmd;
    while (l--) {
        cin >> time >> command; // 뱀의 방향 변환 정보
        cmd[time] = command;
    }

    // 연산 및 출력
    cout << playGame(n, board, cmd);
    return 0;
}