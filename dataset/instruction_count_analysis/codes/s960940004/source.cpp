#include "stdc++.h"

using namespace std;

const auto start_time = std::chrono::high_resolution_clock::now();

void timecalculater(){

    #ifndef ONLINE_JUDGE

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end_time-start_time;

    cerr<<"Time Taken : "<<diff.count()<<"\n";

    #endif

}

void __print(int x) {cout << x;}

void __print(long x) {cout << x;}

void __print(long long x) {cout << x;}

void __print(unsigned x) {cout << x;}

void __print(unsigned long x) {cout << x;}

void __print(unsigned long long x) {cout << x;}

void __print(float x) {cout << x;}

void __print(double x) {cout << x;}

void __print(long double x) {cout << x;}

void __print(char x) {cout << '\'' << x << '\'';}

void __print(const char *x) {cout << '\"' << x << '\"';}

void __print(const string &x) {cout << '\"' << x << '\"';}

void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>

void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}

void _print() {cout << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}

#ifndef ONLINE_JUDGE

#define dbg(x...) cout << "[" << #x << "] = ["; _print(x)

#else

#define dbg(x...)

#endif

#define rep(i, n) for(ll i = 0; i < (n); ++i)

#define repA(i, a, n) for(int  i = a; i <= (n); ++i)

#define all(x) x.begin(), x.end()

#define sz(x) (int) (x).size()

#define fill(a) memset(a, 0, sizeof(a))

#define fst first

#define snd second

#define mp make_pair

#define pb push_back

#define endl '\n'

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<long long, long long> pll;

typedef vector<int> vi;

typedef vector<double> vd;

typedef vector<long long int> vll;

typedef vector<pii> vii;

ll p=1e9+7;

const int N=2e5+5;

ll power(ll a,ll x){

    if(x<0)return 1;

    ll r=1;

    while(x!=0){

        if(x%2==1){

            r=r*a;r%=p;

        }

        a=a*a;a%=p;

        x=x/2;

    }

    return r;

}

ll mul(ll a,ll b){

    ll t=(a*b);

    if(t>=p)t%=p;

    return t;

}

int main() {

  

    cin.sync_with_stdio(0); cin.tie(0);

    cin.exceptions(cin.failbit);

    int T=1;

    // cin>>T;

    while(T--){

        int n;cin>>n;

        int a[n],b[n];

        rep(i,n)cin>>a[i];

        rep(i,n)cin>>b[i];

        int c[2*n-2],d[n-1];

        rep(i,n-1)d[i]=b[i]^b[i+1];

        rep(i,2*n-2)c[i]=a[i%n]^a[(i+1)%n];



        int lps[n-1]={0};

        repA(i,1,n-2){

            int j=lps[i-1];

            while(j>=0){

                if(d[j]==d[i]){

                    lps[i]=j+1;

                    break;

                }

                if(j<1)break;

                j=lps[j-1]; 

            }

        }

        int j=0;

        rep(i,2*n-2){

            if(c[i]==d[j]){

                j++;

                if(j==(n-1)){

                    // cout<<(i-(n-1)+1)<<endl;

                    cout<<(i-n+2)<<" "<<(a[i-n+2]^b[0])<<endl;

                    j=lps[j-1];

                }

            }

            else{

                if(j==0){

                    continue;

                }

                i--;j=lps[j-1];

            }

            

        }

    }   

    timecalculater();

    return 0;   

} 