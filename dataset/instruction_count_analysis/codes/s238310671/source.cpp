#include<stdio.h>

#include<map>

using namespace std;

int n,ch[1000005],sh[1000005],ans,sum,fa[1000005],tot,mk[1000005];

map <int,int> mp,mmp;

int gf(int p){

	if(fa[p]==p)return p;

	return fa[p]=gf(fa[p]);

}

void mg(int a,int b){

	int fx=gf(a),fy=gf(b);

	if(fx!=fy){

		fa[fx]=fy;

	}

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%d",&sh[i]);sum^=sh[i];mp[sh[i]]++;

	}mp[sum]++;

	for(int i=1;i<=n;i++){

		scanf("%d",&ch[i]);mp[ch[i]]--;

		if(mp[ch[i]]<0){

			ans=-999999999;

		}

		if(sh[i]!=ch[i]){mk[i]=1;

			ans++;

		}

	}

	sh[n+1]=sum;

	for(int i=1;i<=n+1;i++){

		if(mp[sh[i]]>0){

			ch[n+1]=sh[i];break;

		}

	}

	n++;tot=n+n;

	mk[n]=1;

	for(int i=1;i<=n;i++){

		if(!mk[i])continue;

		if(mmp[sh[i]]==0)mmp[sh[i]]=++tot;

		fa[i]=i;fa[i+n]=i+n;

	}

	for(int i=1;i<=tot;i++)fa[i]=i;

	for(int i=1;i<=n;i++){

		if(!mk[i]){

			fa[i]=fa[i+n]=0;

		}

	}

	for(int i=1;i<=n;i++){

		if(sh[i]!=ch[i])mg(i,i+n);

		mg(i,mmp[sh[i]]);mg(i+n,mmp[ch[i]]);

	}

	for(int i=1;i<=tot;i++){

		if(fa[i]==i){//printf("i:%d\n",i);

			ans++;

		}

	}

	ans--;

	if(ans<0)printf("-1");

	else printf("%d",ans);

}