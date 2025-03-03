#include<cstdio>

#include<cstring>

#include<cctype>

#include<algorithm>

using namespace std;

const int maxn=2e5+5;

int ls;

int nxt[26][maxn],pre[maxn],f[maxn];

char s[maxn],ch[maxn];

int main()

{

	scanf("%s",s+1);

	ls=strlen(s+1);

	for (int i=0;i<26;i++)

	{

	  int j=ls+1,p=ls;

	  while (j>=1)

	  {

	  	while (p>=1&&s[p]-'a'!=i)p--;

	  	while (j>=p+1)nxt[i][j]=p,j--;

	  	p--;

	  }

	}

	memset(f,0x3f,sizeof(f));

	f[ls+1]=0;

	for (int i=ls+1;i>=1;i--){

		for (int j=0;j<26;j++){

			if (f[i]+1<f[nxt[j][i]]){

				f[nxt[j][i]]=f[i]+1;

				pre[nxt[j][i]]=i;

				ch[nxt[j][i]]='a'+j;

			}else{

				if (f[i]+1==f[nxt[j][i]])if (j<ch[nxt[j][i]]-'a'){

					pre[nxt[j][i]]=i;

					ch[nxt[j][i]]='a'+j;

				}else if (j==ch[nxt[j][i]]-'a'&&s[i]<s[pre[nxt[j][i]]]){

				  pre[nxt[j][i]]=i;

				  ch[nxt[j][i]]='a'+j;

				}

			}

		}

	}

	int p=0;

	printf("%c",ch[0]);

	while (pre[p]!=ls+1)putchar(s[pre[p]]),p=pre[p];

	return 0;

}