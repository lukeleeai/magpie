#include<cstdio>

#include<cstring>

const int N=100007,P=1000000007;

char str[N];int a[N],f[N],las[3];

int main()

{

    scanf("%s",str+1);int n=strlen(str+1),flg=0;

    for(int i=1;i<=n;++i) if(a[i]=(a[i-1]+str[i]-'a'+1)%3,str[i]==str[i-1]) flg=1;

    if(!flg) return puts("1"),0;;

    for(int i=1;i<=n;++i) f[i]=(1ll*f[las[0]]+f[las[1]]+f[las[2]]+(a[i]>=1)-f[las[a[i]]]+P)%P,las[a[i]]=i;

    printf("%d",f[n]);

}