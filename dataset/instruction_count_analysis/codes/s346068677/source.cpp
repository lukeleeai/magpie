#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

int n,k;

char a[15];

bool num[15];



bool check(int a) {

    int cnt=0;

    while (a) {

        if (!num[a%10]) return false;

        a/=10;

    }

    return true;

}



int main() {

    memset(num,1,sizeof(num));

    scanf("%d%d",&n,&k);

    int tmp;

    for (int i=1;i<=k;i++) {

        scanf("%d",&tmp);

        num[tmp]=0;

    }

    int ans=n;

    while (!check(ans)) ans++;

    printf("%d\n", ans);

    return 0;

}
