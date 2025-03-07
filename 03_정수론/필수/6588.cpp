#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(1000001, true);
vector<int> odd;

void oddPrime() {
    //1000000 ������ ��� �Ҽ��� ���س��� 
    for (int i = 2; i <= 1000000; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            isPrime[j] = false;
        }
    }

    // Ȧ���� ����
    for (int i = 3; i <= 1000000; i += 2) {
        if (isPrime[i]) odd.push_back(i);
    }
}

void goldbach(int n) {
    //a�� ���� ���� ���̸� b-a�� �ִ��� ���̹Ƿ� �� ��츦 ���
    bool isWrong = true; //���� ���� ��� üũ

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
