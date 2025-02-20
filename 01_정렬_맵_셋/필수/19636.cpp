#include <iostream>

using namespace std;

struct Desi {
	int w, l0, T, D, l, A;
	int afterW, afterL;
	bool die;
};


void calWeight1(struct Desi& d) {
	double change = 0;
	bool die = false;
	for (int i = 1; i <= d.D; i++) {
		change = d.l - (d.l0 + d.A);
		d.w += change;
		if (d.w <= 0 || d.l0 <= 0)
			die = true;
	}
	d.afterW = d.w;
	d.die = die;
}

void calWeight2(struct Desi& d) {
	double change, j = 0;//j´Â Àý´ñ°ª ±¸ÇÏ·Á°í µÒ
	bool die = false;
	d.afterL = d.l0;
	for (int i = 1; i <= d.D; i++) {
		change = d.l - (d.afterL + d.A);
		d.w += change;
		if (change < 0)
			j = change * (-1);
		if (j > d.T) {
			d.afterL += change / 2;
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

	calWeight1(D1);
	calWeight2(D2);

	if(D1.die) cout<< "Danger Diet";
	else cout << D1.afterW << " " << D1.l0<<"\n";

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
