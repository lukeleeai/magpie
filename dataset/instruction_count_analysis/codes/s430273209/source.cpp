#include <cstdio>

#include <algorithm>

#include <cctype>

using namespace std;

inline int read(int f = 1, int x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

const int N = 2e5+5;

int n, a[N];

int main()

{

    n = read();

    for(int i = 1; i <= n; ++i) a[i] = read();

    sort(a+1, a+1+n); reverse(a+1, a+1+n);

    for(int i = 1; i <= n; ++i)

        if(i+1 > a[i+1])

        {

            int ans = 0;

            for(int j = i+1; a[j] == i; ++j) ans ^= 1;

            ans |= (a[i]-i)&1;

            puts(ans?"First":"Second");

            return 0;

        }

    return 0;

}