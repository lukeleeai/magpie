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

using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

long long int INF = 1e18;

double Pi = 3.141592653589;

const int mod = 1000000007;

vector<int> G[100005];

std::vector<P> tree[100010];

int dx[8]={1,0,-1,0,1,1,-1,-1};

int dy[8]={0,1,0,-1,1,-1,-1,1};

#define p(x) cout<<x<<endl;

#define e cout<<endl;

#define pe(x) cout<<x<<" ";

#define re(i,a,b) for(i=a;i<=b;i++)

ll i,j,k,l,ii,jj;

ll n,m;

string s,a[55555];

ll h,w,x,y,ans=0,sum;

ll ite;

int main(){

	cin>>s;

	cin>>ii;

	n=s.length();

	for(i=1;i<=5;i++){

		for(k=0;k+i<=n;k++){

			a[l]=s.substr(k,i);

			l++;

		}

	}

	sort(a,a+l);

	unique(a,a+l);

	p(a[ii-1]);

	system ("pause");

	return 0;

}