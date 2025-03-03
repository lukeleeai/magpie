#include <stdio.h>

#include <string>

#include <cstring>

#include <stdlib.h>

#include <math.h>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <iterator>

#pragma warning(disable:4996)

 

typedef long long ll;

#define MIN(a, b) ((a)>(b)? (b): (a))

#define MAX(a, b) ((a)<(b)? (b): (a))

#define LINF 9223300000000000000

#define INF 2140000000

#define MOD 1000000007

using namespace std;



// 方針1

//   ある値vを固定したときに、a xor b=u, a+b=u となるようなuの数を求めるには

//   vを2進数表記したときに 11100001111000110000 となったとき 1110000, 1111000, 110000 というように

//   「1が並んで0が並ぶ」というかたまりで分けて考えればよい。

//   それぞれのグループで分けて数えて積をとればよいかと思ったら、そうではなくて

//   下位グループから上位グループに繰り上がるケースがある。

//   そこで、下位グループから順に、繰り上がりがあるケースと、繰り上がりがないケースそれぞれを数えて

//   上位グループにその結果を反映させればよい。

// 方針2

//   nが与えられて、それより小さい数を列挙するときには、

//   nを2進数表記して、任意の1のbitを0に変えてそれより下は自由に選択可能になる。

//   今回はn以下という問題だったので、最初に1を足しておいて、その方針を使う。



ll dp[62][2];         // dp[i][0] = 2進数でi桁で最上位は1というvに対しての(a,b)の選び方の合計 (ただし和が上位に繰り上がらない）

                      // dp[i][1] = 2進数でi桁で最上位は1というvに対しての(a,b)の選び方の合計 (ただし和が上位に繰り上がる）



ll calc( const vector<pair<long, long> >& zz, long jj )

{

    ll val[2]= {dp[jj][0], dp[jj][1]};



    long p;

    for(p=(long)zz.size()-1; p>=0; p--) {

        ll valnew[2] = {0, 0};

        long j = zz[p].first;

        long k = zz[p].second;

        valnew[0] = (valnew[0] + (j*k+1)*val[0]) %MOD;

        valnew[0] = (valnew[0] +    j   *val[1]) %MOD;

        valnew[1] = (valnew[1] +    k   *val[0]) %MOD;

        valnew[1] = (valnew[1] +    1   *val[1]) %MOD;



        val[0] = valnew[0];

        val[1] = valnew[1];

    }



    return val[0];

}





int main(int argc, char* argv[])

{

    ll n;

    scanf("%lld", &n);

    n ++;    // nより小さい数だけを考えればよい形にするため



    long i,j,k;



    dp[0][0]=1;

    dp[0][1]=0;

    for(i=1; i<60; i++) {

        for(j=1; j<=i; j++) {   // 1をj桁並べる

            if(j==i) {     // 1をi=j桁並べておわる場合

                dp[i][0] = (dp[i][0] + 1) %MOD;

            }

            else {

                for(k=1; k<=i-j; k++) {  // 1をj桁並べた後、0をk桁並べる場合

                    dp[i][0] = (dp[i][0] + (j*k+1)*dp[i-j-k][0]) %MOD;

                    dp[i][0] = (dp[i][0] +    j   *dp[i-j-k][1]) %MOD;

                    dp[i][1] = (dp[i][1] +    k   *dp[i-j-k][0]) %MOD;

                    dp[i][1] = (dp[i][1] +    1   *dp[i-j-k][1]) %MOD;

                }

            }

        }

    }



    vector<pair<long, long> > zz;   // (1を並べる個数, 0を並べる個数）を保存

    long count1=0, count0=0;        // 現在の1が並んだ個数, 0が並んだ個数  （zzに保存したら0に戻す）



    ll ans=0;

    for(i=60; i>=0; i--) {

        if(n & ((ll)1<<i)) {   // 桁iが1のとき

            for(j=i; j>=0; j--) {    // 桁iの1を0に変えて、桁jまで0を続ける（i-j+1個）

                vector<pair<long, long> > zz_tmp = zz;

                if(count1) {

                    zz_tmp.push_back(make_pair(count1, count0+(i-j+1)));

                }

                ans = (ans + calc(zz_tmp, j)) %MOD;

            }

            

            if(count1 && count0) {

                zz.push_back( make_pair(count1, count0) );

                count1=1;

                count0=0;

            }

            else {

                count1++;

            }

        }

        else {    // 桁iが0のとき

            if(count1) {

                count0++;

            }

        }

    }

    printf("%lld\n", ans);



    return 0;

}


