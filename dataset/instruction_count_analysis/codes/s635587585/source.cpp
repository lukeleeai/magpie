#include <algorithm>

#include <vector>

#include <cfloat>

#include <string>

#include <cmath>

#include <set>

#include <cstdlib>

#include <map>

#include <ctime>

#include <iomanip>

#include <functional>

#include <deque>

#include <iostream>

#include <cstring>

#include <queue>

#include <cstdio>

#include <stack>

#include <climits>

#include <sys/time.h>

#include <cctype>



using namespace std;



typedef long long ll;



#define MAX_N 10000



class point {

public:

  int x, y;

  point (int _x = 0, int _y = 0) {

    x = _x;

    y = _y;

  }

  bool operator < (const point &s) const {

    return (x < s.x) || (x == s.x && y < s.y);

  }

};



bool samep(point a, point b) {

  return a.x == b.x && a.y == b.y;

}



class line {

public:

  point p1, p2;

  line (point _p1 = point(0, 0), point _p2 = point(0, 0)) {

    p1 = _p1;

    p2 = _p2;

  }

  bool operator < (const line &l) const {

    return (p1 < l.p1) || (samep(p1, l.p1) && p2 < l.p2);

  }

};



bool samel(line a, line b) {

  return (samep(a.p1, b.p1) && samep(a.p2, b.p2)) || (samep(a.p1, b.p2) && samep(a.p2, b.p1));

}



int main() {

  int n;

  while (true) {

    cin >> n;

    if (n == 0) break;



    vector <line> memo;

    for (int i = 0; i < n; i++) {

      int tx, ty, bx, by;

      cin >> tx >> ty >> bx >> by;

      point p[4] = {point(tx, ty), point(bx, ty), point(bx, by), point(tx, by)};

      for (int j = 0; j < 4; j++) memo.push_back(line(p[j], p[(j+1)%4]));

    }



    for (int i = 0; i < memo.size(); i++) {

      for (int j = i+1; j < memo.size(); j++) {

	line l1 = memo[i], l2 = memo[j];

	if (samel(l1, l2)) {

	  memo.erase(memo.begin()+j); j--; continue; // ?????´?????????????¶????

	}

	// ????????????????????????????????????

	if (samep(l1.p1, l2.p1) || samep(l1.p1, l2.p2) ||

	    samep(l1.p2, l2.p1) || samep(l1.p2, l2.p2)) continue;



	if (l1.p1.x == l1.p2.x && l2.p1.y == l2.p2.y) swap(l1, l2);

	if (l1.p1.y == l1.p2.y && l2.p1.x == l2.p2.x) {

	  // ??´???????????????????????§

	  if (l1.p1.x > l1.p2.x) swap(l1.p1, l1.p2);

	  if (l2.p1.y > l2.p2.y) swap(l2.p1, l2.p2);

	  point z = point(-1, -1);

	  // ?????¨???????????????

	  if (l2.p1.y < l1.p1.y && l1.p1.y < l2.p2.y && l1.p1.x == l2.p1.x) {

	    z = point(l1.p1.x, l1.p1.y);

	  }else if (l2.p1.y < l1.p1.y && l1.p1.y < l2.p2.y && l1.p2.x == l2.p1.x) {

	    z = point(l1.p2.x, l1.p1.y);

	  }else if (l1.p1.x < l2.p1.x && l2.p1.x < l1.p2.x && l1.p1.y == l2.p1.y) {

	    z = point(l2.p1.x, l2.p1.y);

	  }else if (l1.p1.x < l2.p1.x && l2.p1.x < l1.p2.x && l1.p1.y == l2.p2.y) {

	    z = point(l2.p2.x, l2.p2.y);

	  }

	  if (!samep(z, point(-1, -1))) {

	    point p[4] = {l1.p1, l1.p2, l2.p1, l2.p2};

	    for (int k = 0; k < 4; k++) {

	      if (samep(z, p[k])) continue;

	      memo.push_back(line(z, p[k]));

	    }

	    memo.erase(memo.begin()+j);

	    memo.erase(memo.begin()+i);

	    j = i;

	  }else {

	    // ?????¨???????????????

	    if (l1.p1.x < l2.p1.x && l2.p1.x < l1.p2.x &&

		l2.p1.y < l1.p1.y && l1.p1.y < l2.p2.y) {	    

	      z = point(l2.p1.x, l1.p1.y);



	      point p[4] = {l1.p1, l1.p2, l2.p1, l2.p2};

	      for (int k = 0; k < 4; k++) {

		memo.push_back(line(z, p[k]));

	      }

	      memo.erase(memo.begin()+j);

	      memo.erase(memo.begin()+i);

	      j = i;

	    }

	  }

	}else {

	  // ??????????????????????????§

	  if (l1.p1.x == l1.p2.x && l1.p1.x == l2.p1.x) {

	    if (l1.p1.y > l1.p2.y) swap(l1.p1, l1.p2);

	    if (l2.p1.y > l2.p2.y) swap(l2.p1, l2.p2);

	    if ((l1.p1.y < l2.p1.y && l2.p1.y < l1.p2.y) ||

		(l1.p1.y < l2.p2.y && l2.p2.y < l1.p2.y)) {



	      int y[4] = {l1.p1.y, l1.p2.y, l2.p1.y, l2.p2.y};

	      sort(y, y+4);

	      for (int k = 0; k < 3; k++) {

		memo.push_back(line(point(l1.p1.x, y[k]), point(l1.p1.x, y[k+1])));

	      }

	      memo.erase(memo.begin()+j);

	      memo.erase(memo.begin()+i);

	      j = i;

	    }

	  }else if (l1.p1.y == l1.p2.y && l1.p1.y == l2.p1.y) {

	    if (l1.p1.x > l1.p2.x) swap(l1.p1, l1.p2);

	    if (l2.p1.x > l2.p2.x) swap(l2.p1, l2.p2);

	    if ((l1.p1.x < l1.p2.x && l1.p2.x < l1.p2.x) ||

		(l1.p1.x < l1.p1.x && l1.p1.x < l1.p2.x)) {

	      int x[4] = {l1.p1.x, l1.p2.x, l2.p1.x, l2.p2.x};

	      sort(x, x+4);

	      for (int k = 0; k < 3; k++) {

		memo.push_back(line(point(x[k], l1.p1.y), point(x[k+1], l1.p1.y)));

	      }

	      memo.erase(memo.begin()+j);

	      memo.erase(memo.begin()+i);

	      j = i;

	    }

	  }

	}

      }

    }



    vector <int> graph[MAX_N];



    set <line> dup;

    map <point, int> index;

    int cnt = 0;

    for (int i = 0; i < memo.size(); i++) {

      point p1 = memo[i].p1, p2 = memo[i].p2;

      map <point, int>::iterator it1 = index.find(p1), it2 = index.find(p2);

      if (dup.find(line(p1, p2)) != dup.end() ||

	  dup.find(line(p2, p1)) != dup.end()) continue;

      if (it1 == index.end() && it2 == index.end()) {

	index[p1] = cnt;

	index[p2] = cnt+1;

	graph[cnt].push_back(cnt+1);

	graph[cnt+1].push_back(cnt);

	cnt += 2;

      }else if (it1 == index.end()) {

	index[p1] = cnt;

	graph[cnt].push_back((*it2).second);

	graph[(*it2).second].push_back(cnt);

	cnt++;

      }else if (it2 == index.end()) {

	index[p2] = cnt;

	graph[cnt].push_back((*it1).second);

	graph[(*it1).second].push_back(cnt);

	cnt++;

      }else {

	graph[(*it1).second].push_back((*it2).second);

	graph[(*it2).second].push_back((*it1).second);

      }

      dup.insert(line(p1, p2));

    }





    int ans;

    int viscnt[MAX_N];

    memset(viscnt, 0, sizeof(viscnt));

    queue <int> que;

    que.push(0);

    bool ok = false;

    int graphn = 0;

    // ??°???????????°?????°??????

    while (!ok) {

      graphn++;

      while (!que.empty()) {

    	int p = que.front(); que.pop();

    	for (int i = 0; i < graph[p].size(); i++) {

    	  int np = graph[p][i];

    	  if (!viscnt[np]) {

    	    viscnt[np]++;

    	    que.push(np);

    	    continue;

    	  }

    	}

      }

      ok = true;

      for (int i = 0; i < cnt; i++) {

    	if (!viscnt[i]) {

    	  que.push(i);

    	  ok = false;

    	  break;

    	}

      }

    }



    ans = 0;



    int hen = dup.size(), tyouten = cnt;    

    ans = 1*graphn+hen-tyouten+1; // ?????????????????????????????????(??¢)?????°????±???????

    cout << ans << endl;

 }

}