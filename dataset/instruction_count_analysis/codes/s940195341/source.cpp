#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

typedef long long LL;

const int inf=1<<29;

const int maxn=1e5+100;

char s[maxn];



int main()

{

    //freopen("1.txt","r",stdin);

    while (scanf("%s",s+1)!=EOF)

    {

        int len=strlen(s+1);

        int ans=inf;

        for (int i=1;i<=len;i++)

        {

            if (s[i]!=s[i+1])

                ans=min(ans,max(i,len-i));

        }

        printf("%d\n",ans);

    }

    return 0;

}
