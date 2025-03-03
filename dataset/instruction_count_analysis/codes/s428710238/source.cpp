#include"stdc++.h"



#define maxn 100005



using namespace std;

typedef long long ll;



int main(){



  ios_base::sync_with_stdio(0);



  int L;

  cin >> L;

  L--;



  cout << 20 << ' ';



  vector < int > u, v, c;

  #define add(x, y, z) {u.push_back(x); v.push_back(y); c.push_back(z);}



  int i;



  for (i = 19; i > 0 && L > (1 << (19 - i)); --i){

    add(i, i + 1, 0);

    add(i, i + 1, (1 << (19 - i)));

    L -= (1 << (19 - i));

  }



  if (i) add(i, i + 1, 0);



  int val = (1 << (19 - i));



  for (int is = 0; is <= 20; ++is) {

    if ((L >> is)&1) {

      add(max(i, 1), 20 - is, val);

      val += (1 << is);

    }

  }



  while ((--i) > 0)

    add(i, i + 1, 0);



  cout << u.size() << '\n';



  for (int i = 0; i < u.size(); ++i)

    cout << u[i] << ' ' << v[i] << ' ' << c[i] << '\n';

  return 0;



}
