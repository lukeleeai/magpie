#include "stdc++.h"

#define REP(i, n) for(int i=0; i<(int)(n); i++)

#define REP1(i,a,b) for(int i=a; i<=(int)(b); i++)

#define ALL(x) begin(x),end(x)

#define PB push_back

using namespace std;

typedef int64_t LL;

typedef vector<int> VI;

typedef pair<int,int> PII;



template<class T> inline bool chmax( T &a, const T &b ) { return b>a ? a=b,true : false; }

template<class T> inline bool chmin( T &a, const T &b ) { return b<a ? a=b,true : false; }

template<class T> using MaxHeap = priority_queue<T>;

template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {

    sort(begin(v),end(v),f);

    v.resize(unique(begin(v),end(v))-begin(v));

}



const int N=51,MOD=1e9+7;

LL dp[N][N][N*N]; // dp(i,j,k): i之前,保留j個,分數為k



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    int n,K;

    cin >> n >> K;

    dp[0][0][0]=1;

    REP(i,n) REP1(j,0,i) REP1(k,0,K) {

        // i-i

        dp[i+1][j][k+j*2]+=dp[i][j][k]; dp[i+1][j][k+j*2]%=MOD;

        // i-x i-x

        dp[i+1][j+1][k+(j+1)*2]+=dp[i][j][k]; dp[i+1][j+1][k+(j+1)*2]%=MOD;

        // i-j i-x

        dp[i+1][j][k+j*2]+=dp[i][j][k]*j*2; dp[i+1][j][k+j*2]%=MOD;

        // i-j i-j

        if ( j ) {

            dp[i+1][j-1][k+(j-1)*2]+=dp[i][j][k]*j*j; dp[i+1][j-1][k+(j-1)*2]%=MOD;

        }

    }



    cout << dp[n][0][K] << '\n';

    return 0;

}
