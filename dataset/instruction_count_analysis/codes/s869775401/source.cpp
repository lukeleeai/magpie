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

ll c=0;

char s[200005];

bool flag=false;



int main(){

	cin>>s;

	n=strlen(s);

	for(i-0;i<n;i++){

		if(s[i]=='S'){

			c++;

		}else{

			if(c>0)ans++;

			c=max(0ll,c-1);

		}

	}

	cout<<n-2*ans<<endl;

	return 0;

}