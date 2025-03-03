#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<vector>

#include<cmath>

#include<algorithm>

#include<iomanip>

#include<cctype>

#include<queue>

#include<map>

#include<stack>

#include<string>

#include<cstring>

#include<set>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef pair<int,int> pii;

typedef vector<pii> vpi;

#define mp make_pair

#define pb push_back



int a[200200],n,s[200200];

int k;

map<int,int> m;

vi b[200200];



int main(){

	scanf("%d%d",&n,&k);

	s[0]=0;

	int cnt=1;

	m.clear();

	m[0]=1;

	b[1].pb(0);

	for (int i=1;i<=n;i++){

		scanf("%d",&a[i]);

		a[i]--;

		a[i]%=k;

		s[i]=(s[i-1]+a[i])%k;

		if (m.find(s[i])==m.end()) m[s[i]]=++cnt;

		b[m[s[i]]].pb(i);

	}

	ll ans=0;

	for (map<int,int>::iterator it=m.begin();it!=m.end();it++){

		int p=it->second;

		int sz=b[p].size();

		if (sz==1) continue;

		int i=0,j=1;

		while (j<sz){

			if (b[p][j]-b[p][i]>=k) i++;

			else{

				ans+=(ll)j-i;

				j++;

			}

		}

	}

	printf("%lld\n",ans);

	return 0;

}