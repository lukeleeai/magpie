#include<cstdio>

#include<queue>

#include<vector>

#define put(x,y) make_pair(x,y)



using namespace std;

const int SIZE=1e6;

deque< pair<int,int> > p;

bool vis[SIZE];

int k;



void bfs() {

	while(p.size()) {

		pair<int,int> now=p.front(); p.pop_front();

		if(vis[now.first]) continue;

		vis[now.first]=true;

		if(!now.first) {

			printf("%d\n",now.second);

			return;

		}

		p.push_front(put(now.first*10%k,now.second));

		p.push_back(put((now.first+1)%k,now.second+1));

	}

	

}

int main() {

	scanf("%d",&k);

	p.push_front(put(1,1));

	bfs();

	return 0;

}