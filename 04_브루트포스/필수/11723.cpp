// 11723: 집합 (실버5/비트마스킹)
#include <iostream>
using namespace std;
/**[백준 11723] 집합
/* - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
/*   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */

void all(int& s) //모든 원소를 집합에 추가
{
    s = (1 << 21) - 1; //21번째 비트까지 모두 1로 채움
}

void empty(int& s) //집합 비우기
{
    s = 0;
}

void add(int& s, int n) //원소 n을 집합에 추가
{
    s |= (1 << n); //n번째 비트를 1로 설정
}

void remove(int& s, int n) //n을 집합에서 제거
{
    s &= ~(1 << n); //n번째 비트를 0으로 설정
}

int check(int& s, int n) //원소 n이 집합에 있는지 확인
{
    if (s & (1 << n)) //n번째 비트가 1이면
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void toggle(int& s, int n) //원소 n이 있으면 제거 없으면 추가함
{
    s ^= (1 << n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, s = 0;
    string op;
    cin >> m;
    while (m--)
    {
        cin >> op;

        // x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all") //모든 원소 추가
        {
            all(s);
        }
        else if (op == "empty") //집합 초기화
        {
            empty(s);
        }

        // x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else
        {
            cin >> x;
            if (op == "add")
            {
                add(s, x); //x추가
            }
            else if (op == "remove")
            {
                remove(s, x); //x제거
            }
            else if (op == "check")
            {
                cout << check(s, x) << "\n"; //x존재여부 출력
            }
            else if (op == "toggle")
            {
                toggle(s, x); 
            }
        }
    }
    return 0;
}