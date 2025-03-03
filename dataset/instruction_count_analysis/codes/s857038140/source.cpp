#include<stdio.h>

#include<stdlib.h>

struct node

{

	long long x,y;

	int a,b;

}point[55];

int incx(const void *a, const void *b)

{

    struct node m = *(struct node *)a;

    struct node n = *(struct node *)b;

    if(m.x<n.x) return -1;

    else return 1;

}

int incy(const void *a, const void *b)

{

    struct node m = *(struct node *)a;

    struct node n = *(struct node *)b;

    if(m.y<n.y) return -1;

    else return 1;

}

int main()

{

	int n,k,mp[55][55],xmax,ymax,temp;

	bool np[55][55];

	long long x[55],y[55],S,min=-1,xx[55],yy[55],Smax=-1;

	for(int i=0;i<55;i++)

	{

		for(int j=0;j<55;j++)

		{

			mp[i][j]=0;

			np[i][j]=false;

		}

	}

	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++)scanf("%lld%lld",&point[i].x,&point[i].y);

	qsort(point,n,sizeof(struct node),incx);

	temp=0;

	for(int i=0;i<n;i++)

	{

		point[i].a=temp;

		xx[temp]=point[i].x;

		temp++;

	}

	qsort(point,n,sizeof(struct node),incy);

	temp=0;

	for(int i=0;i<n;i++)

	{

		point[i].b=temp;

		np[point[i].a][point[i].b]=true;

		yy[temp]=point[i].y;

		temp++;

	}

	if(np[0][0]==false)mp[0][0]=0;

	else mp[0][0]=1;

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			if(i==0)mp[i][j]=mp[i][j-1]+np[i][j];

			else if(j==0)mp[i][j]=mp[i-1][j]+np[i][j];

			else mp[i][j]=mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1]+np[i][j];

		}

	}

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			for(int p=i+1;p<n;p++)

			{

				for(int q=j+1;q<n;q++)

				{

					int sum;

					if(i==0)sum=mp[p][q]-mp[p][j-1];

					else if(j==0)sum=mp[p][q]-mp[i-1][q];

					else sum=mp[p][q]-mp[i-1][q]-mp[p][j-1]+mp[i-1][j-1];

					if(sum>=k)

					{

						if((xx[p]-xx[i])*(yy[q]-yy[j])<=Smax||Smax<0)Smax=(xx[p]-xx[i])*(yy[q]-yy[j]);

					}

				}

			}

		}

	}

	printf("%lld\n",Smax);

}