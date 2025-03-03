//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define Would

#define you

#define please



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



//今日のコンテストはまたゴミクズだったなぁ



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();



	int kotae = 0;

	int kari = 0;

	int mae = 0;

	rep(i, N) {

		int h = getint();

		if (mae >= h) kari++;

		else kari = 0;



		kotae = max(kotae, kari);

		mae = h;

	}



	printf("%d", kotae);



	Would you please return 0;

}