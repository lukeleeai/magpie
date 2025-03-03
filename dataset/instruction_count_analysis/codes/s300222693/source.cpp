#include"stdc++.h"



using namespace std;



typedef long long ll;

typedef pair<int, int> PII;



const int MM = 1e9 + 7;

const double eps = 1e-8;

const int MAXN = 2e6 + 10;



int n, m;



void prework(){



}



void read(){



}



class BITree{

public:

    static const int SIZE = 100010, BIAS = 5;

    long long u[SIZE];

    void clear(){

        memset(u,0,sizeof(u));

    }

    void modify(int x, long long v){

        for(x+=BIAS;x<SIZE;x+=x&-x) u[x]+=v;

    }

    long long getsum(int x){

        long long s=0;

        for(x+=BIAS;x;x-=x&-x) s+=u[x];

        return s;

    }

} hnk;



int a[MAXN];

int f[MAXN];

ll g[MAXN];



void solve(int casi){

	scanf("%d", &n);

	map<int, int> nico;

	for(int i = 1; i <= n; i++){

		scanf("%d", &a[i]);

		nico[a[i]] = 1;

	}

	int cnt = 0;

	for(auto &x : nico){

		x.second = ++cnt;

	}

	

//	for(auto &x : nico){

//		cout<<x.first<<' '<<x.second<<endl;

//	}

	

	hnk.clear();

	for(int i = 1; i <= n; i++){

		hnk.modify(1, 1);

		hnk.modify(nico[a[i]] + 1, -1);

	}

	cnt = 0;

	for(auto &x : nico){

		++cnt;

		f[cnt] = x.first;

		g[cnt] = hnk.getsum(x.second);

	}

	f[0] = 0;

	/*

	for(int i = 1; i <= cnt; i++){

		cout<<f[i]<<' ';

	} cout<<endl;

	for(int i = 1; i <= cnt; i++){

		cout<<g[i]<<' ';

	} cout<<endl;

	*/for(int i = 1, j = 1; i <= n; i++){

		ll ans = 0;

		while(j <= cnt && a[i] >= f[j]){

			ans += g[j] * (f[j] - f[j-1]);

			j++;

		}

		printf("%lld\n", ans);

	}

}



void printans(){



}





int main(){

	prework();

	int T = 1;

//	cin>>T;

	for(int i = 1; i <= T; i++){

		read();

		solve(i);

		printans();

	}

	return 0;

}




