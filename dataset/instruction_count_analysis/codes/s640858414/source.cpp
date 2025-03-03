#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



int a[4];

char s[100001];

int main()

{

	scanf("%s",s+1);

	int len=strlen(s+1);

	for(register int i=1;i<=len;i++)

		a[s[i]-'a'+1]++;

	sort(a+1,a+4);

	if(a[3]-a[1]<=1)  printf("YES");

	else  printf("NO");

	return 0;

}