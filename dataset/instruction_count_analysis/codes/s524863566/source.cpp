#include <iostream>

#include <string>

#include <algorithm>

#include <cmath>

#include <cstdlib>

#include <vector>

#include <map>

#include <queue> 

#include <stack>

#include <set>

#include <list>



using namespace std;

typedef long long ll;

#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))

#define all(x) x.begin(),x.end()





int main()

{

   ll a,b,c,x,y;

    cin>>a>>b>>c>>x>>y;

    ll z=max(x,y);

    ll res = 1e18;

    for(int i = 0; i <= z; ++i){

    	ll tmp = c*i*2 + max(0LL,(x-i)*a)+max(0LL, (y-i)*b);

    	res=min(res,tmp);

    }

    cout<<res<<endl;

}