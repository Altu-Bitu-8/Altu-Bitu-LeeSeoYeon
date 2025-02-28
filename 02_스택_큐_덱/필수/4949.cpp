#include <iostream>
#include <stack>
#include <string>

using namespace std;

string check(const string& e) {
    stack<char> s; //��ȣ�� �޾Ƽ� ����
    for (char ch : e) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            else {
                return "no";
            }
        }
        else if (ch == ']') {
            if (!s.empty() && s.top() == '[') {
                s.pop();
            }
            else {
                return "no"; 
            }
        }
    }
    return s.empty() ? "yes" : "no"; //������� ��Ī
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string e;

    while (true) {
        getline(cin, e); 
        if (e == ".") {//��������
            break;
        }
        e.pop_back();

        cout << check(e) << "\n";
    }

    return 0;
}
