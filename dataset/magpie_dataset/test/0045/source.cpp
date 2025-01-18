#include"stdc++.h"

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)

#define per(i,a,n) for(int i=n;i>=a;i--)

#define pb push_back

#define SZ(x) ((int)(x).size())

typedef long long ll;

typedef pair<int,int> pii;

typedef double db;

ll n,ans,r,g,b;

char s[4010];

int main(){

	cin>>n;

	scanf("%s",s+1);

	rep(i,1,n){

		if(s[i]=='R')	r++;

		if(s[i]=='G')	g++;

		if(s[i]=='B')	b++;

	}

	ans=r*g*b;

	rep(len,1,n){

		rep(j,1,n-2*len){

			if(s[j]!=s[j+len]&&s[j]!=s[j+2*len]&&s[j+len]!=s[j+2*len])

				ans--;	

		}

	}

	printf("%lld\n",ans);

	return 0;

}
