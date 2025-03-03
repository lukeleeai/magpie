#include"stdc++.h"

const int maxn = 100035;



int a[maxn],n,l,t,x,cnt;



int main()

{

    scanf("%d%d%d",&n,&l,&t);

    for (int i=1; i<=n; i++)

    {

        scanf("%d%d",&a[i],&x);

        a[i] += x==1?t:-t;

        cnt += a[i]/l;

        if (a[i]%l<0) cnt--;

        ((a[i]%=l)+=l)%=l;

    }

    std::sort(a+1, a+n+1);

    ((cnt%=n)+=n)%=n;

    for (int i=cnt+1; i<=n; i++) printf("%d\n",a[i]);

    for (int i=1; i<=cnt; i++) printf("%d\n",a[i]);

    return 0;

}
