#include<cstdio>
#include<cmath>
using namespace std;
int main(){
  int i,n;
  int a[]={0,1,2,3,5,7,8,9};
  while(scanf("%d",&n)&&n){
    for(i=0;pow(8,i)<=n;i++);
    for(i--;i>=0;i--){
      printf("%d",a[n/(int)pow(8,i)]);
      n%=(int)pow(8,i);
    }
    puts("");
  }
  return 0;
}
