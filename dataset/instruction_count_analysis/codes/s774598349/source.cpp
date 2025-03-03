#define loop(i, s, e) for(ll i = s;i < e;i++)



#include <iostream>

#include <iomanip>

#include <set>

#include <vector>

#include <queue>

#include <stack>

#include <utility>

#include <algorithm>

#include <map>

#include <cmath>

//#include "vector2d.cpp"



using namespace std;

//using namespace libcgl;

typedef long long signed ll;



long long n,c,v[200000],x[200000],s[2][200000],d[2][200000],ss[2][200000],dd[2][200000];



long long xx(int i) {

    if(i == 0) return 0;

    if(i < 0) return c-x[n+i+1];

    return x[i];

}





long long vv(int i) {

    if(i == 0) return 0;

    if(i < 0) return v[n+i+1];

    return v[i];

}



int main() {

    cin >> n >> c;

    loop(i,1,n+1) { cin >> x[i] >> v[i]; }



    loop(i,1,n+1) {

        s[0][i] = s[0][i-1] + vv(i) - (xx(i) - xx(i-1));

        d[0][i] = d[0][i-1] + vv(-i) - (xx(-i) - xx(-i+1));

        ss[0][i] = max(ss[0][i-1],s[0][i]);

        dd[0][i] = max(dd[0][i-1],d[0][i]);

        s[1][i] = s[1][i-1] + vv(i) - 2 * (xx(i) - xx(i-1));

        d[1][i] = d[1][i-1] + vv(-i) - 2 * (xx(-i) - xx(-i+1));

        ss[1][i] = max(ss[1][i-1],s[1][i]);

        dd[1][i] = max(dd[1][i-1],d[1][i]);

    }



    ll res = 0;

    loop(i,0,n+1) {

        res = max(res,max(ss[1][i] + dd[0][n-i],ss[0][i] + dd[1][n-i]));

    }

    cout << res << endl;

}


