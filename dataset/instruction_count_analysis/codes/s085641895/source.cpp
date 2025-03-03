#include"stdc++.h"

#define ll long long

#define mod 1000000007

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define v(x) vector<int> x;

#define all(x) x.begin(),x.end()

#define s(x,n) memset(x,n,sizeof(x));

#define pb(x) push_back(x)



using namespace std;

int main()

{   fast 

    ll a,b;

    set<ll> s;

    s.insert(1);s.insert(2);s.insert(3);

    cin>>a>>b;

    s.erase(a);s.erase(b);

    auto it=s.begin();

    cout<<*it<<"\n";

    return 0;

}