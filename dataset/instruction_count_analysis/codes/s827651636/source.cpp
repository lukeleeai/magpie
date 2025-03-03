#include<cstdio>

#include<cstring>



const int N=200000;



int del,t,len;

char s[N+5];



int main()

{

	scanf("%s",s+1);

	len=strlen(s+1);

	for(int i=1;i<=len;i++)

	{

		if(s[i] == 'S')

			t++;

		else

			t?t--,del+=2:1;

	}

	printf("%d\n",len-del);

	return 0;

}