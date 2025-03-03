#include <cstdio>

int abs(int x) {

    return x > 0 ? x : -x;

}

int n, x[102], y[102], l[102], stdPoint, ansx, ansy, h;

bool check(){

    for(int i=1;i<=n;i++){

        int t=h-abs(ansx-x[i])-abs(ansy-y[i]);

        if(t<0)t=0;

        if(l[i]!=t)return false;

    }

    return true;

}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d%d%d", &x[i], &y[i], &l[i]);

        if (l[i])

            stdPoint = i;

    }

    for (int i = 0; i <= 100; i++) {

        for (int j = 0; j <= 100; j++) {

            ansx = i, ansy = j;

            h = l[stdPoint] + abs(x[stdPoint] - i) + abs(y[stdPoint] - j);

            if (check()){

                printf("%d %d %d\n",ansx,ansy,h);

                return 0;

            }

        }

    }

    return 0;

}