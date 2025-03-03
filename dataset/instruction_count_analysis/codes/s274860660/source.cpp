

#include <iostream>

#include <climits>

#include <bitset>

#include <stack>

#include <queue>

#include <iomanip>

#include <limits>

#include <string>

#include <cmath>

#include <set>

#include <map>

#include <math.h>

#include <algorithm>

#include <vector>

#include <string.h>

#include <complex>



using namespace std;

typedef long long ll;





typedef complex<double> xy_t;

double dot_product(xy_t a, xy_t b) { return (conj(a)*b).real(); }

double cross_product(xy_t a, xy_t b) { return (conj(a)*b).imag(); }



typedef pair<ll,ll> P;

long long int INF = 1e18;

double Pi = 3.141592653589;

const int mod = 1000000007;

// memset(a,0,sizeof(a)); →全部０にする



vector<int> G[100005];

std::vector<P> tree[100010];



int dx[9]={1,0,-1,0,1,1,-1,-1,0};

int dy[9]={0,1,0,-1,1,-1,-1,1,0};



#define p(x) cout<<x<<endl;

#define el cout<<endl;

#define pe(x) cout<<x<<" ";

#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;

#define re(i,a,b) for(i=a;i<=b;i++)

#define pb push_back

#define lb lower_bound

#define ub upper_bound



ll i,j,k,ii,jj;

ll n,m,sum,num;

ll ans=0;

ll a,b,c,d,e,h,w;



ll x[500005],y[500005],z[500005];

char s[100005],t[100005];

bool ok=false;

bool check[100005];



int main(){

    cin>>n;

    for(i=0;i<n;i++)cin>>x[i];

    for(i=0;i<n-1;i++){

        if(x[i]==x[i+1]){

            ans++;

            i++;

        }

    }

    p(ans);

    return 0;

}
