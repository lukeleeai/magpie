#include"stdc++.h"

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")

//#pragma GCC target("avx,avx2,fma")

using namespace std;

using namespace __gnu_pbds;

 

#define int long long

#define pii pair<int,int>

#define pqi priority_queue<int>

#define pb push_back()

#define INF 1000000000000000000

#define pi acos(-1)

#define deb(x) cout<<#x" = "<<x<<" "

#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

#define all(x) x.begin(),x.end()

const int modu=1e9+7;

#define ull unsigned long long

 

void clesize(vector<int>&v,int n,int val=0){ v.clear(),v.resize(n,val); }   

 

int bigmod(int n,int p){

    if(p==0) return 1;

    int x=bigmod(n,p/2)%modu;

    x=(x*x)%modu;

    if(p%2) return (x*n)%modu;

    return x;

}

 

int modInverse(int a){

    return bigmod(a,modu-2)%modu;

}

 

 

int add(int a,int b){

    int ans=(a%modu + b%modu)%modu;

    while(ans<0) ans+=modu;

    return ans;

}

 

int mul(int a,int b){

    int ans=(a%modu * b%modu)%modu;

    while(ans<0) ans+=modu;

    return ans;

}

 

// starts here



int32_t main(){

    ios_base::sync_with_stdio(false);cin.tie();cout.tie();

    //If you hack my code , You are gay;

    int n,m;

    cin>>n>>m;

    int grid[n][m],ans[n][m];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            ans[i][j]=INF;

            char x;

            cin>>x;

            grid[i][j] = (x=='.') ? 0:1;

        }

    }

    ans[0][0]=grid[0][0];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(j+1<m){

                int now=ans[i][j];

                if(grid[i][j+1] && !grid[i][j]) now++;

                ans[i][j+1]=min(ans[i][j+1],now);

            }

            if(i+1<n){

                int now=ans[i][j];

                if(grid[i+1][j] && !grid[i][j]) now++;

                ans[i+1][j]=min(ans[i+1][j],now);

            }

        }

    }

    cout<<ans[n-1][m-1];

    //endscreen();

    return 0;

 

}