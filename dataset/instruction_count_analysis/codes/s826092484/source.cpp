/*

Till the roof comes off, till the lights go out

Till my legs give out, canâ��t shut my mouth.

Till the smoke clears out. Am I high? Perhaps

I'ma rip this shit till my bones collapse.

*/

#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <vector>

#include <deque>

#include <set>

#include <stack>

#include <string.h>

#include <map>

#include <vector>

#include <queue>

#include <math.h>

#include <stack>

#include <complex>





#define ll long long

#define X real()

#define Y imag()

#define f first

#define s second

#define angle(a)                (atan2((a).imag(), (a).real()))

#define vec(a,b)                ((b)-(a))

#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)

#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep

#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel

#define lngth(a)               (hypot((a).imag(), (a).real()))

#define normalize(a)            (a)/length(a)



using namespace std;



const int N=200005;

typedef pair<ll,int>ii;

typedef pair<ii,int>event;

typedef complex<double>point;

const double EPS = 1e-9;

const int INF=100000;



const double PI = acos(-1);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }



int n,m,a[N],d[N],c[N],mx[N],sol[N];

vector<int>adj[N];

bool v[N][12];

void bfs(int node,int dep,int col){

   if(mx[node]>dep)return;

   queue<int>q;

   q.push(node);

   q.push(dep);

   v[node][dep]=1;

  if(mx[node]==-1)

   sol[node]=col;

   mx[node]=dep;

   while(q.size()){

        node=q.front();

        q.pop();

        dep=q.front();

        q.pop();

        if(!dep)continue;

        for(int i=0;i<adj[node].size();i++){

            int to=adj[node][i];

            if(mx[to]>=dep-1)continue;

           if(mx[to]==-1)

            sol[to]=col;

            mx[to]=dep-1;

            q.push(to);

            q.push(dep-1);

        }

   }

}

int main()

{

    //freopen("test.in","r",stdin);

   //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){

        int a,b;

        scanf("%d%d",&a,&b);

        adj[a].push_back(b);

        adj[b].push_back(a);

    }

    memset(mx,-1,sizeof(mx));

    int q;

    scanf("%d",&q);

    for(int i=0;i<q;i++)

        scanf("%d%d%d",&a[i],&d[i],&c[i]);

    memset(sol,0,sizeof(sol));

    for(int i=q-1;i>-1;i--){

        bfs(a[i],d[i],c[i]);

    }

    for(int i=1;i<=n;i++)cout<<sol[i]<<endl;

    return 0;

}
