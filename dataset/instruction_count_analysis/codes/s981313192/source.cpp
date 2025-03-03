#include <stdio.h>



int b[2000][1000];

int s[2001][1001];



#define calc(x, y, w, h) (s[(x)+(w)][(y)+(h)] - s[(x)+(w)][(y)] - s[(x)][(y)+(h)] + s[(x)][(y)])



int main(void){

    int n, k;

    int x, y;

    char c;

    scanf("%d %d", &n, &k);

    for(long i=0; i<n; i++){

        scanf("%d %d %c", &x, &y, &c);

        y %= 2*k;

        if(c=='W'){

            x += k;

        }

        if(y>=k){

            y-=k;

            x+=k;

        }

        x %= 2*k;

        b[x][y]++;

    }

    s[1][1] = b[0][0];

    for(long i=1; i<2*k; i++){

        s[i+1][1] = s[i][1] + b[i][0];

    }

    for(long i=1; i<k; i++){

        s[1][i+1] = s[1][i] + b[0][i];

    }

    for(long x=1; x<2*k; x++){

        for(long y=1; y<k; y++){

            s[x+1][y+1] = b[x][y] + s[x][y+1] + s[x+1][y] - s[x][y];

        }

    }

    long max = 0;

    for(long x=0; x<k; x++){

        for(long y=0; y<k; y++){

            long t = calc(x, y, k, k-y);

            t += calc(0, 0, x, y);

            t += calc(x+k, 0, k-x, y);

            t = t<n/2 ? n-t : t;

            max = t>max ? t : max;

        }

    }

    printf("%ld", max);

    return 0;

}
