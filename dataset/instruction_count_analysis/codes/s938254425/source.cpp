#include <iostream>

#include <climits>

#include <stack>

#include <queue>

#include <string>

#include <random>

#include <utility>

#include <cmath>

#include <set>

#include <map>

#include <math.h>

#include <string.h>

#include <iomanip>

#include <stdlib.h>

#include <algorithm>

#include <vector>

 

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

 

ll i,j,k;

ll n,m;

ll a[100005],b[100005];

ll ans=0;



int main(){

	cin>>n>>m;

	if(n*m>0){

		if(m>n)ans=m-n;

		else ans=n-m+2;

	}else if(n*m<0){

		ans=abs(abs(m)-abs(n))+1;

	}else{

		if(n==0 && m>0)ans=m;

		else if(n==0 && m<0)ans=1-m;

		else if(m==0 && n>0)ans=1+n;

		else ans=-1*n;

	}

	cout<<ans<<endl;

	return 0;

}