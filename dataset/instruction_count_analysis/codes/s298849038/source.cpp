#include <cstdio>

#include <algorithm>



using namespace std;



int C[10][10];

int h, w;



int main() {

    scanf("%d%d", &h, &w);

    for (int i = 0; i < 10; i++)

        for (int j = 0; j < 10; j++) scanf("%d", &C[i][j]);

    for (int k = 0; k < 10; k++)

        for (int i = 0; i < 10; i++)

            for (int j = 0; j < 10; j++) C[i][j] = min(C[i][j], C[i][k] + C[k][j]);

    int ans = 0;

    for (int i = 0, x; i < h; i++)

        for (int j = 0; j < w; j++) scanf("%d", &x), ans += (x==-1)?0:C[x][1];

    printf("%d\n", ans);

    return 0;

}