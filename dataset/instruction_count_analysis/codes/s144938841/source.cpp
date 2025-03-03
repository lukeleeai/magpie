#include <algorithm>

#include <cctype>

#include <cstring>

#include <cstdio>

using namespace std;

inline int read(int f = 1, int x = 0, char ch = ' ')

{

    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;

    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();

    return f*x;

}

int a, b;

int main()

{

    a = read(), b = read(); if(a > b) swap(a, b);

    if(a <= 0&&b >= 0) puts("Zero");

    else if(a > 0) puts("Positive");

    else if((b-a+1)&1) puts("Negative");

    else puts("Positive");

    return 0;

}