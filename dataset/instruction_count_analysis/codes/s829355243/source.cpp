//q

#include<stdio.h>



int cnt[26]={0}, ok=0;

char s[100005];



int main()

{

	//freopen("in.txt", "r", stdin);

	scanf("%s", s);

	for(int i=0; s[i]; i++) cnt[s[i]-'a']++;

	for(int i=0; i<26; i++)

	{

		if(!cnt[i])

		{

			ok++;

			putchar(i+'a');

			break;

		}

	}

	if(!ok) printf("None");

	puts("");

	return 0;

}