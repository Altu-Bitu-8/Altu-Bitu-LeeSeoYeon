#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//A-S�� D�� ����������ٸ� �����̴� ������ ã�� �� �ִ�
// >> A-S���� �ִ������� ���Ѵ�


int howsD(vector<int>& A, int N, int S) {
    int gcd = abs(A[0] - S); //���� 
    //ù �������� A[0], A[1]�� �ִ������� ���� ��
    //���� �ִ������� �� ���ҵ��� �ִ������� ���ϸ� ��

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
    vector <int> A(N); //������ ��ġ ���� �迭

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << howsD(A, N, S);
}
