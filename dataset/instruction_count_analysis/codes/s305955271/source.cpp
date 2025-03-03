#include <cstdio>

#include<cstring>

#include <algorithm>

using  namespace std;

#define mem(v,x) memset(v,x,sizeof(v))

#define low(x) (x & (-x))

int pos[500010],n,m;



int main() {

    scanf("%d",&n);

    for (int i = 1; i <= n; i++){

       scanf("%d",&m);

       pos[m] = i;

    }

    int len = 1,ans = 5000000;

    for (int i = 1; i < n; i++){

        if (pos[i+1] > pos[i]) len++; else{

            ans = min(ans,n-len);

            len = 1;

        }

    }

    ans = min(ans,n-len);

    printf("%d\n",ans);



    return 0;

}