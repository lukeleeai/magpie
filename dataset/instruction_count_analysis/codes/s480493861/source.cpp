#include <iostream>

#include<stdio.h>

#include<string.h>

#include<math.h>

#include<queue>

#include<algorithm>

#define N 200500

#define LL long long

#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;

LL sum[N],t[N];

LL tree[N];

int n,k,a,m,nn;

void add(int x)

{

    while(x<=nn)//nn为上限，要大于离散化后的最大的数字，

    {

        tree[x]++;

        x+=x&-x;//向上更新，树状数组核心代码。此处就不解释了，不会的先学树状数组。

    }

}

LL query(int x)

{

    LL num=0;

    while(x)

    {

        num+=tree[x];

        x-=x&-x;//向下求和

    }

    return num;

}

int main()

{

    mem(t,0);

    mem(tree,0);

    mem(sum,0);

    scanf("%d%d",&n,&k);

    nn=n+10;

    for(int i=1; i<=n; i++)

    {

        scanf("%d",&a);

        t[i]=sum[i]=sum[i-1]+a-k;//预处理出sum[i]数组（就是上面讲解的num数组）

    }//t[i]数组为离散化的辅助数组

    sort(t,t+n+1);//排序，排n+1个数字的序（包括了sum[0]）

    m=unique(t,t+n+1)-t;//去重

    for(int i=0; i<=n; i++)

        sum[i]=lower_bound(t,t+m+1,sum[i])-t+1;//离散化

    LL ans=0;

    for(int i=0;i<=n;i++)

    {

        ans+=query(sum[i]);//查询有多少个小于sum[i]的数字

        add(sum[i]);//更新树桩数组。

    }

    printf("%lld\n",ans);

}
