#include <stdio.h>

#include <string.h>

int main()

{

	char str[102];

	long long k;

	scanf("%s %lld",str,&k);

	char c=str[0];

	int len=strlen(str);

	long long t=0;

	int pre=0;

	int jian=0;

	for(int i=0;i<len-1;i++)

	if(str[i]!=str[i+1]) jian++;

	if(jian){

	

	for(int i=1;i<=len;i++)

	{	

		

		if(str[i]==str[i-1]) pre++;

		else {

			pre++;

			pre/2==0?pre:pre-1;

			t=t+pre/2;

			pre=0;

		}

	}

	if(str[len-1]!=str[0]) t=t*k;

	else{

		int x=0,y=0;

		for(int i=0;str[i]==str[0];i++)

		x++;

		for(int j=len-1;str[len-1]==str[j];j--)

		y++;

		if(x%2!=0&&y%2!=0) t=t*k+k-1;

		else t=t*k;

	}

}

else {

	t=len*k;

	if(t%2==0) t=t/2;

	else t=(t-1)/2;

}

	printf("%lld",t);

	return 0;

	

}