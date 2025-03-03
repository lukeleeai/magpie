#include <cstdio>

#include <cstring>

#define REP(i,n) for(int i=0; i<(int)(n); i++)



using namespace std;



int a[50000];

int b[50000];

int o[50000];



int rc[2][50000];



int main(){

  int rcs[2], q;



  while(scanf("%d%d%d", &rcs[0], &rcs[1], &q), rcs[0] + rcs[1] + q){

    REP(i,q) scanf("%d%d%d", &a[i], &b[i], &o[i]);



    int rrcc[2] = {0};

    int ans = 0;



    memset(rc[0], 0, sizeof(int) * rcs[0]);

    memset(rc[1], 0, sizeof(int) * rcs[1]);



    for(int i = q - 1; i >= 0; i--){

      if(!rc[a[i]][b[i]]){

	rc[a[i]][b[i]] = 1;

	rrcc[a[i]]++;

	if(o[i] == 1) ans += rcs[!a[i]] - rrcc[!a[i]];

      }

    }



    printf("%d\n", ans);

  }



  return 0;

}