#include <cstdio>

#include <tr1/unordered_set>

using namespace std;

int a[50000],b[50000],o[50000];

int main(){

	int H,W,q;

	while(scanf("%d%d%d",&H,&W,&q)&&H){

		int ans = 0;

		for(int i = 0 ; i < q ; i++)

			scanf("%d%d%d",&a[i],&b[i],&o[i]);

		tr1::unordered_set<int> g[2];

		for(int i = q-1 ; i >= 0 ; i--){

			if(a[i]==0){

				if(!g[0].count(b[i]) && o[i]) ans += W - g[1].size();

				g[0].insert(b[i]);

			}else{

				if(!g[1].count(b[i]) && o[i]) ans += H - g[0].size();

				g[1].insert(b[i]);

			}

		}

		printf("%d\n",ans);

	}

}