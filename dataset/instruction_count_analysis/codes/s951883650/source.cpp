#include<iostream>

#include<string>

#include<iomanip>

#include<cmath>

#include<vector>

#include<algorithm>



using namespace std;



#define int long long

#define rep(i,n) for(int i = 0; i < (n); i++)

#define INF ((long long)1e18)

#define MOD ((int)1e9+7)

#define endl "\n"



#define yn(f) ((f)?"Yes":"No")

#define YN(f) ((f)?"YES":"NO")



#define MAX 110000



int s[MAX], t[MAX], x[MAX];

pair<int,int> temp[MAX], temp2[MAX], que[MAX];



signed main(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	cout<<fixed<<setprecision(10);

	

	int A, B, Q;

	

	cin>>A>>B>>Q;

	

	rep(i,A)cin>>s[i];

	rep(i,B)cin>>t[i];

	rep(i,Q){

		cin>>x[i];

		que[i].first = x[i];

		que[i].second = i;

	}

	

	sort(x,x+Q);

	sort(que,que+Q);

	for(int i = 0; i < Q; i++){

		 que[i].first = que[i].second;

		 que[i].second = i;

	}

	sort(que,que+Q);

	for(int i = 0, j = 0; i < Q; i++){

		for(;j < A;j++){

			if(x[i] < s[j]) break;

		}

		if(j == 0) temp[i].first = INF;

		else temp[i].first = x[i]-s[j-1];

		

		if(j == A) temp[i].second = INF;

		else temp[i].second = s[j]-x[i];

		// cout<<i<<" "<<temp[i].first<<" "<<temp[i].second<<endl;

		// cout<<x[i]<<" "<<s[j]<<endl;

	}

	

	for(int i = 0, j = 0; i < Q; i++){

		for(;j < B;j++){

			if(x[i] < t[j]) break;

		}

		if(j == 0) temp2[i].first = INF;

		else temp2[i].first = x[i]-t[j-1];

		

		if(j == B) temp2[i].second = INF;

		else temp2[i].second = t[j]-x[i];

		// cout<<i<<" "<<temp2[i].first<<" "<<temp2[i].second<<endl;

	}

	

	for(int j = 0; j < Q; j++){

		int i = que[j].second;

		cout<<min(min(max(temp[i].first,temp2[i].first),max(temp[i].second,temp2[i].second)),min(min(temp[i].first,temp2[i].second)*2+max(temp[i].first,temp2[i].second),min(temp[i].second,temp2[i].first)*2 + max(temp[i].second,temp2[i].first)))<<endl;

		// cout<<temp[i].first<<" "<<temp[i].second<<endl;

		// cout<<temp2[i].first<<" "<<temp2[i].second<<endl<<endl;;

	}

	

	

	return 0;

}