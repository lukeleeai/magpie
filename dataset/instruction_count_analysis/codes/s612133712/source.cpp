#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int maxd =2e5+10;

struct node

{

    int a,b;

    bool operator < (const node &other) const

    {

        if(b == other.b) return a < other.a;

        return b < other.b;

    }

}a[maxd];

int n;

int main()

{

    // freopen("a.in","r",stdin);

    // freopen("k.out","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

        scanf("%d %d",&a[i].a,&a[i].b);

    sort(a+1,a+1+n);

    int now = 0;

    for(int i=1;i<=n;i++)

    {

        if(now + a[i].a > a[i].b)

        {

            printf("No\n");

            return 0;

        }

        now += a[i].a;

    }

    printf("Yes\n");

    return 0;

}  