#include "stdc++.h"

using namespace std;

#define ll long long

#define LLMAX (1ll << 60) - 1

#define INTMAX (1 << 30) - 1

#define MOD 1000000007 

#define NMAX 1000*100+1



#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)

#define MSET(x,y) memset(x,y,sizeof(x))

#define gcd(a,b) __gcd(a,b)

#define all(x)  x.begin(),x.end()

#define isOn(S, j) (S & (1 << j))

#define endl '\n'

#define setBit(S, j) (S |= (1 << j))

#define clearBit(S, j) (S &= ~(1 << j))

#define toggleBit(S, j) (S ^= (1 << j))

#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;

#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;

#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}



#define vi vector<ll>

#define vvi vector<vi>

#define ii pair<ll,ll>

#define pll pair<ll,ll>

#define vii vector<ii>

#define vvii vector<vii>

#define viii vector<pair<ii,ll>>

#define pb push_back

#define F first

#define S second

#define mp make_pair

#define mc(a,b,c) mp(mp(a,b),c)

struct DSU

{

    int n,x;

    vi p,r,sz;

    DSU(int N){

        n=N;x=N-1;sz.assign(N,1);p.assign(N,0);r.assign(N,1);

        for(int i=0;i<N;i++)p[i]=i;

    }

    int find(int i){return (p[i]==i)?i:(p[i]=find(p[i]));}

    bool sameset(int i,int j){return find(i)==find(j);}

    void join(int i,int j)

    {

        int p1=find(i);int p2=find(j);

        if(p1!=p2){

            x--;

            if(r[p1]>=r[p2]){

                p[p2]=p1;

                sz[p1]+=sz[p2];

                if(r[p1]==r[p2])

                    r[p1]++;

            }

            else{

                p[p1]=p2;

                sz[p2]+=sz[p1];

            }

        }

    }

    void debug(){for(int it:p)cout<<it<<' ';cout<<endl;}

    int getsize(int i){return sz[find(i)];}

    int noOfSets(){return x;}

};



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll n,x,t,m,y,z;

    cin>>n>>m;

    DSU foo(n);

    vvi lang(m);

    for(int i=0;i<n;i++){

        cin>>x;

        for(int j=0;j<x;j++){

            cin>>y;

            y--;

            lang[y].pb(i);

        }

    }

    for(int i=0;i<m;i++){

        for(int j=1;j<lang[i].size();j++){

            foo.join(lang[i][j], lang[i][j-1]);

        }

    }

    cout<<(foo.noOfSets()?"NO":"YES");

    





    return 0;

}