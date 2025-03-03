#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<int, int> pii;

typedef pair<int, pii> pipii;

typedef pair<pii, int> piipi;

typedef pair<pii, pii> piipii;



#define mp make_pair

#define fi first

#define se second

#define all(a) (a).begin(), (a).end()

#define sz(a) (int)(a).size()

#define eb emplace_back

const int mod = 1000000007;



int l[3005], r[3005], mx[3005];

char s[3005];

int sum[3005][2];

int dp[3005][3005];

int main(){

    int n, m;

    scanf("%d%d", &n, &m);   

    scanf("%s", s+1);

    for(int i=1;i<=n;i++) mx[i] = i;

    for(int i=1;i<=m;i++){

        scanf("%d%d", &l[i], &r[i]);

        mx[l[i]] = max(mx[l[i]], r[i]);

    }



    for(int i=1;i<=n;i++){

        sum[i][s[i]-'0']++;

        sum[i][0] += sum[i-1][0];

        sum[i][1] += sum[i-1][1];

    }



    for(int i=1;i<=n;i++) mx[i] = max(mx[i], mx[i-1]);



    dp[0][0] = 1;

    for(int i=1;i<=n;i++){

        for(int j=0;j<=n;j++){

            if(dp[i-1][j]){

                int c0 = sum[mx[i]][0] - j;

                int c1 = sum[mx[i]][1] - (i-1-j);

                if(c0 > 0) dp[i][j+1] = (dp[i][j+1] + dp[i-1][j])%mod;

                if(c1 > 0) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;

            }

        }

    }

    int ans = 0;

    for(int j=0;j<=n;j++) ans = (ans + dp[n][j])%mod;

    printf("%d\n", ans);

}