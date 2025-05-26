#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;


void postorder(int start, int end) {
    if (start > end) return;

    int root = preorder[start];
    int divide = end + 1;

    for (int i = start + 1; i <= end; ++i) {
        if (preorder[i] > root) {
            divide = i;
            break;
        }
    }



    postorder(start + 1, divide - 1);
    postorder(divide, end);
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while (cin >> x) {
        preorder.push_back(x);
    }

    postorder(0, preorder.size() - 1);

    return 0;
}
