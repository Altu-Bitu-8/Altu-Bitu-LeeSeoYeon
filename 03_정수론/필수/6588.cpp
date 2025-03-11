#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(1000001, true);
vector<int> odd;

void oddPrime() {
    //1000000 이하의 모든 소수를 구해놓기 
    for (int i = 2; i <= 1000000; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            isPrime[j] = false;
        }
    }

    // 홀수만 저장
    for (int i = 3; i <= 1000000; i += 2) {
        if (isPrime[i]) odd.push_back(i);
    }
}

void goldbach(int n) {
    //a가 가장 작은 값이면 b-a가 최대일 것이므로 그 경우를 출력
    bool isWrong = true; //합이 없는 경우 체크

    for (int a : odd) {
        int b = n - a;
        if ((b > 2) && (isPrime[b])) {
            cout << n << " = " << a << " + " << b << "\n";
            isWrong = false;
            break;
        }
    }
    if (isWrong) {
        cout << "Goldbach's conjecture is wrong.";
    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    oddPrime();

    int n;
    while ((cin >> n) && (n != 0)) {
        goldbach(n);
    }

}
