#include "stdc++.h"

using namespace std;

const int N = 3e5+20 , MaxlogN = 25 , INF = 0x3f3f3f3f;

struct node { int x,y; } a[N];

int n,w,h,ans,Min[N],Max[N];

int q[N],head,tail,border;

inline void input(void)

{

    scanf("%d%d%d",&w,&h,&n);

    for (int i=1;i<=n;i++)

        scanf("%d%d",&a[i].x,&a[i].y);

}

inline void divide(int l,int r)

{

    if ( l == r ) return void();

    int mid = l + r >> 1 , y1 , y2;

    divide( l , mid ) , divide( mid+1 , r );

    y1 = 0 , y2 = h;

    for (int i=mid;i>=l;i--)

    {

        Max[i] = y1 , Min[i] = y2;

        if ( a[i].y <= border ) y1 = max( y1 , a[i].y );

        if ( a[i].y >= border ) y2 = min( y2 , a[i].y );

    }

    y1 = 0 , y2 = h;

    for (int i=mid+1;i<=r;i++)

    {

        Max[i] = y1 , Min[i] = y2;

        if ( a[i].y <= border ) y1 = max( y1 , a[i].y );

        if ( a[i].y >= border ) y2 = min( y2 , a[i].y );

    }

    head = 1 , tail = 0;

    for (int i=mid,j=mid+1;i>=l;i--)

    {

        while ( j <= r && Max[j] <= Max[i] )

        {

            while ( head <= tail && Min[q[tail]] + a[q[tail]].x <= Min[j] + a[j].x ) tail--;

            q[++tail] = j++;

        }

        while ( head < tail && Min[i] + a[q[head]].x <= Min[q[head+1]] + a[q[head+1]].x ) head++;

        ans = max( ans , 2 * ( a[q[head]].x - a[i].x + min( Min[i] , Min[q[head]] ) - Max[i] ) );

    }

    head = 1 , tail = 0;

    for (int i=mid+1,j=mid;i<=r;i++)

    {

        while ( j >= l && Max[j] <= Max[i] )

        {

            while ( head <= tail && Min[q[tail]] - a[q[tail]].x <= Min[j] - a[j].x ) tail--;

            q[++tail] = j--;

        }

        while ( head < tail && Min[i] - a[q[head]].x <= Min[q[head+1]] - a[q[head+1]].x ) head++;

        ans = max( ans , 2 * ( a[i].x - a[q[head]].x + min( Min[i] , Min[q[head]] ) - Max[i] ) );

    }

}

inline void solve(void)

{

    auto compare = [](node p1,node p2) { return p1.x < p2.x; };

    sort( a+1 , a+n+1 , compare );

    a[0] = (node){0,h/2} , a[n+1] = (node){w,h/2};

    border = h/2 , divide( 0 , n + 1 );

    for (int i=1;i<=n;i++)

        swap( a[i].x , a[i].y );

    swap( w , h );

    sort( a+1 , a+n+1 , compare );

    a[0] = (node){0,h/2} , a[n+1] = (node){w,h/2};

    border = h/2 , divide( 0 , n + 1 );

}

int main(void)

{

    input();

    ans = 2 * ( max(w,h) + 1 );

    solve();

    printf("%d\n",ans);

    return 0;

}
