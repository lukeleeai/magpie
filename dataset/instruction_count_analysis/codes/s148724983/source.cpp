#include<cstdio>

#include<algorithm>



using namespace std;



#define int long long

#define INF ((long long)1e18)

#define rep(i,n) for(int i = 0; i < (n); i++)



#define MAX 110000

	

int s[MAX], t[MAX], ans[MAX];

pair<int,int> x[MAX];



signed main(){



	int A, B, Q, a, b, c, d;

	

	scanf("%lld %lld %lld", &A,&B,&Q);

	

	rep(i,A)scanf("%lld",&s[i]);

	rep(i,B)scanf("%lld",&t[i]);

	rep(i,Q){scanf("%lld",&x[i].first);x[i].second = i;}

	

	sort(x,x+Q);

	

	for(int i = 0, j = 0, k = 0; i < Q; i++){

		for(;j < A && x[i].first >= s[j];j++);

		for(;k < B && x[i].first >= t[k];k++);

		a = j?x[i].first-s[j-1]:INF,b = j-A?s[j]-x[i].first:INF,c = k?x[i].first-t[k-1]:INF,d = k-B?t[k]-x[i].first:INF;

		ans[x[i].second] = min(min(max(a,c),max(b,d)),min(a>d?d*2+a:a*2+d,b>c?c*2+b:b*2+c));

	}

	

	rep(i,Q) printf("%lld\n",ans[i]);

	

	return 0;

}