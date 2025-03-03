#include "stdc++.h"

#define pb push_back



using namespace std;



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)

#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)

#define dbg_ok cerr<<"OK!\n"



typedef pair<int,int> pii;

typedef unsigned long long int ll;

typedef long double ld;



const int DMAX = 1e5+10;



vector <int> vec;

vector <int> arb[DMAX];



int V[DMAX];



ll n;



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j;



    cin>>n;

    n+=2;

    n=(1LL<<n)-2;

    cout<<n<<'\n';



    return 0;

}
