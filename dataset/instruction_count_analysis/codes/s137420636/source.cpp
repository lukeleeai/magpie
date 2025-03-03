#include <iostream>

#include <vector>

#include <deque>

#include <math.h>

#include <set>

#include <iomanip>

#include <time.h>

#include <list>

#include <stdio.h>

#include <queue>

#include <map>

#include <algorithm>

#include <assert.h>

#include <memory.h>



#define mk make_pair

#define sc second

#define fr first

#define pb emplace_back

#define all(s) s.begin(), s.end()

#define sz(s) ( (int)s.size() )



using namespace std;



const int N = 5e3 + 5, M = 205, inf = -1e9 - 7;



int n, m, ar[N][M], cur[M], numlog[N], table[23][N][202];



long long  pref[N], ans;



inline int max(int a, int b)

{

    return a > b ? a : b;

}

inline int min(int a, int b)

{

    return a > b ? b : a;

}





void build(int pos)

{

      for(int i = 0; i <= numlog[n]; i ++)

      {

            for(int j = 1; j <= n; j ++)

            {

                  if(i == 0)

                  {

                        table[i][j][pos] = ar[j][pos];

                        continue;

                  }

                  int d = min(j + (1 << (i - 1)), n);

                  table[i][j][pos] = max(table[i - 1][j][pos], table[i - 1][d][pos]);

            }

      }

}



int get(int l, int r, int pos)

{

      int curlog = numlog[r - l + 1];

      return max(table[curlog][l][pos], table[curlog][r - (1 << curlog) + 1][pos]);

}



void Compute(int l, int r, int opl, int opr)

{

      if(l > r) return ;

      int md = (l + r) >> 1, opt = l;

      long long c = 0;

      for(int i = opl; i <= min(opr, md); i ++)

      {

            long long res = 0;



            for(int j = 1; j <= m; j ++)

                  res += get(i, md, j);



            res -= pref[md] - pref[i];



            if(res > c)

            {

                  c = res;

                  opt = i;

            }

      }

      ans = max(ans, c);

      Compute(l, md - 1, opl, opt);

      Compute(md + 1, r, opt, opr);

}



main ()

{

    cin >> n >> m;



  for(int i = 2; i <= n; i ++)

        numlog[i] = numlog[i / 2] + 1;



    for (int i = 2; i <= n; i++)

        scanf("%lld", &pref[i]), pref[i] += pref[i - 1];



    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= m; j++)

            scanf("%d", &ar[i][j]);



      for(int i = 1; i <= m; i ++)

            build(i);



    Compute( 1, n, 1, n );



    cout << ans << endl;

}
