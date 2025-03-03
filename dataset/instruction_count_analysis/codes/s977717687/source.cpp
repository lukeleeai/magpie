#include <cstdio>

int k,ans=1;

int main(){

    scanf("%d",&k);

    for(int n=7;n%k;n=(n*10ll+7ll)%k,ans++) if(ans>=k){puts("-1");return 0;}

    printf("%d\n",ans);

    return 0;

}