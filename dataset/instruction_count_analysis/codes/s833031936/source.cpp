#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

using namespace std;

typedef long long LL;

 

LL pos[2][100005];

 

void solve(LL id,LL num){

	LL sgn = 1,tmp = num;

	if(num < 0) sgn = -1,tmp = -num;

	for(LL i = 0;i <= 19;i ++){

		pos[id][i] = tmp % 3;

		tmp /= 3;

	}

	for(LL i = 0;i <= 19;i ++){

		if(pos[id][i] == 2 || pos[id][i] == -2){

			pos[id][i + 1] += pos[id][i] / 2;

			pos[id][i] = - pos[id][i] / 2;

		}

		else if(pos[id][i] == 3 || pos[id][i] == -3){

			pos[id][i + 1] += pos[id][i] / 3;

			pos[id][i] = 0;

		}

	}

	for(LL i = 0;i <= 19;i ++) pos[id][i] *= sgn;

}

 

char ch[45];

LL x[100005],y[100005],exs[2] = {0};

 

LL pwr(LL x,LL y){

	LL ret = 1;

	while(y --) ret *= x; return ret;

}

 

int main(){

	LL n;

	cin >> n;

	for(LL i = 1;i <= n;i ++){

		cin >> x[i] >> y[i];

		exs[(x[i] + y[i]) & 1] = 1;

	}

	if(exs[0] && exs[1]){ cout << -1 << endl; return 0; }

	if(exs[0]){

		cout << 40 << endl;

		for(LL i = 0;i <= 19;i ++) cout << pwr(3LL,i) << ' ' << pwr(3LL,i) << (i == 19 ? '\n' : ' ');

	}

	if(exs[1]){

		cout << 39 << endl;

		for(LL i = 0;i <= 18;i ++) cout << pwr(3LL,i) << ' ' << pwr(3LL,i) << ' ';

		cout << pwr(3LL,19) << endl;

	}

	

	for(LL i = 1;i <= n;i ++){

		solve(0,x[i]); solve(1,y[i]);

//		for(LL j = 0;j <= 19;j ++) cout << pos[1][j] << (j == 19 ? '\n' : ' ');

		for(LL j = 0;j <= 18;j ++){

			if(pos[0][j] == -2){ pos[0][j] = 1; pos[0][j + 1] --; }

			if(pos[1][j] == -2){ pos[1][j] = 1; pos[1][j + 1] --; }

			if(pos[0][j] == 2){ pos[0][j] = -1; pos[0][j + 1] ++; }

			if(pos[1][j] == 2){ pos[1][j] = -1; pos[1][j + 1] ++; }

			

			if(pos[0][j] && pos[1][j]){

				ch[j << 1] = (pos[0][j] == 1 ? 'R' : 'L');

				ch[(j << 1) + 1] = (pos[1][j] == 1 ? 'U' : 'D');

			}

			if(!pos[0][j] && !pos[1][j]){ ch[j << 1] = 'L'; ch[(j << 1) + 1] = 'R'; }

			if(pos[0][j] && !pos[1][j]){

				if(pos[0][j] == 1){ pos[0][j] = -2; pos[0][j + 1] ++; ch[j << 1] = ch[(j << 1) + 1] = 'L'; }

				if(pos[0][j] == -1){ pos[0][j] = 2; pos[0][j + 1] --; ch[j << 1] = ch[(j << 1) + 1] = 'R';  }

			}

			if(!pos[0][j] && pos[1][j]){

				if(pos[1][j] == 1){ pos[1][j] = -2; pos[1][j + 1] ++; ch[j << 1] = ch[(j << 1) + 1] = 'D'; }

				if(pos[1][j] == -1){ pos[1][j] = 2; pos[1][j + 1] --; ch[j << 1] = ch[(j << 1) + 1] = 'U';  }

			}

//			cout << pos[1][j] << ' ';

		}

//		cout << pos[1][19] << endl;

		if(pos[0][19] && !pos[1][19]) ch[38] = (pos[0][19] == 1 ? 'R' : 'L');

		if(!pos[0][19] && pos[1][19]) ch[38] = (pos[1][19] == 1 ? 'U' : 'D');

		if(!pos[0][19] && !pos[1][19]) ch[38] = 'R',ch[39] = 'L';

		if(pos[0][19] && pos[1][19]) ch[38] = (pos[0][19] == 1 ? 'R' : 'L'),ch[39] = (pos[1][19] == 1 ? 'U' : 'D');;

		cout << ch << endl;

	}

	return 0;

}