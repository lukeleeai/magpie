#include "stdc++.h"



using namespace std;

const int N = 300003;

const long long infll = 1000000000000000000;

int arr[N];

long long lef[N], righ[N];

int main()

{

    int n;

    scanf("%d",&n);

    for(int i = 0;i<3*n;i++)

        scanf("%d",&arr[i]);

    for(int i = 0;i<N;i++)

        lef[i] = -infll, righ[i] = infll;

    long long sum = 0;

    multiset<int> s;

    for(int i = 0;i<3*n;i++) {

        s.insert(arr[i]);

        sum += arr[i];

        if(s.size() == n) {

            lef[i] = sum;

        } else if(s.size() > n) {

            sum -= *s.begin();

            s.erase(s.begin());

            lef[i] = sum;

        }

    }

    s.clear();

    sum = 0;

    for(int i = 3*n-1;i>=0;i--) {

        sum += arr[i];

        s.insert(arr[i]*-1);

        if(s.size() == n) {

            righ[i] = sum;

        } else if (s.size() > n) {

            sum -= *(s.begin()) * -1;

            s.erase(s.begin());

            righ[i] = sum;

        }

    }

    for(int i = 1;i<N;i++)

        lef[i] = max(lef[i],lef[i-1]);

    for(int i = N-2;i>=0;i--)

        righ[i] = min(righ[i], righ[i+1]);

    long long ans = -infll;

    for(int i = 0;i<3*n;i++)

        ans = max(ans,lef[i] - righ[i+1]);

    printf("%lld",ans);

    return 0;

}
