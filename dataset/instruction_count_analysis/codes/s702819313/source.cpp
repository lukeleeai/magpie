#include<cstdio>

int main(){

  int i;

  int a[11]={1},n;

  char s[9]="01235789";

  for(i=1;i<11;++i)

    a[i]=a[i-1]*8;

  while(scanf("%d",&n),n){

    for(i=0;a[i]<=n;++i);

    for(--i;i>=0;--i){

      printf("%c",s[n/a[i]]);

      n%=a[i];

    }

    puts("");

  }

  return 0;

}