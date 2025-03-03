#include<cstdio>

using namespace std;



main(){

  int n,s;

  while(true){

    scanf("%d%d",&n,&s);

    if (n==0)break;

    int r[101]={0};

    for(int i=0;i<n;i++){

      int tmp;scanf("%d",&tmp);r[tmp]++;

    }

    int ans = 0;

    for(int i=0;i<101;i++){

      if (i+i > s && r[i])ans += (r[i]*(r[i]-1))/2;

      for(int j=i+1;j<101;j++){

	if (i+j > s)ans += r[i]*r[j];

      }

    }

    printf("%d\n",ans);

  }

}