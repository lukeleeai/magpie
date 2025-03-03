#include"stdc++.h"

#define me(a,x) memset(a,x,sizeof(a))

#define sc scanf

#define itn int

using namespace std;

const int N=1e6;

const long long mod=1e9+7;

const int oo=0x7fffffff;

const int sup=0x80000000;

typedef long long ll;

typedef unsigned long long ull;

template <typename it>void db(it *begin,it *end){while(begin!=end)cout<<(*begin++)<<" ";puts("");}

template <typename it>

string to_str(it n){string s="";while(n)s+=n%10+'0',n/=10;reverse(s.begin(),s.end());return s;}

template <typename it>int o(it a){cout<<a<<endl;return 0;}

ll mul(ll a,ll b,ll c){ll ans=0;for(;b;b>>=1,a=(a+a)%c)if(b&1)ans=(ans+a)%c;return ans;}

ll ksm(ll a,ll b,ll c){ll ans=1;for(;b;b>>=1,a=mul(a,a,c))if(b&1)ans=mul(ans,a,c);return ans;}

int n;

int a[N],b[N]={0};

int main(){

	//freopen("in.txt","r",stdin);

	cin>>n;

	for(int i=1;i<=n;i++)cin>>a[i];

  for (int i = n; i >= 1; --i) {

    b[i] = a[i];

    for (int j = i * 2; j <= n; j += i)

      b[i] ^= b[j];

  }

  int cnt = 0;

  for (int i = 1; i <= n; ++i) if (b[i] == 1) cnt++;

  printf("%d\n", cnt);

  for (int i = 1; i <= n; ++i)

    if (b[i] == 1) printf("%d ", i);

}