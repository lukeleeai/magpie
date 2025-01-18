#include"stdc++.h"

#include<ext/pb_ds/assoc_container.hpp>



using namespace std;

using namespace __gnu_pbds;

//#define int          long long int

#define rep(i,n) for(int i=0;i<n;i++)

#define mod      1000000007

#define MOD      998244353

#define mp       make_pair

#define pb       push_back

#define F        first

#define S        second

#define t()      int test;cin>>test;while(test--)

#define ii       pair<int,int>

#define endl     "\n"

#define que_max  priority_queue <int>

#define IOS      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



typedef tree < int ,  null_type ,  greater <int> ,  rb_tree_tag ,  tree_order_statistics_node_update > pbds;



int pw(int b, int p) { int r = 1; while (p > 0) { if (p & 1) r = r * b;

        p = p >> 1; b = b * b; } return r; }





int n,k;

vector <int> arr(1e5);

vector <int> dp(1e5 , -1);



int solve(int id)

{

    if(id == n-1)

        return 0;



    if(dp[id]!=-1)

    {

        return dp[id];

    }

    int ans = INT_MAX;



    for(int i = 1; i <= k; i++) {

        if(id + i >= n) break;

        ans = min(ans, solve(id + i) + abs(arr[id + i] - arr[id]));

    }



        return dp[id] = ans;

}

int main()

{

    cin>>n>>k;



    arr.resize(n);

    for(int i=0;i<n;i++)

    {

        cin>>arr[i];

    }

    cout<<solve(0)<<endl;

}
