#include "stdc++.h"

using namespace std;



#define MAX_N 300005

#define INF 0x3f3f3f3f3f3f3f3f



int n;

int a[MAX_N];



int main()

{

    scanf("%d",&n);

    for(int i=0; i<3*n; i++)

        scanf("%d",&a[i]);



    vector <long long> dp1(3*n ,-INF) ,dp2(3*n ,INF);

    multiset <int> ms;

    long long sum = 0LL;

    for(int i=0; i<3*n; i++){

        ms.insert(a[i]) ,sum += a[i];

        if(ms.size() > n){

            sum -= *ms.begin();

            ms.erase(ms.begin());

        }

        if(ms.size() == n)

            dp1[i] = sum;

    }

    sum = 0 ,ms.clear();

    for(int i=3*n-1; ~i; i--){

        ms.insert(a[i]) ,sum += a[i];

        if(ms.size() > n){

            sum -= *prev(ms.end());

            ms.erase(prev(ms.end()));

        }

        if(ms.size() == n)

            dp2[i] = sum;

    }



    long long ans = -INF;

    for(int i=0; i<3*n-1; i++)

        ans = max(ans ,dp1[i]-dp2[i+1]);

    printf("%lld\n",ans);

}
