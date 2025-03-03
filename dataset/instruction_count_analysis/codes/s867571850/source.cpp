#include <cmath>

#include <cstdlib>

#include <iostream>

#include <bitset>

#include <deque>

#include <list>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <vector>

#include <algorithm>

#include <iterator>

#include <string>

#include <chrono>

#include <random>

#include <tuple>

#include <utility>

#include <fstream>

#include <complex>



const long INF = (1l << 30);

const long LINF = (1l << 60);

const long MOD =1000000007;



long n;

long ans = 1;

long a[1005];



int main(){

    scanf("%ld", &n);

    for(long i = 0; i <= n; i++){

        a[i] = i;

    }

    for(long div = 2; div <= n; div++){

        long cnt = 0;

        for(long i = 1; i <= n; i++){

            while(a[i] % div == 0){

                cnt++;

                a[i] /= div;

            }

        }

        ans *= (cnt + 1);

        ans %= MOD;

    }

    printf("%ld\n", ans);

}
