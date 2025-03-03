#include"stdc++.h"

using namespace std;

char a[100][100];

int main()

{

	int m,n;

	cin>>m>>n;

	memset(a,48,sizeof(a));

	for(int i=1;i<=m;++i)

	  for(int j=1;j<=n;++j)

	  {

	  	char t;

	  	cin>>t;

	  	if(t=='#')a[i][j]='#';

	  }

	for(int i=1;i<=m;++i)

	  for(int j=1;j<=n;++j)

	  {

	  	if(a[i][j]==48)

	  	{

	  		for(int k=i-1;k<=i+1;++k)

	  		  for(int l=j-1;l<=j+1;++l)

	  		  if(a[k][l]=='#')a[i][j]++;

		}

	  }

	for(int i=1;i<=m;++i)

	{

	 	for(int j=1;j<=n;++j)

	    cout<<a[i][j];

	    cout<<endl;

	} 

}