// 1476: 날짜 계산 (실버5/브루트포스)
#include <iostream>

using namespace std;

int solve(int earth, int sun, int moon)
{
    if (earth == 15) //지구의범위가 15임
        earth = 0;
    if (sun == 28) //태양의범위가 28임
        sun = 0;
    if (moon == 19) //달의범위가 19임
        moon = 0;
    // 행성의(지구, 태양, 달) 범위에 해당하면 0으로 바꾸어준다.
    // 아래 비교문에서 mod 연산을 사용했기 때문에 이를 고려한다.

    int year = 1;
    while (true)
    {
        if (year % 15 == earth && year % 28 == sun && year % 19 == moon) //e s m으로 표시되는 가장 빠른 년도를 구한다.
        {
            return year;
        }
        year++;
    }
}

int main()
{
    // 입력
    int e, s, m;
    cin >> e >> s >> m;

    // 연산 & 출력
    cout << solve(e, s, m);

    return 0;
}