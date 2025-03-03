#include<stdio.h>

#include<string.h>

#include<string>

#include<math.h>

#include<map>

#include<vector>

#include<queue>

#include<set>

#include<algorithm>

#define MAX 1000000007

using namespace std;

int main(){

    int n,m;

    while(~scanf("%d%d",&n,&m)){

        long long ans=1;

        if(n-m>1||m-n>1){

            printf("0\n");

        }

        else{

            if(n==m){

                for(int i=2;i<=n;i++){

                    ans=(ans*i)%MAX;

                    ans=(ans*i)%MAX;

                }

                ans=(ans*2)%MAX;

            }

            else{

                int pp;

                if(m<n){

                    pp=n;

                    n=m;

                    m=pp;

                }

                for(int i=2;i<=n;i++){

                    ans=(ans*i)%MAX;

                    ans=(ans*i)%MAX;

                }

                ans=(ans*m)%MAX;

            }

            printf("%lld\n",ans);

        }

    }

	return 0;

}
