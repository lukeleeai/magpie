#include <iostream>

#include <map>

#include <set>

#include <algorithm>

#include <stack>

#include <cstring>

using namespace std;



typedef long long ll;



int main() {

  int n;

  while (true) {

    scanf("%d", &n);

    if (n == 0) break;

    int tx[n], ty[n], bx[n], by[n];

    set <int> xy;

    for (int i = 0; i < n; i++) {

      scanf("%d %d %d %d", &tx[i], &ty[i], &bx[i], &by[i]);

      xy.insert(tx[i]);

      xy.insert(ty[i]);

      xy.insert(bx[i]);

      xy.insert(by[i]);

    }



    map <int, int> index;

    int cnt = 1;

    for (set <int>::iterator it = xy.begin(); it != xy.end(); it++, cnt++) {

      index[*it] = cnt;

    }

    ll field[cnt][cnt];

    memset(field, 0, sizeof(field));

    ll p = 1;

    for (int i = 0; i < n; i++) {

      for (int y = index[by[i]]; y < index[ty[i]]; y++) {

	for (int x = index[tx[i]]; x < index[bx[i]]; x++) {

	  field[x][y] |= p;

	}

      }

      p <<= 1;

    }



    int ans = 0;

    for (int i = 0; i < cnt; i++) {

      for (int j = 0; j < cnt; j++) {

	if (field[j][i] != -1) {

	  ans++;

	  ll ch = field[j][i];

	  int dx[] = {1, -1, 0, 0};

	  int dy[] = {0, 0, -1, 1};

	  stack <pair<int, int> > st;

	  st.push({j, i});

	  while (!st.empty()) {

	    pair<int, int> pos = st.top(); st.pop();

	    field[pos.first][pos.second] = -1;



	    for (int k = 0; k < 4; k++) {

	      pair<int, int> np = {pos.first+dx[k], pos.second+dy[k]};



	      if (np.first >= 0 && np.second >= 0 && np.first < cnt && np.second < cnt) {

		if (ch == field[np.first][np.second]) {

		  st.push(np);

		}

	      }

	    }

	  }

	}

      }

    }



    printf("%d\n", ans);

  }

}