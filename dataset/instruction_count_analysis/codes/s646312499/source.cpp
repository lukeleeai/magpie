#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

char c[100007];

int main(){

    scanf("%s",c);int l=strlen(c),g=0;

    for(int i=0;i<l;++i)if(c[i]=='g')g++;

    printf("%d\n",min(l/2,g)-min(l-l/2,l-g));

    return 0;

}