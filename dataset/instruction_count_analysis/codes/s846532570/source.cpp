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



#define REP(i, m, n) for(int i=int(m);i<int(n);i++)

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



//ここから編集する





int main() {

    int N, K;

    cin >> N >> K;

    vector<int> px(N);

    vector<int> py(N);

    vector<int> x(N);

    vector<int> y(N);

    bool flag[50][50][50][50];

    REP(i, 0, N) {

        REP(j, 0, N) {

            REP(k, 0, N) {

                REP(l, 0, N) {

                    flag[i][j][k][l] = false;

                }

            }

        }

    }



    REP(i, 0, N) {

        cin >> px[i] >> py[i];

        x[i] = px[i];

        y[i] = py[i];

    }



    sort(x.begin(), x.end());

    sort(y.begin(), y.end());



    REP(i, 0, N) {

        REP(j, 0, N) {

            REP(k, 0, N) {

                REP(l, 0, N) {

                    int cnt = 0;

                    REP(m, 0, N) {

                        if (x[i] <= px[m] && px[m] <= x[k] && y[j] <= py[m] && py[m] <= y[l]) {

                            cnt++;

                        }

                    }

                    if (cnt >= K) {

                        flag[i][j][k][l] = true;

                    }





                }

            }

        }

    }

    ll ans = (ll)(x[N-1] - x[0]) * (ll)(y[N-1] - y[0]);

    REP(i, 0, N) {

        REP(j, 0, N) {

            REP(k, 0, N) {

                REP(l, 0, N) {

                    if (flag[i][j][k][l]) {

                        ans = min(ans,(ll)(x[k] - x[i]) * (ll)(y[l] - y[j]));

                    }

                }

            }

        }

    }



    cout << ans << endl;



    return 0;

}
