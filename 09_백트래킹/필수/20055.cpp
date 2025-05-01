#include <iostream>
#include <vector>

using namespace std;


struct container {
	int id;
	int hp;
	bool isRobot = false;
};

//��Ʈ�� �� ĭ ���� �κ��� �Բ� �� ĭ ȸ��
void firstRound(int n, vector <container> &all) {
	container tmp = all[2 * n - 1];
	
	for (int i = 2 * n - 1; i > 0; i--) {
		all[i] = all[i - 1];
	}
	all[0] = tmp;

	//ȸ�� �� ������ ��ġ�� �κ� �ֳ� üũ...
	if (all[n-1].isRobot)
		all[n-1].isRobot = false;
}

//�κ� �̵�
void secondRound(int n, vector <container> &all) {
	for (int i = n - 2; i > 0; i--) {
		//���� �ö�� �κ����� ���� �ϴϱ� ��������
		if (all[i].isRobot && !all[i+1].isRobot && all[i+1].hp>=1) {
			all[i].isRobot = false;
			all[i + 1].hp--;

			if (i + 1 == n-1) { //�� ĭ �̵����� �� ������ ��ġ���
				all[i + 1].isRobot = false;
			} 
			else
				all[i+1].isRobot = true;
		}
	}

}

//�κ� �ø���
void thirdRound(int n, vector <container>& all) {
	if (all[0].hp > 0) {
		all[0].isRobot = true;
		all[0].hp--;
	}
}

//��������... ������ üũ
bool countHP(int n,int k, vector <container>& all) {
	int count = 0;
	for (int i = 0; i < 2*n; i++) {
		if (all[i].hp == 0)
			count++;
	}
	if (count >= k)
		return false;
	else
		return true;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector <container> all(2 * n);

	for (int i = 0; i < 2 * n; i++) {
		all[i].id = i;
		cin >> all[i].hp;
	}

	int count = 0;

	while(true){
		count++;
		firstRound(n, all);
		secondRound(n, all);
		thirdRound(n, all);
		if(!countHP(n,k,all))
			break;
	}

	cout << count;

}
