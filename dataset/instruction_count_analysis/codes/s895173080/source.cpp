#include"stdc++.h"

using namespace std;

 

#define f first

#define s second

#define pb push_back

#define ll long long

#define MAX 200005  

#define mp make_pair

const int M=1e9+7;

const int mod=998244353;

typedef double ld;

bool visited[MAX];

ll qpow(ll x, ll k,ll m) {return k==0? 1: 1ll*qpow(1ll*x*x%m,k>>1,m)*(k&1?x:1)%m;}

ll modinv(ll a,ll m){ll g=__gcd(a,m);return (g==1)? qpow(a,m-2,m):-1;}



string lcs(string a,string b)

{

    int n=a.size(),m=b.size();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)

    {

        for(int j=0;j<=m;j++)

        {

            if(i==0 || j==0)

                dp[i][j]=0;

            else if(a[i-1]==b[j-1])

                dp[i][j]=dp[i-1][j-1]+1;

            else

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }

    }

    string ans="";

    int i=n,j=m;

    while(i>0 && j>0)

    {

        if(a[i-1]==b[j-1])

        {

            ans+=a[i-1];

            i--,j--;

        }

        else 

        {

            if(dp[i][j-1]>dp[i-1][j])

                j--;

            else

                i--;

        }

    }

    reverse(ans.begin(),ans.end());

    return ans;

}



int main()

{

    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    string a,b;

    cin>>a>>b;

    //int n=s.length();

    cout<<lcs(a,b)<<endl;

    return 0;

}






