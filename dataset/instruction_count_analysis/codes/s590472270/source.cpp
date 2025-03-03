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



char str[2005][2005];

vector<int> a[2005];

vector<int> b[2005];



int main(int argc, char* argv[])

{

    int h,w;

    scanf("%d%d", &h, &w);



    int i,j;

    for(i=0; i<h; i++) {

        scanf("%s", str[i]);

        for(j=0; j<w; j++) {

            if(str[i][j]=='#') {

                a[i].push_back(j);

                b[j].push_back(i);

            }

        }

    }



    int max=0;

    for(i=0; i<h; i++) {

        for(j=0; j<w; j++) {

            if(str[i][j]=='.') {

                int num = (int)a[i].size();

                int k = lower_bound(a[i].begin(), a[i].end(), j) - a[i].begin();

                int tmp1 = (k>=num? w-1: a[i][k]-1);

                int tmp0 = (k==0? 0: a[i][k-1]+1);



                num = (int)b[j].size();

                k = lower_bound(b[j].begin(), b[j].end(), i) - b[j].begin();

                int tmp3 = (k>=num? h-1: b[j][k]-1);

                int tmp2 = (k==0? 0: b[j][k-1]+1);



                int tmp = (tmp1-tmp0+1)+(tmp3-tmp2+1)-1;

                max = MAX(max,tmp);

            }

        }

    }

    printf("%d\n", max);





    return 0;

}
