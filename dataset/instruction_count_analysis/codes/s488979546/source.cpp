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

#define LINF 9223372036854775807

#define INF 2147483647

#define MOD 1000000007

using namespace std;



long n,m;

vector<vector<long> > z;

long vis[10];

long cnt;

ll   ans;



void dfs( long curr )

{

    if(cnt==n) {

        ans++;

        return;

    }



    long i;

    for(i=0; i<(long)z[curr].size(); i++) {

        if(!vis[z[curr][i]]) {

            vis[z[curr][i]]=1;

            cnt++;

            dfs( z[curr][i] );

            vis[z[curr][i]]=0;

            cnt--;

        }

    }

    return;

}



int main(int argc, char* argv[])

{

    scanf("%ld%ld", &n, &m);



    z.resize(n);

    long i;

    for(i=0; i<m; i++) {

        long a, b;

        scanf("%ld%ld", &a, &b);

        z[a-1].push_back(b-1);

        z[b-1].push_back(a-1);

    }



    ans=0;

    vis[0]=1;

    cnt = 1;

    dfs( 0 );



    printf("%lld\n", ans);



    return 0;

}
