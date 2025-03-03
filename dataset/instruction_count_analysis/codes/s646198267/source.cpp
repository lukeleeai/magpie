#include <cstdio>

#include <vector>

#include <set>

using namespace std;

int card[10],n,k;

bool used[10];

vector<int> V;

set<int> S;

void solve(int x) {

	if(x==k) {

		int p=0,q=1;

		for(int i=0;i<V.size();i++) {

			p+=(V[i]%10)*q; q*=10;

			if(V[i]/10) p+=(V[i]/10)*q,q*=10;

		}

		S.insert(p);

		return;

	}

	for(int i=0;i<n;i++) {

		if(!used[i]) {

			used[i]=true;

			V.push_back(card[i]);

			solve(x+1);

			V.pop_back();

			used[i]=false;

		}

	}

}

int main() {

	while(scanf("%d",&n),n) {

		scanf("%d",&k);

		for(int i=0;i<n;i++) scanf("%d",&card[i]);

		S.clear();

		solve(0);

		printf("%d\n",S.size());

	}

}