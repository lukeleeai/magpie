#include<cstdio>

using namespace std;

int H,W,K;

char t[1001][1001],ch;

int J[1001][1001];

int O[1001][1001];

int I[1001][1001];

int ay,ax,by,bx;

int main(){

  scanf("%d %d %d",&H,&W,&K);

  scanf("%c",&ch);

  for(int i=1;i<=H;i++){

    for(int j=1;j<=W;j++){

      scanf("%c",&t[i][j]);

      J[i][j]=(t[i][j]=='J'?1:0)+J[i-1][j]+J[i][j-1]-J[i-1][j-1];

      O[i][j]=(t[i][j]=='O'?1:0)+O[i-1][j]+O[i][j-1]-O[i-1][j-1];

      I[i][j]=(t[i][j]=='I'?1:0)+I[i-1][j]+I[i][j-1]-I[i-1][j-1];

    }

    scanf("%c",&ch);

  }

  for(int i=0;i<K;i++){

    scanf("%d %d %d %d",&ay,&ax,&by,&bx);

    printf("%d ",J[by][bx]-J[ay-1][bx]-J[by][ax-1]+J[ay-1][ax-1]);

    printf("%d ",O[by][bx]-O[ay-1][bx]-O[by][ax-1]+O[ay-1][ax-1]);

    printf("%d\n",I[by][bx]-I[ay-1][bx]-I[by][ax-1]+I[ay-1][ax-1]);

  }

  

  return 0;

}