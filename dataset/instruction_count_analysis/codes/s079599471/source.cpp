# include <stdio.h>

int n,m;

int a[2521],b[2521],c[2521];

long long INF = 1000000001;

long long INFLL = (long long)INF * INF;

 

long long dist[1252];

int over[1252];

int main(void){

    // Here your code !

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){

        scanf("%d%d%d",&a[i],&b[i],&c[i]);

        a[i]--;b[i]--;

    }

    for(int i=0;i<n;i++)dist[i] = -INFLL;

    dist[0] = 0;

    for(int k=0;k<=(2 * n - 2);k++)for(int i=0;i<m;i++){

        if(dist[a[i]] != -INFLL && dist[b[i]] < dist[a[i]] + c[i]){

            dist[b[i]] = dist[a[i]] + c[i];

            if(k == 2*n - 2){

                over[b[i]] = 1;

            }

        }

    }

    if(over[n-1])printf("inf\n");

    else printf("%lld\n",dist[n-1]);

    return 0;

}