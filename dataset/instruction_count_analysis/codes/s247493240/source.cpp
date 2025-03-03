#include<stdio.h>

#include<algorithm>

using namespace std;

int main(){

    int N,L[220];

    scanf("%d",&N);

    for(int i=0;i<N*2;i++)

        scanf("%d",&L[i]);

    sort(L,L+2*N,greater<int>());

    int ans=0;

    for(int i=1;i<2*N;i+=2)

        ans+=L[i];

    printf("%d\n",ans);

    return 0;

}