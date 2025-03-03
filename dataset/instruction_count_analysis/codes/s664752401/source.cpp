#include <stdio.h>

 struct h{long long int a,b;}c[1000000];

bool cmp(h d,h e)

{if(d.b!=e.b)

return d.b<e.b;

}

#include<algorithm>

using namespace std;

int main()

{ long long int n,s,i,j,t;

while(~scanf("%lld",&n))

  {j=0,s=0;

  for(i=1;i<=n;i++)

   scanf("%lld%lld",&c[i].a,&c[i].b);

   if(n==1)

   {if(c[1].a>c[1].b)printf("No\n");

      else printf("Yes\n");

   }

   else{

   sort(c+1,c+1+n,cmp);

   t=1;

   

  for(i=1;i<n;i++)

   {

  if(t==1) s+=c[i].a+c[i+1].a;

    else  s+=c[i+1].a;

    t=2;

   

   if(s>c[i+1].b)

    {printf("No\n");

    

    j=1;

    break;

    }

   

  

  }

  

 

if(j==0)printf("Yes\n");}

}

}