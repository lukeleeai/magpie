

#include <cstdio>

#include <cstring>

#include <algorithm>



using namespace std;



char s[110][110];

int H, W, f[110][110];



int main() {

    scanf("%d%d", &H, &W);

    for (int i = 1; i <= H; ++i) scanf("%s", s[i] + 1);



    f[1][1] = s[1][1] == '#';

    for (int i = 2; i <= W; ++i)

        f[1][i] = f[1][i - 1] + (s[1][i - 1] == '.' && s[1][i] == '#');

    for (int i = 2; i <= H; ++i)

        f[i][1] = f[i - 1][1] + (s[i - 1][1] == '.' && s[i][1] == '#');

    for (int i = 2; i <= H; ++i)

        for (int j = 2; j <= W; ++j)

            f[i][j] = min(f[i - 1][j] + (s[i - 1][j] == '.' && s[i][j] == '#'),

                          f[i][j - 1] + (s[i][j - 1] == '.' && s[i][j] == '#'));

    printf("%d\n", f[H][W]);

    return 0;

}