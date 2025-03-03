#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 5000000

using namespace std;

typedef int hp[MAXN+5];

char str[MAXN+5];

int sum=0;

hp N,d;

void Str_To_Hp(char *s,hp &x)

{

	int len=strlen(s);

	for(int i=0;i<len;i++)

		x[len-i]=s[i]-'0';

	x[0]=len;

}

void Clear(hp &x)

{

	for(int i=x[0];i>=0;i--)

		x[i]=0;

}

void Add(hp &a,int b)

{

	int len=a[0];

	sum-=a[1];

	a[1]+=b;

	for(int i=1;true;i++)

	{

		sum+=a[i]%10;

		if(a[i]>=10)

		{

			sum-=a[i+1];

			a[i+1]+=a[i]/10;

			a[i]%=10;

		}

		else

		{

			len=max(i,len);

			break;

		}

	}

	len++;

	while(len>1&&a[len]==0)

		len--;

	a[0]=len;

}

void Mul(hp a,int b,hp &c)

{

	Clear(d);

	int len=a[0];

	for(int i=1;i<=len;i++)

	{

		d[i]+=a[i]*b;

		d[i+1]+=d[i]/10;

		d[i]%=10;

	}

	len++;

	while(d[len])

	{

		d[len+1]+=d[len]/10;

		d[len]%=10;

		len++;

	}

	while(len>1&&d[len]==0)

		len--;

	d[0]=len;

	for(int i=0;i<=len;i++)

		c[i]=d[i];

}

bool Check(int k)

{

	int sum=0;

	for(int i=1;i<=N[0];i++)

		sum+=N[i];

	if(sum>9*k)

		return false;

	return true;

}

int main()

{

	scanf("%s",str);

	Str_To_Hp(str,N);

	Mul(N,9,N);

	sum=0;

	for(int i=1;i<=N[0];i++)

		sum+=N[i];

	for(int k=1;true;k++)

	{

		Add(N,9);

		if(sum<=9*k)

		{

			printf("%d\n",k);

			return 0;

		}

	}

	return 0;

}