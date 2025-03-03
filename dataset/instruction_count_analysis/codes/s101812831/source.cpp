#include<cstdio>

int main(){

  int k,s;

  scanf("%d%d",&k,&s);

  int re=(s+2)*(s+1);

  if(k<=s) re-=3*(s-k+1)*(s-k);

  if(2*k<=s) re+=3*(s-2*k)*(s-2*k-1);

  printf("%d\n",re/2);

  return 0;

}
