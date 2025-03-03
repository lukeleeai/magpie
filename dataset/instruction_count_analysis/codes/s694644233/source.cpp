#include "stdc++.h"

using namespace std;

const int N=1e5+10;

string s[N];

int p[5],ans[N];

int n;

void solve(int i,int x,int y) {

	int x0,y0;

	if (p[x]>p[y]) {

		ans[i]=y; p[x]--; p[y]++;

	}

	else if (p[x]<p[y]) {

		ans[i]=x; p[x]++; p[y]--;

	}

	else if (p[x]>1) {

		ans[i]=x; p[x]++; p[y]--;

	}

	else if (p[x]==0) {

		cout<<"No"<<endl;

		exit(0);

	}

	else {

		if (i==n) {

			ans[i]=x; p[x]++; p[y]--; return;

		}

		x0=s[i+1][0]-'A'; y0=s[i+1][1]-'A';

		if (x0==x&&y0==y) {

			ans[i]=x; p[x]++; p[y]--; return;

		} 

		if (x==x0||x==y0) {

			ans[i]=x; p[x]++; p[y]--; return;

		}

		else {

			ans[i]=y; p[x]--; p[y]++; return;

		}

	}

}

int main() {

	int i;

	ios::sync_with_stdio(false);

	cin>>n>>p[0]>>p[1]>>p[2];

	for (i=1;i<=n;i++) 

		cin>>s[i];

	for (i=1;i<=n;i++) {

		if (s[i]=="AB") solve(i,0,1);

		else if (s[i]=="BC") solve(i,1,2);

		else solve(i,0,2); 

	}

	cout<<"Yes"<<endl;

	for (i=1;i<=n;i++)

		cout<<char(ans[i]+'A')<<endl;

	return 0;

}