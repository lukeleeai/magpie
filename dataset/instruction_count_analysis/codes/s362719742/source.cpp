#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include<algorithm>

using namespace std;

char s[210000];

int n,ans;

int main()

{

    scanf("%s",s+1);

    n=strlen(s+1);

    ans=n;

    for(int i=1;i<n;i++)

    {

        if(s[i]!=s[i+1])

            ans=min(ans,max(i,n-i));

    }

    printf("%d\n",ans);

    //system("pause");

    return 0;

}
