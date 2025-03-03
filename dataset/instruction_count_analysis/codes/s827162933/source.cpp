#include<cstdio>

#include<algorithm>

using namespace std;



int rec[100100];



int main()

{

    int n,k,i;

    int ans=0;

    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++)

        scanf("%d",rec+i);

    sort(rec,rec+n);

    for(i=0;i<k;i++)

        ans+=rec[i];

    printf("%d\n",ans);

    return 0;

}
