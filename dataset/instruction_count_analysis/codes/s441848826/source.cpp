#include"stdc++.h"



using namespace std;

inline void read(long long &x) {

    char ch;

    bool flag = false;

    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;

    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());

    x = flag ? -x : x;

}

inline void write(long long x) {

    static const long long maxlen = 100;

    static char s[maxlen];

    if (x < 0) {   putchar('-'); x = -x;}

    if (!x) { putchar('0'); return; }

    long long len = 0; for (; x; x /= 10) s[len++] = x % 10 + '0';

    for (long long i = len - 1; i >= 0; --i) putchar(s[i]);

}



inline void read(int &x){

    char ch;

    bool flag = false;

    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;

    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());

    x = flag ? -x : x;

}



const int MAXN =101000;



int n;

int a[ MAXN ];

bool f[ MAXN ];



int main(){

    read(n);

    for (int i=1;i<=n;i++)

        read(a[i]);

    f[0]=1;

    for (int i=1;i<=n;i++)

        for (int j=MAXN-1;j>=a[i];j--)

            f[j]=f[j]||f[j-a[i]];

    for (int i=MAXN-1;i>=0;i--)

        if ( (f[i]) && ( i%10!=0) )

            {

                printf("%d\n",i);

                return 0;

            }

    puts("0");

    return 0;

}
