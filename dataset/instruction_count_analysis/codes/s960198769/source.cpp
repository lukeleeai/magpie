#include<iostream>

#include<cstdio>

#include<map>

#include<set>

#include<queue>

using namespace std;

const int N=100001;

int n;

map<pair<int,int>,int> book;

set<int> e[N];

queue<pair<int,int> >q;

int f[N];

int find(int v)

{

	if(v==f[v]) return v;

	f[v]=find(f[v]);

	return f[v];

}

pair<int,int> make(int x,int y)

{

    if(x>y) swap(x,y);

    return make_pair(x,y);

}

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    	f[i]=i;

    for(int i=1;i<=(n-1)*2;i++)

	{

        int x,y;

        scanf("%d%d",&x,&y);

        e[x].insert(y);

		e[y].insert(x);

        pair<int,int> t=make(x,y);

        book[t]++;

        if(book[t]==2) q.push(t);

        if(book[t]>2)

        {

        	printf("NO");

        	return 0;

		}

    }

    for(int i=1;i<n;i++)

	{

        if(q.empty())

        {

        	printf("NO");

        	return 0;

		}

        int x=0,y=0;

        while(x==y)

        {

        	x=find(q.front().first),y=find(q.front().second);

        	q.pop();

		}

        if(e[x].size()>e[y].size()) swap(x,y);

        f[x]=y;

        for(set<int>::iterator it=e[x].begin();it!=e[x].end();it++)

		{

            int v=find(*it);

            e[v].erase(e[v].find(x));

            if(v==y) continue;

            e[v].insert(y),e[y].insert(v);

            pair<int,int> t=make(v,y);

            book[t]++;

            if(book[t]==2) q.push(t);

        }

        e[x].clear();

    }

    printf("YES");

    return 0;

}