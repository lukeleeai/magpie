#include<cstdio>

#include<algorithm>

using namespace std;

char str[200005];

int main(){



    scanf("%s",str);

    int ans = 0;

    int a=-1;

    for(int i=0;str[i];i++){

        if(str[i]=='Z'){

            if(a!=-1)

                ans = max(ans,i-a);

        }else if(str[i]=='A' && a==-1)

            a = i;

    }

    printf("%d\n",ans+1);

    return 0;

}
