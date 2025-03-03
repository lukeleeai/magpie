#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<math.h>

#include<complex>

#include<queue>

#include<deque>

#include<stack>

#include<map>

#include<set>

#include<bitset>

#include<functional>

#include<assert.h>

#include<numeric>

using namespace std;

#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )

#define rep(i,n) REP(i,0,n)

using ll = long long;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;



int main(){

    int n;cin>>n;

    string s;

    cin>>s;

    int ans = 0;

    rep(i,10)rep(j,10)rep(k,10){

        vector<char> v = {char('0'+i),char('0'+j),char('0'+k),'-'};

        int c=0;

        rep(l,n){

            if(s[l]==v[c])c++;

        }

        ans += c==3;

    }

    cout<<ans<<endl;

    return 0;

}