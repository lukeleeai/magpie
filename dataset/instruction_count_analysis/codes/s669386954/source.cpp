#include "stdc++.h"

#define up(i,a,b) for(int i=a;i<=b;i++)

#define down(i,a,b) for(int i=a;i>=b;i--)

#define rep(i,a,b) for(int i=a;i<b;i++)

#define repd(i,a,b) for(int i=a-1;i>=b;i--)

#define CL(x) (x<<1)

#define CR(x) (x<<1)+1

#define pb push_back

#define bit1(x) __builtin_popcount(x)



using namespace std;



typedef long long ll;

typedef pair<int,int> pii;



template<typename T> inline void _read(T &x){

    char ch; x=0; bool neg=false;

    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())

        if(ch=='-') neg=true;

    for(;ch>='0'&&ch<='9';ch=getchar()) x=10*x+ch-'0';

    if(neg) x=-x;

}

#define read(a) _read(a)

#define Read(a,b) _read(a),_read(b)



const int maxn=1e5+7;

const int maxS=(1<<6);

const ll mod=1e9;

const int inf=1e9+7;

const ll linf=1e16+9;



int n,t[maxn],kq;

struct Neko{

    int x,y;

}a[maxn];



inline void Enter(){

    cin>>n;

    up(i,1,n) cin>>t[i]>>a[i].x>>a[i].y;

}



inline int dis(Neko x,Neko y){

    return abs(x.x-y.x)+abs(x.y-y.y);

}



inline void Solve(){

    up(i,1,n){

        int Time=t[i]-t[i-1];

        if(dis(a[i],a[i-1])%2 == Time%2 && dis(a[i],a[i-1])<=Time) kq++;

    }

    if(kq!=n) cout<<"No";

    else cout<<"Yes";

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL),cout.tie(NULL);

    //freopen("TEST.INP","r",stdin);

    //freopen("TEST.OUT","w",stdout);



    Enter();

    Solve();



    return 0;

}
