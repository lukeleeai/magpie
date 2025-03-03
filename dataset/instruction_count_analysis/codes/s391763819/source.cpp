#include"stdc++.h"

using namespace std;



const int maxn = 1e5+100;

char s[maxn];



int main()

{

    while (scanf("%s",s)!=EOF)

    {

        int l = strlen(s);

        int k = 0, ans = l;

        for (int i = 1; i < l; ++i)

            if (abs(s[i-1] - s[i]) == 1)

            {

                k = max(i,l-i);

                ans = min(ans,k);

            }

        printf("%d\n",ans);

    }

    return 0;

}
