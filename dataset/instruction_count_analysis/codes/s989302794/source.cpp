#include<cstdio>

using namespace std;

int main(){

  int h,i,j;

  int n,m;

  while(scanf("%d%d",&n,&m),n||m){

    int s[100];

    for(i=0;i<m;++i)

      scanf("%d",s+i);

    h=1;

    for(i=0;i<n;++i){

      for(j=0;j<m;++j){

	int b;

	scanf("%d",&b);

	if(h){

	  s[j]-=b;

	  if(s[j]<0)

	    h=0;

	}

      }

    }

    if(h)

      puts("Yes");

    else

      puts("No");

  }

  return 0;

}