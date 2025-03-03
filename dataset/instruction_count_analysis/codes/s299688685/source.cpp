#include"stdc++.h"

using namespace std;

#define maxn 200008

int n,m,q;

int arr[maxn];

int sum[maxn];

int cha[maxn];

vector<int> v1[maxn];

int main(){

	scanf("%d%d%d",&n,&m,&q);

	for(int i=1;i<=m;i++){

		int a,b;

		scanf("%d%d",&a,&b);

		v1[a].push_back(b);

	}

	for(int i=1;i<=n;i++){

		sort(v1[i].begin(),v1[i].end());

	}

	int ans=0;

	for(int i=1;i<=q;i++){

		int a,b;

		ans=0;

		scanf("%d%d",&a,&b);

		for(int j=a;j<=b;j++){

			ans+=upper_bound(v1[j].begin(),v1[j].end(),b)-v1[j].begin();

		}

		cout<<ans<<endl;

	}

	return 0;

}