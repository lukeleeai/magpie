#include <algorithm>

#include <iostream>

#include <vector>



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;



#define MOD 1000000007

#define REP(i, N) for (int i = 0; i < N; ++i)

#define REP1(i, N) for (int i = 1; i <= N; ++i)

#define RREP(i, N) for (int i = N - 1; i >= 0; --i)

#define ALL(a) a.begin(), a.end()



int main() {

  int N;

  cin >> N;

  vector<int> A(N);

  REP(i, N) cin >> A[i];

  int m_cnt = 0;

  int a_min = 1e9 + 1;

  ll abs_sum = 0;

  REP(i, N) {

    if (A[i] < 0) m_cnt++;

    if (abs(A[i]) < a_min) a_min = abs(A[i]);

    abs_sum += abs(A[i]);

  }

  if (m_cnt % 2 == 0)

    cout << abs_sum << endl;

  else

    cout << abs_sum - 2ll * a_min << endl;

  return 0;

}