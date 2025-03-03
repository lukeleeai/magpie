#include"stdc++.h"

#define MAXN 100005

#define reg register

#define inl inline

using namespace std;

char s[MAXN],ch[MAXN];

inl char Chg(reg char x)

{

	return x=='b'?'d':(x=='d'?'b':(x=='p'?'q':'p'));

}

int main()

{

	scanf("%s",ch+1);

	reg int len=strlen(ch+1);

	memcpy(s,ch,sizeof(ch));

	reverse(ch+1,ch+len+1);

	for(reg int i=1;i<=len;i++) ch[i]=Chg(ch[i]);

	reg bool fg=1;

	for(reg int i=1;i<=len;i++)

	{

		if(ch[i]!=s[i])

		{

			fg=0;

			break;

		}

	}

	puts(fg?"Yes":"No");

	return 0;

}