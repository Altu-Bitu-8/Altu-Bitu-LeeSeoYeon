#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num1, num2;
    cin >> num1 >> num2;

    vector<int> n1, n2;//한자리씩 저장

    for (char ch : num1) {
        digits1.push_back(ch - '0');  
    }

    for (char ch : num2) {
        digits2.push_back(ch - '0');
    }

    vector<int> res; //덧셈 결과
    int carry = 0; //올림수

    int i = n1.size() - 1;
    int j = n2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += n1[i];
            i--;
        }
        if (j >= 0) {
            sum += n2[j];
            j--;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    for (int k = res.size() - 1; k >= 0; --k) {
        cout << res[k];
    }
}
