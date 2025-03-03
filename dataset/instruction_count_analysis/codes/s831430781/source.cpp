//#include"stdc++.h" 

#include<iostream> 

#include<cstdio>

#include<cstring>

#include<queue>

#include<vector>  

#define Max int(2e5+10) 

using namespace std;  

int n,p[Max],a[Max],dp[Max];

vector<int> g[Max];

int dfs(int x)

{

	if(dp[x]>0)

	   return dp[x];

	dp[x]=1;

	for(int i=0;i<g[x].size();i++)

	    dp[x]=dfs(g[x][i])+1;

	 return dp[x];	  

}

int  main()  

{   

    while(~scanf("%d",&n))

    {

    	for(int i=1;i<=n;i++)

    	    g[i].clear();

    	for(int i=1;i<=n;i++)

    	   {

    	   	scanf("%d",&p[i]);

    	   	a[p[i]]=i;

		   }

    	for(int i=1;i<n;i++)

		    if(a[i]<a[i+1])

		       g[a[i]].push_back(a[i+1]);

	//	for(int i=1;i<=n;i++)

	//	   cout<<g[i][0]<<endl; 	       

		memset(dp,0,sizeof dp);   

		int ma=-1;      

    	for(int i=1;i<=n;i++)

		   ma=max(ma,dfs(i));

		//cout<<ma<<endl;   

		printf("%d\n",n-ma);   

	}

      

       

     return 0;     

} 