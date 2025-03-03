#include <algorithm>

#include <bitset>

#include <complex>

#include <deque>

#include <exception>

#include <fstream>

#include <functional>

#include <iomanip>

#include <ios>

#include <iosfwd>

#include <iostream>

#include <istream>

#include <iterator>

#include <limits>

#include <list>

#include <locale>

#include <map>

#include <memory>

#include <new>

#include <numeric>

#include <ostream>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <stdexcept>

#include <streambuf>

#include <string>

#include <typeinfo>

#include <utility>

#include <valarray>

#include <vector>

#include <climits>



#define rep(i, m, n) for(int i=int(m);i<int(n);i++)

#define EACH(i, c) for (auto &(i): c)

#define all(c) begin(c),end(c)

#define EXIST(s, e) ((s).find(e)!=(s).end())

#define SORT(c) sort(begin(c),end(c))

#define pb emplace_back

#define MP make_pair

#define SZ(a) int((a).size())



//#define LOCAL 0

//#ifdef LOCAL

//#define DEBUG(s) cout << (s) << endl

//#define dump(x)  cerr << #x << " = " << (x) << endl

//#define BR cout << endl;

//#else

//#define DEBUG(s) do{}while(0)

//#define dump(x) do{}while(0)

//#define BR

//#endif





//改造

typedef long long int ll;

using namespace std;

#define INF (1 << 20)

#define INFl (ll)5e15

#define DEBUG 0 //デバッグする時1にしてね

#define dump(x)  cerr << #x << " = " << (x) << endl

#define MOD 1000000007

//ここから編集する





int main() {

    int N,K;

    cin >> N >> K;

    vector<pair<ll,ll> > ev;

    vector<ll> X,Y;



    rep(i,0,N){

        ll x,y;

        cin >> x >> y;

        ev.emplace_back(x,y);

        X.push_back(x);

        Y.push_back(y);

    }

    sort(all(X));

    sort(all(Y));

    ll ans = -1;

    rep(i,0,X.size()){

        rep(j,i+1,X.size()){

            rep(k,0,Y.size()){

                rep(l,k+1,Y.size()){

                    int cnt = 0;

                    for(pair<ll,ll> e : ev){

                        if(e.first >= X[i] && e.first <= X[j] && e.second >= Y[k] && e.second <= Y[l]){

                            cnt++;

                        }

                    }

                    if(cnt >= K){

                        if(ans == -1){

                            ans = (X[j] - X[i]) * (Y[l] - Y[k]);

                        }else{

                            ans = min(ans,(X[j] - X[i]) * (Y[l] - Y[k]));

                        }

                    }

                }

            }

        }

    }



    cout << ans << endl;



    return 0;

}
