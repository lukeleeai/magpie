#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)

#pragma GCC optimize(2)

#include<iostream>

#include<algorithm>

#define l first

#define r second

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

const int N=200010;

const ll mod=998244353;

int n,k;

ll f[N],s[N];

pii a[N];

int main()

{

    IO;

    int T=1;

    //cin>>T;

    while(T--)

    {

        cin>>n>>k;

        for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;

        f[1]=1;

        s[1]=1;

        for(int i=2;i<=n;i++)

        {

            for(int j=1;j<=k;j++)

                f[i]=(f[i]+s[max(0,i-a[j].l)]-s[max(0,i-a[j].r-1)])%mod;;

            s[i]=(s[i-1]+f[i])%mod;

        }    

        cout<<(f[n]+mod)%mod<<'\n';

    }

    return 0;

}