#include<cstdio>

#include<algorithm>



int main(){

  int s,k;

  long long st[100001],p[100001];

  scanf("%d%d",&s,&k);

  for(int i=1;i<=s;i++){

    scanf("%lld",&st[i]);

  }

  p[0]=0;

  p[1]=0;

  p[2]=(st[2]-st[1] < 0) ? st[1]-st[2] : st[2]-st[1];

  for(int i=3;i<=s;i++){

    p[i] = 1000000001;

  }

  for(int i=3;i<=s;i++){

    for(int j=1;j<=k;j++){

      if(i-j>=1){

	long long tmp;

	tmp = (st[i]-st[i-j] < 0) ? st[i-j]-st[i] : st[i]-st[i-j];

	if(p[i] > p[i-j]+tmp){

	  p[i] = p[i-j]+tmp;

	}

	if(tmp == 0) break;

      }else{

	break;

      }

    }

  }

  printf("%lld\n",p[s]);

  return 0;

}
