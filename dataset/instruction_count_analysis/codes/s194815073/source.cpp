#include <iostream>

#include <string.h>

#include <stdio.h>

#include <map>

#include <vector>

#include <math.h>

using namespace std;



#define rep(i,a) for(int i=0; i<a; i++)

#define rrep(i,a) for(int i=a; i>=0; i--)

#define loop3(i,j,k,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)

#define loop4(i,j,k,l,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)for(int l=0; l<a; l++)if(i!=l&&j!=l&&k!=l)

#define rep1(i,a) for(int i=1; i<=a; i++)



#define scnd1(a) scanf("%d", &a)

#define scnd2(a,b) scanf("%d%d", &a,&b)

#define scnd3(a,b,c) scanf("%d%d%d", &a,&b,&c)

#define scnd4(a,b,c,d) scanf("%d%d%d%d", &a,&b,&c,&d)



#define prtd1(a) printf("%d\n", a)

#define prtd2(a,b) printf("%d %d\n", a,b)

#define prtd3(a,b,c) printf("%d %d %d\n", a,b,c)

#define prtd4(a,b,c,d) printf("%d %d %d %d\n", a,b,c,d)



#define mem(a,n) memset( a, n, sizeof(a))



typedef long long ll;

ll N, C, dist[100009], cal[100009], turnL[100009][2], turnR[100009][2];



int main() {

    

    cin >> N >> C;

    

    mem( turnL, 0); mem( turnR, 0);

    

    rep( i, N) cin >> dist[i] >> cal[i];

    

    // 時計回りした時の寿司iまでの差し引きカロリーの最高値計算

    ll sumcal = 0;

    rep( i, N) {

        sumcal += cal[i];

        if(i==0 && cal[i] - dist[i] > 0 ) {

            turnR[i][0] = sumcal - dist[i];

            turnR[i][1] = dist[i];

        } else {

            if ( sumcal - dist[i] <= turnR[i-1][0] ) {

                turnR[i][0] = turnR[i-1][0];

                turnR[i][1] = turnR[i-1][1];

            } else {

                turnR[i][0] = sumcal - dist[i];

                turnR[i][1] = dist[i];

            }

        }

    }

    

    // 反時計時計回りした時の寿司iまでの差し引きカロリーの最高値計算

    sumcal = 0;

    rrep( i, N-1) {

        sumcal += cal[i];

        if(i==N-1) {

            if ( cal[i] - (C-dist[i]) > 0 ) {

                turnL[i][0] = sumcal - (C-dist[i]);

                turnL[i][1] = (C-dist[i]);

            }

        } else {

            if ( sumcal - (C-dist[i]) <= turnL[i+1][0] ) {

                turnL[i][0] = turnL[i+1][0];

                turnL[i][1] = turnL[i+1][1];

            } else {

                turnL[i][0] = sumcal - (C-dist[i]);

                turnL[i][1] = (C-dist[i]);

            }

        }

    }

    

    ll maxcal = max( turnR[N-1][0], turnL[0][0]);

    

    // 反時計回りにBまで行き折り返してAまで行く場合の差し引きカロリーの最大値を全探索

    for ( int i = 1; i < N; i++ ) {

        maxcal = max( maxcal, turnL[i+1][0] - turnL[i+1][1] + turnR[i][0] );

    }

    

    // 時計回りにAまで行き折り返してBまで行く場合の差し引きカロリーの最大値を全探索

    for ( int i = 1; i < N; i++ ) {

        maxcal = max( maxcal, turnR[i-1][0] - turnR[i-1][1] + turnL[i][0] );

    }

    

    cout << maxcal << endl;

}