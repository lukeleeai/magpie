#include "stdc++.h"

//#include <ext/rope>

//

//using namespace __gnu_cxx;



#define rep(i,e) for(int i=0;i<(e);i++)

#define rep1(i,e) for(int i=1;i<=(e);i++)

#define repx(i,x,e) for(int i=(x);i<=(e);i++)

#define pii pair<int,int>

#define X first

#define Y second

#define PB push_back

#define MP make_pair

#define mset(var,val) memset(var,val,sizeof(var))

#define scd(a) scanf("%d",&a)

#define scdd(a,b) scanf("%d%d",&a,&b)

#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define IOS ios::sync_with_stdio(false);cin.tie(0)



using namespace std;



//#ifdef local

//    #define dbg(args...) do { cout  << #args << " -> "; err(args); cout << endl;} while (0)

//#else

//    #define dbg(...)

//#endif

//

//void err() {  }

////template<template<typename...> class T, typename t, typename... Args>

////void err(T<t> a, Args... args) { for (auto x: a) cout << x << ' '; err(args...); }

//template<typename T, typename... Args>

//void err(T a, Args... args) { cout << a << ' '; err(args...); }





typedef long long ll;

template <class T>

void test(T a) {

    cout<<a<<endl;

}

template <class T,class T2>

void test(T a,T2 b) {

    cout<<a<<" "<<b<<endl;

}

template <class T,class T2,class T3>

void test(T a,T2 b,T3 c) {

    cout<<a<<" "<<b<<" "<<c<<endl;

}

const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;

const int mod = 1e9+7;



const int N = 1e5+10;



set<int> s;



void work() {

    int n, m;

    scdd(n, m);

    for(int i = 1; i <= sqrt(m+1); ++i){

        if(m%i == 0){

            s.insert(m/i);

            s.insert(i);

        }

    }

    int x = *(s.lower_bound(n));

    printf("%d\n", m/x);

}





int main() {

#ifdef local

    freopen("in.txt","r",stdin);

//        freopen("out1.txt","w",stdout);

#endif // local

//    IOS;

//    init();

    int t;

//    cin >> t;

//    scd(t);

//    for(; t--;)

        work();

    return 0;

}
