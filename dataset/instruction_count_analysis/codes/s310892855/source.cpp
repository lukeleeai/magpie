#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

int a[5];

int cnt=0;

int main()

{

	for(int i=1;i<=3;i++)

		scanf("%d",&a[i]);

	int cnt=0;

	int f=1;

	while(f)

	{

		if(a[1]==a[2]&&a[2]==a[3]) break;

		sort(a+1,a+1+3);

		while(a[1]+2<=a[3])a[1]+=2,cnt++;

		if(a[1]==a[2]&&a[2]==a[3]) break;

		while(a[2]+2<=a[3])a[2]+=2,cnt++;

		if(a[1]==a[2]&&a[2]==a[3]) break;

		if(a[2]==a[3]&&a[1]!=a[2]) a[1]+=2,a[2]+=1,a[3]+=1,cnt+=2;\

		if(a[1]==a[2]&&a[2]==a[3]) break;

		if((a[1]+1<=a[3]&&a[2]+1<=a[3]))a[1]+=1,a[2]+=1,cnt++;

	}

	printf("%d",cnt);

}