#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


bool wordCount(vector<int>& count, string& word) {
    vector<int> tempCount(count); // count 배열을 복사하여 임시 배열로 사용
    bool isSame = false;

    for (char c : word) {
        int wordNum = c - 'A';
        tempCount[wordNum] -= 1;
    }

    // 원소가 모두 0이라면 두 단어는 같은 구성을 가짐
    int vectorCount = 0; // 0이 아닌 원소의 개수를 체크할 변수
    int not0Check1 = 0, not0Check2 = 0;

    for (int i = 0; i < 26; i++) { // A~Z까지 돌며 확인
        if (tempCount[i] != 0) {
            vectorCount++;
            if (vectorCount == 3) {
                break;
            }
            else if (vectorCount == 2) {
                not0Check2 = i;
            }
            else if (vectorCount == 1) not0Check1 = i;
        }
    }
    if ((vectorCount == 1) && (abs(tempCount[not0Check1]) == 1)) {
        isSame = true;

    }

    else if (vectorCount == 0) {
        isSame = true;

    }

    else if (vectorCount == 2) {
        if ((abs(tempCount[not0Check1]) == 1) && (tempCount[not0Check1] + tempCount[not0Check2] == 0)) {
            isSame = true;

        }
    }


    return isSame;
}


int main() {
    int n;
    cin >> n;

    string word1;
    vector <int> count(26, 0);
    int sameCount = 0; //비슷한 단어가 몇 개인지 체크할 변수

    bool isSame = false;

    cin >> word1;

    for (char c : word1) {
        int word1Num = c - 'A';
        count[word1Num] += 1;
    } //첫번째 단어의 알파벳을 체크한 후 저장.


    string word; //첫번째 이후 입력받는 문자들
    for (int i = 0; i < n - 1; i++) { //n-1번 반복
        cin >> word;
        if (wordCount(count, word)) {
            sameCount++;
        }
    }

    cout << sameCount;
}

