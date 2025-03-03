#include<cstdio>

#include<algorithm>

int main(){

  int j=1,x,da[3][100001],fun[3][2];

  scanf("%d",&x);

  fun[0][0] = fun[1][0] = fun[2][0] = 0;

  for(int i=1;i<=x;i++){

    scanf("%d%d%d",&da[0][i],&da[1][i],&da[2][i]);

    fun[0][j] = std::max(fun[1][j^1],fun[2][j^1]) + da[0][i];

    fun[1][j] = std::max(fun[0][j^1],fun[2][j^1]) + da[1][i];

    fun[2][j] = std::max(fun[1][j^1],fun[0][j^1]) + da[2][i];

    j^=1;

  }

  j^=1;

  printf("%d\n",std::max(std::max(fun[0][j],fun[1][j]),fun[2][j]));

  

  return 0;

}
