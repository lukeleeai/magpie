#include<cstdio>

#include<algorithm>

using namespace std;



int main(){

  int n,s,r[20200];



  while(scanf("%d%d",&n,&s),n){

    for(int i=0;i<n;i++)scanf("%d",r+i);

    sort(r,r+n);



    int ans = 0;

    for(int i=0;i<n;i++){

      ans += n - (upper_bound(r+i+1,r+n,s-r[i]) - r);

    }

    printf("%d\n",ans);

  }

}