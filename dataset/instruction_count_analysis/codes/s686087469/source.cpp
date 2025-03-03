#include"stdc++.h"

using namespace std;

int len,a[4],ok = 0;

char s[100010],ch;

int main(){

	scanf("%s",s+1);

	len=strlen(s+1);

	for(int i=1;i<=len;i++){

		if(s[i]=='a') a[1]++; 

		else if(s[i]=='b') a[2]++;

		else a[3]++;

	}

	sort(a+1,a+3+1);

	if(a[1]==a[2]&&a[2]==a[3]) ok=1;

	if((a[1]==(a[2]-1))&&a[2]==a[3]) ok=1;

	if(a[1]==a[2]&&a[2]==a[3]-1) ok=1;

	if(ok) puts("YES");

	else puts("NO");

	return 0;

}