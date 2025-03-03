#include <iostream>

#include <climits>

#include <stack>

#include <queue>

#include <string>

#include <set>

#include <map>

#include <math.h>

#include <algorithm>

#include <vector>

#include <string.h>

#include <random>

#include <iomanip>

#include <limits>

 

using namespace std;

 

typedef long long ll;

 

typedef pair<ll,ll> P;

long long int INF = 1e18;

double Pi = 3.141592653589;

const int mod = 1000000007;

// memset(a,0,sizeof(a)); →全部０にする

 

vector<int> G[100005];

std::vector<P> tree[100010];

 

int dx[8]={1,0,-1,0,1,1,-1,-1};

int dy[8]={0,1,0,-1,1,-1,-1,1};

 

#define p(x) cout<<x<<endl;

#define el cout<<endl;

#define pe(x) cout<<x<<" ";

#define re(i,a,b) for(i=a;i<=b;i++)

 

ll i,j,k,l,ii,jj;

ll n,m,a,b,c,d,ans=INF,num,ddx,ddy;

ll x[100005],y[100005];

char s[300004];







ll de(ll x){

	ll num=0;

	while(true){

		num += x%10;

		x = x/10;

		if(x==0)break;

	}

	return num;

}





int main(){

	cin>>n;

	for(i=1;i<n;i++){

		ans = min(ans,de(i)+de(n-i));

	}

	p(ans);

	return 0;

}