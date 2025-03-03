#include<cstring>

#include<algorithm>

#include<cmath>

#include<iostream>

#include<cstdio>

using namespace std;

typedef long long ll;

const int maxm=500007;

char s[maxm];

int n;

int dp[maxm];//到i位置的最大操作数 

int l[maxm];//在左边离i最近的0的位置 

int main()

{

 scanf("%d",&n);

 scanf("%s",s+1);

 for(int i=1;i<=n;i++)

 {

  if(s[i]=='1') l[i]=l[i-1];

  else l[i]=i;	

 }

 for(int i=1;i<=n;i++)

 {

   dp[i]=dp[i-1];

   if(s[i]=='1')

   {

     if(s[i-1]=='0'&&s[i-2]=='1')

     {

       dp[i]=max(dp[i],dp[l[i-2]]+i-l[i-2]-2);//100|11111101的贡献为他们的长度-2,

       dp[i]=max(dp[i],dp[l[i-2]+1]+i-l[i-2]-1-2);//11111101|11111101

     }

     else if(l[i]>1&&s[l[i]-1]=='1')

	 {

	  dp[i]=max(dp[i],dp[l[i]-2]+i-l[i]+2-2);//101111111

     }

   }

 }

 printf("%d\n",dp[n]);

 return 0;	

}