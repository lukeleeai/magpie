#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)

#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)

#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)

#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)



/*

上から順に決めれそう

*/



bool ok=true;

ll n,a[200010],b[200010];

vector<ll> fact[200010],ans;



void factoring(ll n,vector<ll> v[]){

	ll visit[300010]={};

	reg(i,2,n){

		if(visit[i]==0){

			reg(j,1,n){

				if(j*i>n)break;

				visit[i*j]=1;

				v[i*j].push_back(i);//素因数リスト（重複は含まず）

			}

		}

	}

}



void init(){

	cin>>n;

	reg(i,1,n)cin>>a[i];

	// factoring(n,fact);

}



int main(void){

	init();

	ireg(i,1,n){

		if(a[i]==1){

			ans.push_back(i);

			reg(j,1,i){

				if(j*j>i)break;

				if(i%j!=0)continue;

				if(j==i/j){

					a[j]=1-a[j];

				}else{

					a[j]=1-a[j];

					a[i/j]=1-a[i/j];

				}

			}

		}

	}

	ireg(i,1,n)if(a[i]==1)ok=false;

	if(ok){

		cout<<ans.size()<<endl;

		rep(i,ans.size())cout<<ans[i]<<" ";

		cout<<endl;

	}else{

		cout<<-1<<endl;

	}

	return 0;

}