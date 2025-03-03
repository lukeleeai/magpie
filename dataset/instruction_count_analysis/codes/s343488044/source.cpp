#include<cstdio>

using namespace std;

#define MAX 1000000

int prime[MAX];

bool is_prime[MAX];

int sieve(int n){   //埃氏?

   int p=0;

   for(int i=0;i<=n;i++)

    is_prime[i]=true;

    is_prime[0]=is_prime[1]=false;

   for(int i=2;i<=n;i++){

    if(is_prime[i]){

        prime[p++]=i;    //??素数的个数和素数的?

        for(int j=2*i;j<=n;j+=i)

            is_prime[j]=false;

    }

   }

   return p;

}

int main()

{

  int num;

  while(scanf("%d",&num)!=EOF){

   printf("%d\n",sieve(num));

  }

  return 0;

}