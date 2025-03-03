#include <iostream>

#include <algorithm>

#include <stdio.h>

#include <vector>



using namespace std;



#define LL long long

#define FOR(i,l,r) for(int i = l; i <= r; ++i)

#define REP(i,l,r) for(int i = l; i < r; ++i)

#define pi pair<int,int>

#define mp make_pair



const int maxN = 1e5 + 11;

const LL oo = 1e17 + 11;

const int msk = 1 << 12;



int N,M;

int A[maxN];

vector <int> e[maxN];

LL F[1001][msk];



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie();

    cout.tie();

    //

    cin >> N >> M;

    FOR(i,1,M){

        int d,x;

        cin >> A[i] >> d;

        FOR(j,1,d){

            cin >> x;

            e[i].push_back(x);

        }

    }



    int woosh = 1 << N;

    FOR(i,0,M) REP(j,0,woosh) F[i][j] = oo;

    F[0][0] = 0;

    //

    REP(i,0,M) REP(j,0,woosh) if(F[i][j] < oo){

        F[i + 1][j] = min(F[i + 1][j],F[i][j]); // không chọn i + 1

        int newMask = j;

        REP(k,0,e[i + 1].size()){

            int z = e[i + 1][k];

            newMask |= (1 << (z - 1));

        }

        F[i + 1][newMask] = min(F[i + 1][newMask],F[i][j] + A[i + 1]);

    }

    

    if(F[M][woosh - 1] >= oo) cout << -1;

    else cout << F[M][woosh - 1];



    return 0;

}