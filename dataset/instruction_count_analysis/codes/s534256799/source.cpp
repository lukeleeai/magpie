#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define mst(a,b) memset(a,b,sizeof(a))

#define lowbit(x) ((x)&(-x))

#define X first

#define Y second

using namespace std;

using namespace __gnu_cxx;

using namespace __gnu_pbds;

typedef long long LL;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 200000+10;

const int maxm = 2222222+10;

const int mod = 1e9+7;

const double eps = 1e-9;

int r,c;

bool check(int x,int y){

    return x==0 || x==r || y==0 || y==c;

}

ll dist(int x,int y){

    return 1ll*x*x+1ll*y*y;

}

struct Point{

    int x,y,id;

    Point (int x=0,int y=0,int id=0):x(x),y(y),id(id){}

    bool operator < (const Point &rhs) const {

        return 1ll*x*rhs.y>1ll*rhs.x*y || 1ll*x*rhs.y==1ll*rhs.x*y && dist(x,y)<dist(rhs.x,rhs.y);

    }

}a[maxn];

bool in[maxn];

stack<int> stk;

int main() {

#ifdef local

    freopen("in.txt", "r", stdin);

//    freopen("out.txt", "w", stdout);

#endif

    ios::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    int n; cin>>r>>c>>n;

    int tot=0,p=-1;

    for (int i=0;i<n;i++){

        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;

        if (check(x1,y1) && check(x2,y2)){

            if (p==-1 || (a[p].y>y1 || a[p].y==y1 && a[p].x>x1)) p=tot;

            a[tot++]=Point(x1,y1,i);

            if (p==-1 || (a[p].y>y2 || a[p].y==y2 && a[p].x>x2)) p=tot;

            a[tot++]=Point(x2,y2,i);

        }

    }

    if (~p){

        int dx=a[p].x,dy=a[p].y;

        for (int i=0;i<tot;i++){

            a[i].x-=dx;

            a[i].y-=dy;

        }

        sort(a,a+tot);

        for (int i=0;i<tot;i++){

            if (!in[a[i].id]){

                in[a[i].id]=true;

                stk.push(a[i].id);

            } else {

                if (stk.top()!=a[i].id){

                    cout<<"NO\n";

                    return 0;

                }

                stk.pop();

                in[a[i].id]=false;

            }

        }

    }

    cout<<"YES\n";

    return 0;

}
