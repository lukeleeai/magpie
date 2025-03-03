#include"stdc++.h"

using namespace std;



//defines

#define openin freopen("input.txt","r",stdin)

#define openout freopen("output.txt","w",stdout)

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define ll long long

#define int long long

#define mod 1000000007

#define repr(i,x,y) for (__typeof(x) i=x;i>=y;i--)

#define rep(i,x,y) for (__typeof(x) i=x;i<=y;i++)

#define all(c) (c).begin(),(c).end()

#define ff first

#define ss second

#define pb push_back

#define mp make_pair



/* Print pair */

template <typename T,typename S>

ostream & operator << (ostream &os , const pair<T,S> &v) {

    os << "(" ;

    os << v.first << "," << v.second << ")" ;

    return os ;

}

/* Print vector */

template <typename T>

ostream & operator << (ostream &os , const vector<T> &v) {

    os << "[" ;

    int sz = v.size() ;

    for(int i = 0 ; i < sz ; ++i) {

        os << v[i] ;

        if(i!=sz-1)os << "," ;

    }

    os << "]\n" ;

    return os ;

}

/* Print set */

template <typename T>

ostream & operator << (ostream &os , const set<T> &v) {

    T last = *v.rbegin() ;

    os << "[" ;

    for(auto it : v) {

        os << it  ;

        if(it != last) os << "," ;

    }

    os << "]\n" ;

    return os ;

}

/* Print Map */

template <typename T,typename S>

ostream & operator << (ostream &os , const map<T,S> &v) {

    for(auto it : v) {

        os << it.first << " : " << it.second << "\n" ;

    }

    return os ;

}

int power(int a , int b)

{

    int res = 1 ;

    while(b)

    {

        if(b%2) {

            res = (res * a) % mod ;

        }

        b/=2 ;

        a = (a*a) % mod ;

    }

    return res ;

}



//debug

#define TRACE



#ifdef TRACE

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

void __f(const char* name, Arg1&& arg1){

        cerr << name << " : " << arg1 << std::endl;

}

template <typename Arg1, typename... Args>

void __f(const char* names, Arg1&& arg1, Args&&... args){

        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);

}

#else

#define trace(...)

#endif



const int N = 3e5 + 5 ; 



int arr[N] ; 

int cnt[N] ; 

int present[N] ; 



int32_t main()

{

    fast;

    int n , m ; cin >> n >> m ; 

    rep(i,0,n-1) cin >> arr[i] ; 

    rep(i,0,n-1) cnt[arr[i]] ++ ; 

    int ans = 0 ; 

    rep(i,1,n) {

        int temp = max(0LL,i-cnt[i]) ;

        rep(j,temp,i-1) present[j]++;

    }

    rep(i,0,n-1) if(!present[i]) ++ans ;

    rep(i,1,m) {

        int x , y ; cin >> x >> y ; --x ;

        if(y != arr[x]) {

            if(y > cnt[y]) {

                if(present[y-cnt[y]-1] == 0) --ans ;

                present[y-cnt[y]-1]++ ;

            }

            if(arr[x] >= cnt[arr[x]]) {

                if(present[arr[x]-cnt[arr[x]]] == 1) ++ans ;

                present[arr[x]-cnt[arr[x]]]-- ; 

            }

            cnt[arr[x]]-- ; 

            cnt[y]++ ; 

            arr[x] = y ;

        }

        cout << ans << endl ;

    }

    return 0;

}
