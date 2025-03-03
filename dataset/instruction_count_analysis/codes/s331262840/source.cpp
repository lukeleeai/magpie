#include <iostream>

#include <cstdio>

#include <iomanip>

#include <string>

#include <cmath>

#include <algorithm>

#include <iomanip>

#include <cstring>

#include <queue>

#include <stack>

#include <vector>

#include <map>

#include <set>

using namespace std;

typedef long long ll;

inline ll read() {

	ll kk=0,f=1;

	char cc=getchar();

	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}

	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}

	return kk*f;

}

inline void write(ll xx){

	if(xx < 0){putchar('-');xx=-xx;}

	if(xx > 9)write(xx/10);

	putchar(xx%10+'0');

	return;

}

ll n,a[3];

char s[100005][5];

vector<char> res;

int flag;

int cnt;

int main(){

	n = read();

	a[0] = read();

	a[1] = read();

	a[2] = read();

	for(int i = 1;i <= n;i++){

		scanf("%s",s[i]);

	}

	for(int i = 1;i <= n;i++){

		if(a[s[i][0] - 'A'] < a[s[i][1] - 'A']){

			a[s[i][0] - 'A']++;

			a[s[i][1] - 'A']--;

			res.push_back(s[i][0]);

		}else if(a[s[i][0] - 'A'] > a[s[i][1] - 'A']){

			a[s[i][0] - 'A']--;

			a[s[i][1] - 'A']++;

			res.push_back(s[i][1]);

		}else{

			if(s[i + 1][0] == s[i][0] || s[i + 1][1] == s[i][0]){

				a[s[i][0] - 'A']++;

				a[s[i][1] - 'A']--;

				res.push_back(s[i][0]);

			}else{

				a[s[i][0] - 'A']--;

				a[s[i][1] - 'A']++;

				res.push_back(s[i][1]);

			}

		}

		if(a[0] < 0 || a[1] < 0 || a[2] < 0){

			flag = 1;

			break;

		}

	}

	if(!flag){

		printf("Yes\n");

		for(int i = 0;i < res.size();i++){

			printf("%c\n",res[i]);

		}

	}else{

		printf("No\n");

	}

	return 0;

}