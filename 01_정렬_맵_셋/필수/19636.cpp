#include <iostream>

using namespace std;

struct Desi {
	int w, l0, T, D, l, A;
	int afterW, afterL;
	bool die;
};


void calWeight(struct Desi& d, bool ischange) {
	double change = 0, j = 0;//j´Â Àý´ñ°ª ±¸ÇÏ·Á°í µÒ
	bool die = false;
	d.afterL = d.l0;
	for (int i = 1; i <= d.D; i++) {
		change = d.l - (d.afterL + d.A);
		d.w += change;
		if (ischange)
		{
			if (change < 0)
				j = change * (-1);
			if (j > d.T) {
				d.afterL += change / 2;
			}
		}
		if (d.w <= 0 || d.afterL <= 0)
			die = true;
	}
	d.afterW = d.w;
	d.die = die;
}


int main() {
	struct Desi D1, D2;
	cin >> D1.w >> D1.l0 >> D1.T >> D1.D >> D1.l >> D1.A;
	D2 = D1;

	calWeight(D1, false);
	calWeight(D2, true);

	if (D1.die) cout << "Danger Diet\n";
	else cout << D1.afterW << " " << D1.l0 << "\n";

	if (D2.die)
		cout << "Danger Diet";
	else
	{
		cout << D2.afterW << " " << D2.afterL;
		if ((D2.l0 - (D2.afterL)) > 0)
			cout << " YOYO";
		else
			cout << " NO";
	}
}
