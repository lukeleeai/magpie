#include "stdc++.h"

#define ll long long

#define INF 999999999

#define MOD 1000000007

#define rep(i,n) for(int i=0;i<n;i++)



using namespace std;



typedef pair<int,int>P;



const int MAX_N = 100;

const int MAX_W = 10000;



int n,W;

int w[MAX_N];

int v[MAX_N];

int m[MAX_N];

int dp[MAX_W+1];

int deq[MAX_W+1];

int deqv[MAX_W+1];



int main()

{

	cin >> n >> W;

	rep(i,n){

		scanf("%d%d%d",&v[i],&w[i],&m[i]);

	}

	rep(i,n){

		rep(a,w[i]){

			int s=0,t=0;

			for(int j=0;j*w[i]+a<=W;j++){

				int val = dp[j*w[i]+a]-j*v[i];

				while(s<t&&deqv[t-1]<=val){

					t--;

				}

				deq[t] = j;

				deqv[t++] = val;

				dp[j*w[i]+a] = deqv[s] + j*v[i];

				if(deq[s] == j-m[i]){

					s++;

				}

			}

		}

	}

	cout << dp[W] << "\n";

	return 0;

}