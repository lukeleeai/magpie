#include <cstdio>

#include <cstring>

const int maxn=1e5+10;

char s[maxn];

int main() {

    scanf("%s",s+1);

    int len=strlen(s+1);

    if (len==1) {

        puts("1 1");

        return 0;

    }

    if (len==2 && s[1]==s[2]) {

        puts("1 2");

        return 0;

    }

    if (len==2 && s[1]!=s[2]) {

        puts("-1 -1");

        return 0;

    }

    bool f=false;

    for (int i=1;i<len-1;i++) {

        if (s[i]==s[i+1]||s[i]==s[i+2]) {

            printf("%d %d\n", i,i+2);

            f=true;

            break;

        }

    }

    if (!f) puts("-1 -1");

    return 0;

}