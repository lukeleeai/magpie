#include "stdc++.h"

using namespace std;

//#define MOD 1000000007

#define MOD 998244353

#define INF 1145141919810893364

//#define INF 810114514

#define PI 3.141592653589

typedef long long ll;

typedef pair<ll,ll> PP;

#define int ll

#define setdouble setprecision

#define REP(i,n) for(int i=0;i<(n);++i)

#define OREP(i,n) for(int i=1;i<=(n);++i)

#define RREP(i,n) for(int i=(n)-1;i>=0;--i)

#define GOODBYE do { cout << "0" << endl; return 0; } while (false)

#define MM <<" "<<

#define Endl endl

#define debug false

#define debug2 false









signed main(void){

    int N,M,a;

    vector<int> A,B;

    cin >> N >> M;

    REP(i,M){

        cin >> a;a--;

        A.push_back(a);

        cin >> a;a--;

        B.push_back(a);

    }

    

    vector<int> G[214514];

    REP(i,M){

        G[A[i]].push_back(B[i]);

        G[B[i]].push_back(A[i]);

    }

    

    vector<int> Ans(N,-1);

    queue<int> Q;

    Ans[0]=0;

    Q.push(0);

    

    while(!Q.empty()){

        int q = Q.front();

        Q.pop();

        REP(i,G[q].size()){

            if(Ans[G[q][i]]==-1){

                Q.push(G[q][i]);

                Ans[G[q][i]]=q;

            }

        }

    }

    

    REP(i,N){

        if(i==0)continue;

        if(Ans[i]==-1){

            cout << "No" << endl;

            return 0;

        }

    }

    cout << "Yes" << endl;

    REP(i,N){

        if(i==0)continue;

        cout << Ans[i]+1 << endl;

    }

    

    return 0;

}




