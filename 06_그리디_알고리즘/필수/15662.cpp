// 15662: 톱니바퀴2

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; //톱니바퀴 저장 벡터
vector<pair<int, int>> stack; //회전 명령(톱니바퀴 번호, 방향) 저장 스택
vector<int> visited; //이미 회전했는지 확인하기 위한 벡터

void check_rotation(int current_num, int current_dir) //톱니바퀴가 회전하는지 체크하는 함수
{
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) //왼쪽에 톱니바퀴가 있고 아직 확인하지 않은 경우
    {
        if (li[current_num][6] != li[current_num - 1][2])
        { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); //반대방향으로 회전
            visited[current_num - 1] = 1; //확인 처리
            check_rotation(current_num - 1, current_dir * -1); //왼쪽으로 이동
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) //오른쪽에 톱니바퀴가 있고 아직 확인하지 않은 경우
    {
        if (li[current_num][2] != li[current_num + 1][6])
        { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num + 1, current_dir * -1));//반대방향으로 회전
            visited[current_num + 1] = 1; //확인 처리
            check_rotation(current_num + 1, current_dir * -1); //오른쪽으로 이동
        }
    }
}

int main()
{
    int t;
    int k;

    cin >> t; // 톱니바퀴의 개수 T 입력

    li.resize(t); // 톱니바퀴 개수만큼 resize
    for (int i = 0; i < t; ++i)
        cin >> li[i]; // 톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i)
    { // k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction; 
        cin >> num >> direction; // 방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear(); //회전 스택 초기화
        stack.push_back(make_pair(num - 1, direction)); //회전 명령
        visited.assign(t, 0); // t개만큼 0을 초기화
        visited[num - 1] = 1; //회전했다고 처리함
        check_rotation(num - 1, direction); //옆의 톱니 회전하는지 확인

        while (!stack.empty()) //회전 명령이 있는 동안 계속
        {
            pair<int, int> top = stack.back(); //스택에서 마지막 회전 명령 가져옴
            stack.pop_back(); //스택에서 제거
            int tmp_num = top.first;  // 돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; // 돌릴 방향
            if (tmp_dir == 1)
            { // 시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
            }
            else
            { // 반시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; ++i)
    {
        if (li[i][0] == '1') //12시방향 톱니가 1이면 카운트 증가
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}