#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

#define SF scanf

#define PF printf

#define MAXN 500010

using namespace std;

int dig[MAXN];	

int top,ans;

char s[MAXN];

int main(){

	SF("%s",s);

	int len=strlen(s);

	for(int i=len-1;i>=0;i--)

		dig[len-i-1]=s[i]-'0';

	top=len-1;

	int las=top;

	while(1){

		bool flag=0;

		if(top==0){

			if(dig[0]!=0)

				ans++;

			break;	

		}

		if(las<=top&&dig[las]>dig[las-1]&&dig[top]==dig[top-1]){

			top--;

			dig[top+1]=0;

			dig[0]++;

			int now=0;

			while(dig[now]>=10){

				dig[now+1]++;

				dig[now]%=10;

				now++;

				top=max(top,now+1);	

			}

			while(top>0&&dig[top]==0)

				top--;

			flag=1;

			ans++;

			continue;

		}

		for(int i=las-1;i>=0;i--)

			if(dig[i]<dig[i+1]){

				las=i+1;

				while(dig[i+1]==dig[i+2])

					i++;

				top=i;

				dig[top+1]=0;

				dig[0]++;

				int now=0;

				while(dig[now]>=10){

					dig[now+1]++;

					dig[now]%=10;

					now++;

					top=max(top,now+1);	

				}

				while(top>0&&dig[top]==0)

					top--;

				flag=1;

				break;

			}

		ans++;

		if(flag==0)

			break;

	}

	PF("%d",ans);

}	