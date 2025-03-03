#include<cstdio>

#include<cstring>

#include<cmath>

#include<vector>

#include<queue>

#define SF scanf

#define PF printf

#define MAXN 2000010

using namespace std;

typedef long long ll;

char s[MAXN];

char t[MAXN];

int pre[MAXN];

int n,las,cnt=1,ans,add;

int main(){

	SF("%d",&n);

	SF("%s",s+1);

	SF("%s",t+1);

	int las=n;

	bool flag=0;

	for(int i=1;i<=n;i++)

		if(s[i]!=t[i])

			flag=1;

	if(flag==0){

		PF("0");

		return 0;	

	}

	int now=1;

	for(int i=n;i>=1;i--){

		if(i==1||t[i]!=t[i-1]){

			las=min(las,i);

			while(las>0&&s[las]!=t[i])

				las--;

			if(las==0){

				PF("-1");

				return 0;

			}

			add++;

			pre[las+add]--;

			if(las+add>=i+add)

				now--;

			now++;

			ans=max(ans,now);

			continue;

		}

		now+=pre[i+add];

	}

	PF("%d",ans);

}