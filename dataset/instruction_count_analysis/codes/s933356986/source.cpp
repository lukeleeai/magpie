#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int maxd =1e5+10;

char s[maxd];

int main()

{

    // freopen("a.in","r",stdin);

    // freopen("k.out","w",stdout);

    scanf("%s",s);

    for(int i=1;s[i];i++)

        if(s[i] == s[i-1]){

            printf("Bad");

            return 0;

        }

    printf("Good");

    return 0;

}  