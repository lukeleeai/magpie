#include<cstdio>

#include<algorithm>

using namespace std;

const int maxn = 1e5 + 7;

int a[maxn];

int main(){

    int n, k;

    scanf("%d%d", &n, &k);

    int cnt = -1;

    for(int i = 0; i < n; ++i){

        scanf("%d", &a[i]);

        if(a[i] >= 0 && cnt == -1){

            cnt = i;

        }

    }

    //a[cnt] >= 0

    if(cnt == -1){

        printf("%d\n", -a[n - k]);

        return 0;

    }

    else if(cnt == 0){

        printf("%d\n", a[k - 1]);

        return 0;

    }



    int ans = 2e9;

    if(cnt - k >= 0){

        ans = min(ans, -a[cnt - k]);

    }

    if(cnt + k - 1 < n){

        ans = min(ans, a[cnt + k - 1]);

    }

    for(int i = 1; i < k; ++i){

        if(cnt - i < 0 || cnt + k - i - 1 >= n)

            continue;

            ans = min(ans, -2*a[cnt - i] + a[cnt + k - i - 1]);

    }

    for(int i = 1; i < k; ++i){

        if(cnt + i - 1 >= n || cnt - k + i < 0)

            continue;

        ans = min(ans, 2*a[cnt + i - 1] - a[cnt - k + i]);

    }

    printf("%d\n", ans);

}
