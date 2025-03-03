#include <string>

#include <cstring>

#include <vector>

#include <stdlib.h>

#include <time.h>

#include <algorithm>

#include <iostream>

#include <cstdio>

#include <queue>

#include <set>

using namespace std;

typedef long long ll;



int main(){

    ll n, k;

    scanf("%lld%lld",&n, &k);

    n = n % k;

    ll c = n - k;

    if(c < 0) c = -c;

    if(n < c) printf("%lld\n",n);

    else printf("%lld\n",c);

    return 0;

}