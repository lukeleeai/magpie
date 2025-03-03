#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

using namespace std;

int main()

{

    char s[16], d[26];

    scanf("%s", s);

    for(char* p=d, c='A'; c<='Z'; ++c) if (!strchr("ACGT", c)) *p++=c;



    int res=0;

    for(char* p=strtok(s, d); p; p=strtok(NULL, d)) res=max(res, (int)strlen(p));

    printf("%d\n", res);

}