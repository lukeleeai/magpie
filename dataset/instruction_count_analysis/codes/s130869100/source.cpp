#include"stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

int  main(){

    std::ios::sync_with_stdio(false);

   cin.tie(0);

    ll a,b,x;

    cin>>a>>b>>x;

    a!=0?cout << b / x - (a - 1) / x << endl:cout << b / x + 1 << endl;

return 0;

}
