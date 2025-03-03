#include "stdc++.h"

#define pb push_back



using namespace std;



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)

#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)

#define dbg_ok cerr<<"OK!\n"



typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



inline int two(int n) { return 1 << n; }

inline int test(int n, int pos) { return (bool) (n & two(pos)); }

inline void set_bit(int &n, int b) { n |= two(b); }

inline void unset_bit(int &n, int b) { n &= ~two(b); }

inline int last_bit(int n) { return n & (-n); }



const int DMAX = 1e5+10;



vector <int> vec;

vector <int> arb[DMAX];



struct nume{

    int node,val;

};



int V[DMAX];



priority_queue <nume> heap;



int n,ans;



inline bool operator<(nume x,nume y){

    return x.val<y.val;

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j,k,ant,cate;



    cin>>k>>n;

    for(i=1;i<=n;i++){

        cin>>V[i];

        heap.push({i,V[i]});

    }

    ant=0;

    nume var,var2;

    cate=ans=1;

    while(!heap.empty()){

        var=heap.top();

        heap.pop();

        if(var.node != ant){

           ant=var.node;

           if(var.val > 1)

              heap.push({var.node,var.val-1});

           cate=1;

           continue;

        }

        if(heap.empty()){

           cate++;

           ans=max(cate,ans);

           if(var.val > 1)

              heap.push({var.node,var.val-1});

           continue;

        }

        var2=heap.top();

        heap.pop();

        ant=var.node;

        cate=1;

        if(var2.val > 1)

           heap.push({var2.node,var2.val-1});

        if(var.val > 1)

           heap.push({var.node,var.val-1});



    }

    cout<<ans-1<<'\n';

    return 0;

}
