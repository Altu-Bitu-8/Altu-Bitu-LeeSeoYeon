#include <iostream>
#include <deque>

using namespace std;

void draw(deque<int>& dq, deque<int>& ground) {
	ground.push_front(dq.front());
	dq.pop_front();
}

void ring(deque<int>& dq, deque<int>& ground1, deque<int>& ground2) {
	for (int i = ground2.size() - 1; i >= 0; i--) {
		dq.push_back(ground2[i]);
	}
	for (int i = ground1.size() - 1; i >= 0; i--) {
		dq.push_back(ground1[i]);
	}
	ground1.clear();
	ground2.clear();
}

int main() {
	int n, m;
	cin >> n >> m;

	deque <int> doDq(n);
	deque <int> suDq(n);
	deque <int> doGround;
	deque <int> suGround;

	for (int i = n - 1; i >= 0; i--) {
		cin >> doDq[i];
		cin >> suDq[i];
	}

	bool doTurn = true; //도도 차례

	while (m--) {
		if (doTurn) {
			draw(doDq, doGround);
		}
		else {
			draw(suDq, suGround);
		}

		if (doDq.empty()) {
			cout << "su";
			return 0;
		}
		if (suDq.empty()) {
			cout << "do";
			return 0;
		}

		if (!doGround.empty() && doGround.front() == 5) {
			ring(doDq, doGround, suGround);
		}
		else if (!suGround.empty() && suGround.front() == 5) {
			ring(doDq, doGround, suGround);
		}
		else if (!doGround.empty() && !suGround.empty() && doGround.front() + suGround.front() == 5) {
			ring(suDq, suGround, doGround);
		}

		doTurn = !doTurn;
	}

	if (doDq.size() > suDq.size()) cout << "do";
	else if (doDq.size() < suDq.size()) cout << "su";
	else cout << "dosu";
}
