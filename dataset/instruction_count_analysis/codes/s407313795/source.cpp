#include<cstdio>

#include<cstring>

using namespace std;



char s[200002];

int z[200001];

int main(){

	scanf("%s",s+1);

	int n=strlen(s+1);

	for(int i=1;i<=n;i++)

		if(s[i]=='A')z[++z[0]]=1;

		else if(i<n&&s[i]=='B'&&s[i+1]=='C')

			z[++z[0]]=2,i++;

		else z[++z[0]]=3;

	long long ans=0;

	for(int i=1;i<=z[0];i++){

		if(z[i]==3)continue;

		int j=i;

		while(j<=z[0]&&z[j]!=3)j++;

		int w=0;

		for(int k=i;k<=j;k++)

			if(z[k]==2)ans+=k-i-w,w++;

		i=j;

	}

	printf("%lld\n",ans);

}