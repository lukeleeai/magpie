#include<cstdio>

using namespace std;

typedef long long ll;

const int MAX=2e5+10;

char str[MAX];

int main(){

    while(~scanf("%s",str)){

        ll ans=0,b=0;

        for(int i=0;str[i];i++){

            if(str[i]=='B') b++;

            else ans+=b;

        }

        printf("%lld\n",ans);

    }

    return 0;

}