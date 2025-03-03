#include"stdc++.h"

using namespace std;

#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)

#define F first

#define S second

#define pb emplace_back

#define mt make_tuple

#define gcd __gcd

#define PI 3.141592653589

// Input

#define in(a) scanf("%d",&a)

#define in2(a,b) scanf("%d%d",&a,&b)

#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define llin(a) cin >> a

#define inl(a) scanf("%lld",&a)

#define read(v,i,n) for(i=0;i<n;i++)in(v[i])

#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}

#define sc(ch) scanf("%c",&ch)

#define sstr(str) scanf("%s",str)

// Output

#define pr(a) printf("%d ",a)

#define pr2(a,b) printf("%d %d\n",a,b)

#define pr3(a,b,c) printf("%d %d %d\n",a,b,c)

#define out(a) printf("%d\n",a)

#define outl(a) printf("%lld\n",a)

#define llpr(a) cout << a << " "

#define llout(a) cout << a << "\n"

#define yes printf("YES\n")

#define no printf("NO\n")

#define lin printf("\n")

// Iterator

#define lp(i,a,b) for(i=a;i<b;i++)

#define rep(i,n) for(i=0;i<n;i++)

#define all(vec) vec.begin(),vec.end()

#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()

#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()

#define tf(mytuple) get<0>(mytuple)

#define ts(mytuple) get<1>(mytuple)

#define tt(mytuple) get<2>(mytuple)

// Debug

#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin

#define what(x) cerr << #x << " : " << x << "\n"

#define ck printf("continue\n")

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>

void err(istream_iterator<string> it, T a, Args... args)

{

	cerr << *it << " = " << a << "\n";

	err(++it, args...);

}

// Data Type

#define ll long long int

#define ii pair<int,int>

#define pli pair<ll,int>

#define triple tuple<int,int,int>

#define vi vector<int>

#define vii vector<pair<int,int> >

#define vvi vector<vector<int> >

#define viii vector<pair<pair<int,int>,int> >

#define vvii vector<vector<pair<int,int> > >

#define M 1000000000

#define N 200005  //check the limits, man

int ar[4*N];

int step[N];

void pull(int p)

{

    ar[p]=min(ar[2*p],ar[2*p+1]);

}

void build(int l,int h,int p)

{

    if(l==h)

    {

        ar[p]=M;

        return ;

    }

    int m=((l+h)>>1);

    build(l,m,2*p);

    build(m+1,h,2*p+1);

    pull(p);

}

int query(int a,int b,int l,int h,int p)

{

    if(a<=l && b>=h)

        return ar[p];

    else if(a>h || b<l)

        return M;

    int m=((l+h)>>1);

    return min(query(a,b,l,m,2*p),query(a,b,m+1,h,2*p+1));

}

void update(int a,int x,int l,int h,int p)

{

    if(a<l || a>h)

        return ;

    if(l==h)

    {

        ar[p]=x;

        return ;

    }

    int m=((l+h)>>1);

    update(a,x,l,m,2*p);

    update(a,x,m+1,h,2*p+1);

    pull(p);

}

vvi ad(N);

int main()

{

    int n,k,i,j,x,a,m;

    in2(n,k);

    string str;

    cin >> str;

    build(0,n,1);

    step[n]=0;

    update(n,0,0,n,1);

    for(i=n-1;i>=0;i--)

    {

        if(str[i]=='1')

        {

            step[i]=M;

            continue;

        }

        step[i]=1+query(i+1,min(n,i+k),0,n,1);

        update(i,step[i],0,n,1);

    }

    if(step[0]>=M)

    {

        out(-1);

        return 0;

    }

    rep(i,n+1)

    {

        a=step[i];

        if(a<N)

            ad[a].pb(i);

    }

    vi ans;

    i=0;

    while(i<n)

    {

        a=query(i+1,min(n,i+k),0,n,1);

        j=lower(ad[a],i+1);

        x=ad[a][j];

        ans.pb(x-i);

        i=x;

    }

    m=ans.size();

    dbg(ans,i,m);

}
