#include<cstdio>

#include<cmath>

using namespace std;

long long n,ans;

int s;

int main(){

    scanf("%lld",&n);

    for(int i=sqrt(n);i>0;--i)

        if(n%i==0){

            ans=n/i;

            break;

        }

    while(ans>0){

        ++s;

        ans/=10;

    }

    printf("%d\n",s);

    return 0;

}
