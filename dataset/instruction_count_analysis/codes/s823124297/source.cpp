#include <cstdio>

#include <cstring>

#include <cctype>

#include <cmath>

#include <algorithm>

using namespace std;

inline int read(int f = 1, int x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

const int N = 1e5+5;

int n, w[3][N], f[N], h[2];

int main()

{

    n = read();

    for(int i = 0; i < 3; ++i)

        for(int j = 1; j <= n; ++j) 

            w[i][j] = read();

    for(int i = 1; i <= n; ++i)

    {

        int a = w[0][i], b = w[1][i], c = w[2][i];

        if(abs(a-b) > 1||abs(b-c) > 1||b%3 != 2||(b%6&i&1)) return puts("No"), 0;

        f[i] = b/3+1, h[i&1] ^= a > c;

    }

    for(int i = 1; i <= n; ++i)

        while(f[i] != i) h[i&1^1] ^= 1, swap(f[i], f[f[i]]);

    puts(h[0]||h[1]?"No":"Yes");

    return 0;

}