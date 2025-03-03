#include <cstdio>

using namespace std;

int main() {

    int n,k,x,y;

    scanf("%d%d%d%d",&n,&k,&x,&y);

    k--;



    int ans = 0;

    for(int i=0; i<n; i++) ans += (i<=k ? x : y);

    printf("%d\n",ans);

 

    return 0;

}
