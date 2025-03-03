#include"stdc++.h"

#define RG register

using namespace std;

struct node

{

	int a,b,c;

	node(int aa=0,int bb=0,int cc=0)

	{

		a=aa;b=bb;c=cc;

	}

}point[100005];

int t,n,m,q,pd[100005],vis[100005],father2[100005],father1[100005];

long long size1[100005],size2[100005],mina1[100005],mina2[100005];

bool flag;

bool cmp1(const node &a,const node &b)

{

	return a.a<b.a;

}

bool cmp2(const node &a,const node &b)

{

	return a.b<b.b;

}

int find1(int x)

{

	if(x==father1[x]) return x;

	int now=find1(father1[x]);

	size1[x]+=size1[father1[x]];

	return father1[x]=now;

}

int find2(int x)

{

	if(x==father2[x]) return x;

	int now=find2(father2[x]);

	size2[x]+=size2[father2[x]];

	return father2[x]=now;

}

bool union1(int x,int y,int val)

{

	int r1=find1(x),r2=find1(y);

	if(r1!=r2)

	{

		father1[r1]=r2;

		size1[r1]=size1[y]+val-size1[x];

	}

	else 

	{

		if(size1[x]-size1[y]!=val) return false;

	}

	return true;

}

bool union2(int x,int y,int val)

{

	int r1=find2(x),r2=find2(y);

	if(r1!=r2)

	{

		father2[r1]=r2;

		size2[r1]=size2[y]+val-size2[x];

	}

	else 

	{

		if(size2[x]-size2[y]!=val) return false;

	}

	return true;

}

int main()

{

	t=1;

	while(t--)

	{

		flag=false;

		scanf("%d%d",&n,&m);

		scanf("%d",&q);

		for(RG int i=1;i<=q;i++)

		{

			scanf("%d%d%d",&point[i].a,&point[i].b,&point[i].c);

		}

		for(int i=1;i<=n;i++)

		father1[i]=i,size1[i]=0;

		for(int i=1;i<=m;i++)

		father2[i]=i,size2[i]=0;

		for(RG int i=1;i<=q;i++)

		{

			if(point[i].c<0)

			{

				flag=true;

				break;

			}

		}

		sort(point+1,point+q+1,cmp1);

		for(int i=2;i<=q;i++)

		if(point[i].a==point[i-1].a)

		{

			if(!union2(point[i-1].b,point[i].b,point[i].c-point[i-1].c)) 

			{

				flag=true;

				break;

			}

		}

		sort(point+1,point+q+1,cmp2);

		for(int i=2;i<=q;i++)

		if(point[i].b==point[i-1].b)

		{

			if(!union1(point[i-1].a,point[i].a,point[i].c-point[i-1].c)) 

			{

				flag=true;

				break;

			}

		}

		memset(mina1,127,sizeof(mina1));

		memset(mina2,127,sizeof(mina2));

		for(int i=1;i<=q;i++)

		{

			int pos=find1(point[i].a);

			mina1[pos]=min(mina1[pos],point[i].c+size1[point[i].a]);

		}

		for(int i=1;i<=n;i++)

		{

			int pos=find1(i);

			mina2[pos]=min(mina2[pos],-size1[i]);

		}

		for(int i=1;i<=n;i++)

		if(father1[i]==i&&mina1[i]+mina2[i]<0) 

		{

			flag=true;

			break;

		}

		memset(mina1,127,sizeof(mina1));

		memset(mina2,127,sizeof(mina2));

		for(int i=1;i<=q;i++)

		{

			int pos=find2(point[i].b);

			mina1[pos]=min(mina1[pos],point[i].c+size2[point[i].b]);

		}

		for(int i=1;i<=m;i++)

		{

			int pos=find2(i);

			mina2[pos]=min(mina2[pos],-size2[i]);

		}

		for(int i=1;i<=m;i++)

		if(father2[i]==i&&mina1[i]+mina2[i]<0) 

		{

			flag=true;

			break;

		}

		if(flag)

		{

			printf("No\n");

		}

		else 

		{

			printf("Yes\n");

		}

	}

	return 0;

}

/*

6

2 2

3

1 1 0

1 2 10

2 1 20

2 3

5

1 1 0

1 2 10

1 3 20

2 1 30

2 3 40

2 2

3

1 1 20

1 2 10

2 1 0

3 3

4

1 1 0

1 3 10

3 1 10

3 3 20

2 2

4

1 1 0

1 2 10

2 1 30

2 2 20

1 1 

1

1 1 -1



1

3 3

4

1 1 0

1 3 10

3 1 10

3 3 20

*/