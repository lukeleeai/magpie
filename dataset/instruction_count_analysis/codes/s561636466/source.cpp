#include "stdc++.h"

using namespace std;

typedef long long ll;

const int N=2e6+20;

const ll mod=1e9+7;

char s[N],t[N];

int fail[N],suf[N];

void getfail(int *fail,char *s)

{

	fail[0]=-1;

	int i=0,j=-1;

	while(s[i])

	{

		if(j==-1||s[i]==s[j])

		{

			fail[i+1]=j+1;

			i++,j++;

		}

		else

			j=fail[j];

	}

}

int main()

{

	while(scanf("%s",s)!=EOF)

	{

		ll ans=0;

		int len=strlen(s);

		for(int i=0;s[i];i++)

			t[i]=s[len-i-1];

		t[len]='\0';

		getfail(fail,s);

		getfail(suf,t);

		int m;

	//	cout<<fail[len]<<endl;

		if(fail[len]==0||len%(len-fail[len]))

			m=1;

		else

			m=2;

		bool flag=true;

		for(int i=1;s[i];i++)

		{

			if(s[i]!=s[i-1])

				flag=false;

		}	

		if(flag)

			m=len;

		if(m==1||flag)

			ans=1;

		else

		{

			for(int i=0;i<len-1;i++)

			{

				int k=len-i-1;

			//	cout<<i<<' '<<k<<endl;

				if((fail[i+1]==0||(i+1)%((i+1)-fail[i+1])) &&(suf[k]==0||(k)%(k-suf[k])))

					ans++;

			}

		}	

		cout<<m<<endl<<ans<<endl;

	}

	return 0;

}
