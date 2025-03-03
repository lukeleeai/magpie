#include<stdio.h>

#include<map>

#include<vector>

#include<map>

#include<algorithm>

using namespace std;

int p[200008];

int main(){

  int n;

  scanf("%d",&n);

  for(int i=1;i<=n;i++)

    scanf("%d",p+i);

  sort(p+1,p+n+1);

  int x=n/2;

  x=p[x+1]-p[x];

 // x--;

  printf("%d\n",x);

}
