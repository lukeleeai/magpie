#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<map>

#include<queue>

#include<set>

#include<stack>

#include<string>

#include<vector>

using namespace std;

typedef long long LL;

LL n;



vector<LL>v;

 LL sum=0;

LL b[100005]={0};

struct node

{

	 LL v,i;

};

bool cmp(const node a,const node b)

{ 

 return a.v<b.v;

}

struct node a[100005];

void bfs(LL index,LL t)

{

LL i=index;

	sum+=(t-b[i]);

	while(i>=0)

	 {

	 	 if(v[i]<t)

	 	 	break;

	 	 	b[i]=t;

			

		     i--;

	 }

	 i=index;

	 while(i<n)

	 {

	 	if(v[i]<t)

	 	 break;

		 

		b[i]=t;

		  i++;

	 }

 } 

int main()

{

 cin>>n;

  for(LL i=0;i<n;i++)

  {

  	cin>>a[i].v;

  	a[i].i=i;

  	v.push_back(a[i].v);

  }

 

  sort(a,a+n,cmp);

  for(LL i=0;i<n;i++)

  {

  	bfs(a[i].i,a[i].v);

//  	cout<<i<<" "<<a[i].v<<" "<<a[i].i<<endl;

//  	for(int i=0;i<n;i++)

//  	cout<<b[i]<<" ";

//  	cout<<"sum= "<<sum;

//  	cout<<"\n";

  }

//  for(int i=0;i<v.size();i++)

//  cout<<v[i]<<" ";

  cout<<sum;

}


