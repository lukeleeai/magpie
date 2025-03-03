#include"stdc++.h"

using namespace std;

    int p[100010],q[100010],s[300010];

    int x,y,a,b,c;

    long long ans;

void qs(int f[],int l,int r)

{

    int i=l,j=r;

    int t;

    int x=f[(l+r)/2];

    do

    {

        while (f[i]>x) i++;

        while (f[j]<x) j--;

        if (i<=j)

        {

            t=f[i];

            f[i]=f[j];

            f[j]=t;

            i++;

            j--;

        }

    }while (i<=j);

    if (l<j) qs(f,l,j);

    if (i<r) qs(f,i,r);

}

int main()

{

    scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);

    for (int i=1;i<=a;i++) scanf("%d",&p[i]);

    qs(p,1,a);

    for (int i=1;i<=x;i++) s[i]=p[i];

    for (int i=1;i<=b;i++) scanf("%d",&q[i]);

    qs(q,1,b);

    for (int i=1;i<=y;i++) s[x+i]=q[i];

    for (int i=1;i<=c;i++) scanf("%d",&s[x+y+i]);

    qs(s,1,x+y+c);

    ans=0;

    for (int i=1;i<=x+y;i++)

        ans+=s[i];

    cout << ans << endl;

}
