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

#include <list>

#include <iterator>

#include <assert.h>

#pragma warning(disable:4996) 

 

typedef long long ll;

#define MIN(a, b) ((a)>(b)? (b): (a))

#define MAX(a, b) ((a)<(b)? (b): (a))

#define LINF 9223300000000000000

#define INF 2140000000

const long long MOD = 1000000007;

using namespace std;



char str[2000][2001];

int val[2000][2001];



int main(int argc, char* argv[])

{

    int h,w;

    scanf("%d%d", &h, &w);

    int i,j;

    for(i=0; i<h; i++) {

        scanf("%s", str[i]);

    }

    for(i=0; i<h; i++) {

        for(j=0; j<w; j++) {

            int cnt=0;

            int k=j;

            while(k<w) {

                if(str[i][k]=='.') {

                    k++;

                    cnt++;

                }

                else {

                    break;

                }

            }

            k--;

            int p;

            for(p=j; p<=k; p++) {

                val[i][p]+=cnt;

            }

            j=MAX(j,k);

        }

    }



    for(i=0; i<w; i++) {

        for(j=0; j<h; j++) {

            int cnt=0;

            int k=j;

            while(k<h) {

                if(str[k][i]=='.') {

                    k++;

                    cnt++;

                }

                else {

                    break;

                }

            }

            k--;

            int p;

            for(p=j; p<=k; p++) {

                val[p][i]+=cnt;

            }

            j=MAX(j,k);

        }

    }



    int ans=0;

    for(i=0; i<h; i++) {

        for(j=0; j<w; j++) {

            if(str[i][j]=='.') val[i][j]--;



            ans=MAX(ans,val[i][j]);

        }

    }

    printf("%d\n", ans);



    return 0;

}
