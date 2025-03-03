#include<cstdio>

#include <algorithm>

using namespace std;



int x[200001];

int y[200001];



int main(){

    

    

    int n;

    scanf("%d",&n);

    

    for(int i=1;i<=n;i++){

        scanf("%d",&x[i]);

        y[i] = x[i];

    }

    

    sort(y+1,y+n+1);

    int med = y[n/2];

    

    for(int i=1;i<=n;i++){

        if(x[i] > med) printf("%d\n",med);

        else printf("%d\n",y[n/2+1]);

    }

    

    return 0;

}