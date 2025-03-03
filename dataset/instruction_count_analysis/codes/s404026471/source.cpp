#include"stdc++.h"

using namespace std;



typedef long long lint;

typedef long double louble;



template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}

template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}



const char lf = '\n';



namespace ae86

{

	const int bufl = 1 << 15;



	char buf[bufl],*s=buf,*t=buf;



	inline int fetch()

	{

		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}

		return *s++;

	}



	inline int ty()

	{

		int a=0;int b=1,c=fetch();

		while(!isdigit(c))b^=c=='-',c=fetch();

		while(isdigit(c))a=a*10+c-48,c=fetch();

		return b?a:-a;

	}

}

using ae86::ty;



const int _ = 100007 , __ = _ + _;



void failure(){cout<<"IMPOSSIBLE"<<lf;exit(0);}



int n;

vector<int> e[_];



struct oatww

{

	int rt,to[__],ne[__],he[_],ecnt;



	void adde(int a,int b){to[++ecnt]=b,ne[ecnt]=he[a],he[a]=ecnt;}



	void addde(int a,int b){adde(a,b),adde(b,a);}



	int du[_];



	int dfs(int x)

	{

		int a=0;

		du[x]=0;

		for(int i=he[x];i;i=ne[i])

		{

			int b=dfs(to[i]);du[x]++;

			if(!a)a=b;

			else e[a].emplace_back(b),e[b].emplace_back(a),a=0;

		}

		if(!a)a=x;

		return a;

	}



	void make()

	{

		for(int i=1,a;i<=n;i++)

		{

			a=ty();

			if(a==-1)rt=i;

			else adde(a,i);

		}

		int res=dfs(rt);

		e[res].emplace_back(res);

	}

	

	oatww()

	{

		memset(he,0,sizeof(he));

		ecnt=1;

	}

}t1,t2;



int col[_]={0};



void dfs(int x,int v)

{

	col[x]=v+v-1;

	for(auto b:e[x])if(!col[b])dfs(b,1-v);

}



int main()

{

	ios::sync_with_stdio(0),cout.tie(nullptr);



	n=ty(),t1.make(),t2.make();

	for(int i=1;i<=n;i++)if(t1.du[i]%2!=t2.du[i]%2)failure();



	for(int i=1;i<=n;i++)if(!col[i] && !e[i].empty())dfs(i,0);

	cout<<"POSSIBLE";

	for(int i=1;i<=n;i++)cout<<" \n"[i==1]<<col[i];

	cout<<lf;



	return 0;

}
