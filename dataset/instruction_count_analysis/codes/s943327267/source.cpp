#include<algorithm>

#include<cstring>

#include<cstdio>

#define INF 1<<28

using namespace std;



int sx, sy, gx, gy;

int dx[5][1111], dy[5][1111], dn[5];

int memo[5][5][1111];

int a, b;



int solve(int k, int t, int q){



  if(k == 4) return abs(dx[t][q]-gx) + abs(dy[t][q]-gy);

  if(memo[k][t][q]) return memo[k][t][q];



  int ans = INF, d = (t+1)%5, s;

  for(int i=0;i<dn[d];i++){

    if(!k) s = abs(sx-dx[d][i]) + abs(sy-dy[d][i]);

    else s = abs(dx[t][q]-dx[d][i]) + abs(dy[t][q]-dy[d][i]);

    ans = min(ans, solve(k+1, d, i) + s);

  }



  return memo[k][t][q] = ans;

}



int main(){



  int w,h;

  char c;



  while(true){

    scanf("%d %d", &w, &h);

    if(!w && !h) break;



    memset(dn, 0, sizeof(dn));



    for(int i=0;i<h;i++){

      for(int j=0;j<w;j++){

	scanf(" %c", &c);

	if(c == 'S') sx = j, sy = i;

	else if(c == 'G') gx = j, gy = i;

	else if(c != '.') dx[c-'1'][dn[c-'1']] = j, dy[c-'1'][dn[c-'1']] = i, dn[c-'1']++;

      }

    }

    

    b = INF;

    for(int i=0;i<5;i++){

      memset(memo, 0, sizeof(memo));

      if(b > solve(0,i,0)) a = i, b = solve(0,i,0);

    }



    if(b == INF) printf("NA\n");

    else printf("%d %d\n", a+1, b);



  }

}