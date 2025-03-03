#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <iomanip>



#include <vector>

#include <cstring>

#include <string>

#include <queue>

#include <deque>

#include <stack>

#include <map>

#include <set>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <list>



#include <cmath>

#include <algorithm>

#include <cassert>

#include <bitset>

#include <complex>



using namespace std;



typedef long long ll;

typedef pair<int, int> ii;

typedef pair<ll, ll> l4;



#define mp make_pair

#define pb push_back



const int maxn = 2e5+1;

int n, a[maxn], sorted[maxn];



int main()

{

  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)

    scanf("%d", a+i);

  memcpy(sorted, a, sizeof(sorted));

  sort(sorted+1, sorted+1+n);

  for (int i = 1; i <= n; ++i)

    printf("%d\n", a[i]<=sorted[n/2]?sorted[n/2+1]:sorted[n/2]);

}
