#include <iostream>
#include <stack>
#include <string>

using namespace std;

string check(const string& e) {
    stack<char> s; //괄호만 받아서 저장
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
    return s.empty() ? "yes" : "no"; //비었으면 대칭
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string e;

    while (true) {
        getline(cin, e); 
        if (e == ".") {//종료조건
            break;
        }
        e.pop_back();

        cout << check(e) << "\n";
    }

    return 0;
}
