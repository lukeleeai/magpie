#include <cstdio>

#include <algorithm>



#define maxn (200000 + 8)



using namespace std;



int n;

long long sum[maxn];



int main() {

    while (scanf("%d",&n)==1) {

        sum[0]=0;

        for (int i=1;i<=n;++i) {

            int a;

            scanf("%d",&a);

            sum[i]=sum[i-1]+a;

        }

        sort(sum,sum+n+1);

        unsigned long long res=0llu,cnt=1llu;

        for (int i=1;i<=n;++i) {

            if (sum[i]==sum[i-1]) {

                ++cnt;

                if (i==n) res+=cnt*(cnt-1llu)/2llu;

            }

            else {

                res+=cnt*(cnt-1llu)/2llu;

                cnt=1llu;

            }

        }

        printf("%llu\n",res);

    }

    return 0;

}
