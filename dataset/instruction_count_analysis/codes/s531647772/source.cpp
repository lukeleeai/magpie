#include"stdc++.h"



using namespace std;



#define fi first

#define se second

#define pb push_back

#define mp make_pair



typedef pair<int,int> ii;



long long n,k,mod,c[305][305],f[305][305],g[305][305],h[305][305];



int main(){

    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);

    cin >> n >> k >> mod;

    c[0][0] = 1;

    for(int i = 1;i<=300;i++){

        c[i][0] = 1;

        for(int j = 1;j<=i;j++){

            c[i][j] = c[i-1][j-1] + c[i-1][j];

            c[i][j]%=mod;

        }

    }

    for(int i = 0;i<=302;i++)

        h[0][i] = 1;

    for(int i = 1;i<=n;i++){

        for(int j = k;j>=0;j--){

            f[i][j] = h[i-1][j+1]%mod;

            g[i][j] = g[i][j+1]+f[i][j];

            g[i][j]%=mod;

        }

        for(int j = 0;j<=k;j++){

            for(int l =1;l<=i;l++){

                h[i][j] += ((h[i-l][j]*g[l][j]%mod)*c[i-1][l-1])%mod;

                h[i][j]%=mod;

            }

        }

    }

    cout<<h[n][1]%mod;

}
