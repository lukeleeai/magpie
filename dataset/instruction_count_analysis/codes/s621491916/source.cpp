#include <cstdio>

#include <cstring>

#include <vector>

#include <algorithm>



using namespace std;



typedef pair<int, int>P;

const int INF = 1<<29;

int N,M;

int dp[256][128][16];

vector<P> s[151];



int main(){

  while(scanf("%d%d", &N,&M) && N||M){

    for(int i=0;i<151;i++) s[i].clear();

    for(int i=0;i<151;i++) for(int j=0;j<76;j++) for(int k=0;k<11;k++) dp[i][j][k] = INF;

    for(int i=0;i<N;i++){

      int k;

      scanf("%d", &k);

      for(int j=0;j<k;j++){

	int x,d; scanf("%d%d", &x,&d);

	s[i].push_back(P(x,d));

      }

    }

    

    for(int i=0;i<s[0].size();i++) dp[0][M][i] = min(dp[0][M][i], 0);

    if(M) for(int i=0;i<s[1].size();i++) dp[1][M-1][i] = min(dp[1][M-1][i], 0);

    /*    for(int m=0;m<=M;m++){

      for(int i=0;i<N;i++){

	for(int j=0;j<s[i].size();j++) printf("%d ", dp[i][m][j]);

	puts("");

      }puts("");

      } */   



    for(int i=0;i<N-1;i++){

      for(int j=0;j<s[i].size();j++){

	for(int m=0;m<=M;m++){

	  if(dp[i][m][j] == INF) continue;

	  for(int k=0;k<s[i+1].size();k++){

	    dp[i+1][m][k] = min(dp[i+1][m][k],

				dp[i][m][j]+(s[i+1][k].second+s[i][j].second)*abs(s[i+1][k].first-s[i][j].first));

	  }

	  if(i+2 < N && m) for(int k=0;k<s[i+2].size();k++){

	      dp[i+2][m-1][k] = min(dp[i+2][m-1][k],

				    dp[i][m][j]+(s[i+2][k].second+s[i][j].second)*abs(s[i+2][k].first-s[i][j].first));

	    }

	}

      }

      //      printf("%d\n" ,i);

      /*      for(int m=0;m<=M;m++){

	for(int i=0;i<N;i++){

	  for(int j=0;j<s[i].size();j++) printf("%d ", dp[i][m][j]);

	  puts("");

	}puts("");

      }*/

    }

    /*    for(int m=0;m<=M;m++){

      for(int i=0;i<N;i++){

	for(int j=0;j<s[i].size();j++) printf("%d ", dp[i][m][j]);

	puts("");

      }puts("");

      }*/

    

    int res = INF;

    for(int i=0;i<s[N-1].size();i++) for(int m=0;m<=M;m++) res = min(res, dp[N-1][m][i]);

    for(int i=0;i<s[N-2].size();i++) for(int m=1;m<=M;m++) res = min(res, dp[N-2][m][i]);

    printf("%d\n", res);

  }

  return 0;

}