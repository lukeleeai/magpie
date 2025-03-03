#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



const int N=200000;



int len;

char s[N+5],t[N+5];

char s1[255],t1[255];



int main()

{

	scanf("%s %s",s+1,t+1);

	len=strlen(s+1);

	for(int i=1;i<=len;i++)

	{

		if( (!s1[s[i]] || s1[s[i]] == t[i]) && (!t1[t[i]] || t1[t[i]] == s[i]))

		{

			s1[s[i]] = t[i];

			t1[t[i]] = s[i];

		}

		else

		{

			puts("No");

			return 0;

		}

	}

	puts("Yes");

	return 0;

}