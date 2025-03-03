#include <cstdio>

#include <cstring>

#include <string>

#include <queue>

#include <map>

#include <set>

#include <vector>

#include <iostream>

using std::string;

using std::queue;

using std::map;

using std::set;

using std::vector;

int n;

map<string,int> mp;

set<string> st[2010]; 

vector<int> edge[2010];

int in[2010];

char s[100010];

int tot;

string str[2010];

bool init()

{

	memset(in,0,sizeof(in));

	for(int i = 0; i < 2010; i++) edge[i].clear();

	tot = 0; mp.clear();

	scanf("%d",&n);

	if(!n) return false;

	for(int i = 0; i < n; i++)

	{

		scanf("%s",s);

	    string tmp = "";

		int j;

		for(j = 0; s[j]!=':'; j++) tmp += s[j];

		if(mp.find(tmp) == mp.end()) mp[tmp] = tot++,str[tot-1] = tmp;

		int fa = mp[tmp];

		tmp = "";

		for(j++;s[j];j++)

		{

			if(s[j]==',' || s[j] == '.')

			{

				if(mp.find(tmp) == mp.end()) mp[tmp] = tot++,str[tot-1]=tmp;

				edge[mp[tmp]].push_back(fa);

				in[fa]++;

				tmp = "";

			}

			else tmp += s[j];

		}

	}

//	for(int i= 0; i < tot; i++) std::cout<<str[i]<<std::endl;

	return true;

}

void solve()

{

	queue<int> Q;

	for(int i = 0; i < tot; i++) st[i].clear();

	for(int i = 0; i < tot; i++) if(!in[i]) 

	{

	//	printf("i=%d\n",i);

		Q.push(i);

		st[i].insert(str[i]);

	}

	while(!Q.empty())

	{

		int fr = Q.front();Q.pop();

		for(int i = 0; i < edge[fr].size(); i++)

		{

			int to = edge[fr][i];

			--in[to];

			for(set<string>::iterator it = st[fr].begin(); it != st[fr].end(); it++)

			{

				st[to].insert(*it);

			}

			if(!in[to])

			{

				Q.push(to);

			}

		}

	}

	printf("%d\n",st[0].size());

}

int main()

{

	while(init())

		solve();

}