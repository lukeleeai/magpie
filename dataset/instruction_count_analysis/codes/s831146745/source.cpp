#include <cstdio>

using namespace std;

int main(){

  int k,s,c,i;

  while(1){

    scanf("%d",&k);

    if (!k) break;

    for(i=0,s=0;i<k*(k-1)/2;i++)

      scanf("%d",&c),s+=c;

    printf("%d\n",s/(k-1));

  }

  return 0;

}