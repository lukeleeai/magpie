#include<cstdio>

typedef long long lger;

inline lger read(){

    lger x=0,f=1;char ch=getchar();

    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}

    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}

    return x*f;

}

lger n,num[100050],sum;

int main(){

	n=read();

	for(int i=1;i<=n;i++){num[i]=read();sum+=num[i];}

	if(sum%(n*(n+1)/2)!=0){puts("NO"); return 0;}

	lger round=sum/(n*(n+1)/2);

	lger flag=0;

	if((round-num[1]+num[n])%n!=0||round-num[1]+num[n]<0){puts("NO"); return 0;}

	else flag+=(round-num[1]+num[n])/n;

	for(int i=2;i<=n;i++)

		if((round-num[i]+num[i-1])%n!=0||round-num[i]+num[i-1]<0){

			puts("NO"); return 0;

		}

		else flag+=(round-num[i]+num[i-1])/n;

	puts(flag==round?"YES":"NO");

	return 0;

}
