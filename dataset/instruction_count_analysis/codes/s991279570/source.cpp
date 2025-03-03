#include <cstdio>

#include <queue>

#include <cstring>



using namespace std;



struct state {

  int x, y;

  int cost;

  bool operator>(const state& e) const {

    return cost > e.cost;

  }

};



int w, h;

char a[555][555];



int cost[555][555];

int prevx[555][555], prevy[555][555];

int done[555][555];



const int MAX_N = 555*555;

struct uni {

  int p[MAX_N];

  uni(){init();}

  void init(){ memset(p,-1,sizeof(p)); }

  int root(int a) {

    return p[a]<0?a:(p[a]=root(p[a]));

  }

  bool find(int a,int b){ return root(a) == root(b); }

  bool merge(int a,int b) {

    a = root(a);

    b = root(b);

    if( a == b ) return false;

    p[a] += p[b];

    p[b] = a;

    return true;

  }

  int size(int a){ return -p[root(a)]; }

};



uni u;

int ans1[555][555];

int ans2[555][555];



int main(void) {

  scanf("%d%d", &h, &w);

  int sx, sy;

  for (int i = 0; i < h; i++) {

    for (int j = 0; j < w; j++) {

      scanf(" %c", a[i]+j);

      if (a[i][j] == '#') {

        sx = j;

        sy = i;

      }

    }

  }



  for (int i = 0; i < h; i++) {

    for (int j = 0; j < w; j++) {

      printf("%c", i == 0 || a[i][j] == '#' || (i!=h-1&&j%2 == 0) ? '#' : '.');

    }

    puts("");

  }



  puts("");

  

  for (int i = 0; i < h; i++) {

    for (int j = 0; j < w; j++) {

      printf("%c", i == h-1 || a[i][j] == '#' || (i!=0&&j%2 == 1) ? '#' : '.');

    }

    puts("");

  }

  

  return 0;

}
