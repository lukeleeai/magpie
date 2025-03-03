

//  main.cpp

//  solve

//

//  Created by Ahmed on 11/16/16.

//  Copyright © 2016 Abdellah. All rights reserved.

//





#include<set>

#include<map>

#include <unordered_map>

#include <unordered_set>

#include<list>

#include<iomanip>

#include<cmath>

#include<string>

#include<vector>

#include<queue>

#include<stack>

#include<complex>

#include<sstream>

#include<iostream>

#include<fstream>

#include<algorithm>

#include<numeric>

#include<utility>

#include<functional>

#include<stdio.h>

#include<assert.h>

#include<memory.h>

#include<bitset>

#include<math.h>

#include <strings.h>







#define f first

#define s second

#define pb push_back

#define sz(a) (int)a.size()

#define lp(i,a,n) for(int (i)=(a);(i)<=(int)(n);(i)++)

#define lpd(i,n,a) for(ll (i)=(n);(i)>=(a);--(i))

#define mp make_pair

#define clr(a,b) memset(a,b,sizeof a)

#define all(v) v.begin(),v.end()

#define mod 1000000007

#define eps 1e-6

#define infi 1000000002

#define infll 1000000000000000000ll

#define MX 1000000

#define X real()

#define Y imag()

#define polar(r,t) ((r)* exp(point(0,(t))))

#define length(a) hypot( (a).X , (a).Y )

#define angle(a) atan2( (a).Y , (a).X )

#define vec(a,b) ( (b) - (a) )

#define dot(a,b) (conj(a)*(b)).X

#define cross(a,b) (conj(a)*(b)).Y

#define lengthsqr(a) dot(a,a)

#define reflect(V,M) (conj((V)/(M)) * (M))

#define normalize(a)   ((a)/length(a))

#define ccw(a,b,c)   cross(vec(a,b) , vec(a,c)) > -eps

#define cosRule(a,b,c) (acos(((a)*(a)+(b)*(b)-(c)*(c))/(2*(a)*(b))))

#define cosDot(a,b) (acos(dot(a,b)/length(a)/length(b)))

#define EQ(a,b) (fabs((a) - (b)) <= eps) /* equal to */

#define NE(a,b) (fabs((a) - (b)) > eps)  /* not equal to */

#define LT(a,b) ((a) < (b) - eps)        /* less than */

#define GT(a,b) ((a) > (b) + eps)        /* greater than */

#define LE(a,b) ((a) <= (b) + eps)       /* less than or equal to */

#define GE(a,b) ((a) >= (b) - eps)       /* greater than or equal to */

#define mod1 100050001

#define mod2 100030001

#define base1 37

#define base2 31

#define que priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int> > >

#define rotate(v,t) ((v)*exp(point(0,t)))

#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))

#define PI atan(1)*4



using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<double,double> pdd;

typedef pair<ll, ll> pll;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<vi> vvi;

typedef set<int> si;

typedef map<int, int> mii;

typedef complex<long double> point;

typedef pair<point, point> line;

typedef pair<double , point> Circle;



const int N = 200005;

int n,m,q,a[N] , c[N];



bool vis[N][12];

vi adjL[N];





void dfs(int node,int d,int color) {

    if(d == -1 || vis[node][d]) return;

    vis[node][d] = true;

    if(!c[node]) c[node] = color;

    for(int ch:adjL[node]) dfs(ch, d-1, color);

}



struct query {

    int v,d,c;

}qs[N];

int main()

{

    scanf("%d%d",&n,&m);

    

    lp(i, 1, m) {

        int a,b;

        scanf("%d%d",&a,&b);

        adjL[a].pb(b),adjL[b].pb(a);

    }

    

    scanf("%d",&q);

    lp(i, 1, q) scanf("%d%d%d",&qs[i].v,&qs[i].d,&qs[i].c);

    

    lpd(i, q, 1) dfs(qs[i].v, qs[i].d, qs[i].c);

    

    lp(i, 1, n) printf("%d\n",c[i]);

    

    return 0;

}

/*

 

 */

//freopen("output.txt","w",stdout);

//freopen("input.txt","r",stdin);

//ios::sync_with_stdio(0);cin.tie(0);


