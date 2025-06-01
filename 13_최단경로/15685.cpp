#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;

// ����: ��(0), ��(1), ��(2), ��(3)
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

// 1x1 ���簢�� ���� ���
int cntSquares(vector<vector<bool>>& plane) {
    int ans = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //�� �������� ��� true��
            if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1]) {
                ans++; //����
            }
        }
    }
    return ans;
}

// ��鿡 �巡�� Ŀ�긦 ǥ��
void drawDragonCurve(vector<vector<bool>>& plane, int x, int y, int d, int g) {
    vector<int> direct; // ���� ����
    plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; // ��鿡 ǥ�� (�ʱ�ȭ)

    x += dx[d];
    y += dy[d];
    direct.push_back(d);//���� ����

    while (g--) { // 1 ~ g ����
        int size_d = direct.size();
        for (int j = size_d - 1; j >= 0; j--) { // ���� ���
            int next_d = (direct[j] + 1) % 4;//ȸ��
            x += dx[next_d];
            y += dy[next_d];
            plane[y][x] = true; // ��鿡 ǥ��
            direct.push_back(next_d);
        }
    }
}

/*
* ��Ģ
* 0 ����: 0
* 1 ����: 0 1
* 2 ����: 0 1 2 1
* 3 ����: 0 1 2 1 2 3 2 1
* ...
* N ����: concat((N-1����), ((N-1���� �Ųٷ�) + 1)%4)
* ���(���� ����� (0, 0))�� �巡�� Ŀ�긦 �׸� �� ���簢���� ������ ���
* �巡�� Ŀ��� ��� ������ ������ �������� ������ Ȯ���� �ʿ� ����
* 1. 0 ������ �巡�� Ŀ�긦 ���� ���� (�ʱ� ����)
* 2. ���븦 �ŵ��ϸ鼭 �巡�� Ŀ�긦 �׸� (��Ģ�� �ľ��ϴ� ���� �߿�)
* 3. �巡�� Ŀ�갡 �׷��� ��� ���� ���簢���� ���� ��� (�� ������ Ȯ��)
*/

int main()
{
    int n, x, y, d, g;
    vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false)); // ���

    // �Է�
    cin >> n;

    // ����
    while (n--) { // n���� �巡�� Ŀ�� �׸���
        cin >> x >> y >> d >> g;
        drawDragonCurve(plane, x, y, d, g);
    }

    // ���
    cout << cntSquares(plane) << '\n';
    return 0;
}