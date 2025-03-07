#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//A-S가 D로 나누어떨어진다면 수빈이는 동생을 찾을 수 있다
// >> A-S들의 최대공약수를 구한다


int howsD(vector<int>& A, int N, int S) {
    int gcd = abs(A[0] - S); //절댓값 
    //첫 연산으로 A[0], A[1]의 최대공약수를 구한 후
    //나온 최대공약수와 뒷 원소들의 최대공약수를 구하면 됨

    for (int i = 1; i < N; i++) {
        int b = abs(A[i] - S);
        while (b) {
            gcd %= b;
            swap(gcd, b);
        }
    }

    return gcd;
}


int main() {
    int N, S;
    cin >> N >> S;
    vector <int> A(N); //동생의 위치 담을 배열

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << howsD(A, N, S);
}
