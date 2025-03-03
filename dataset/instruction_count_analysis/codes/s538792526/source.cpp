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

#include <stack>

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

//const long long MOD = 998244353;

using namespace std;



char str[30000];



int main(int argc, char* argv[])

{

    int n;

    scanf("%d", &n);

    scanf("%s", str);



    set<int> z1,z2,z3;

    int i;

    for(i=0; i<n; i++) {

        int tmp=str[i]-'0';

        {

            auto it=z2.begin();

            for(; it!=z2.end(); ++it) {

                z3.insert((*it)*10+tmp);

            }

        }

        {

            auto it=z1.begin();

            for(; it!=z1.end(); ++it) {

                z2.insert((*it)*10+tmp);

            }

        }

        z1.insert(tmp);

    }

    printf("%d\n", (int)z3.size());



    return 0;

}
