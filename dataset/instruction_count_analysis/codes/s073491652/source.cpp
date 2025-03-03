#include<cstdio>

using namespace std;

int n,m,a[105],sum=0;

int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d",&a[i]);

        sum+=a[i];

    }

    scanf("%d",&m);

    while(m--){

        int p,x;

        scanf("%d%d",&p,&x);

        printf("%d\n",sum-a[p]+x);

    }

    return 0;

}