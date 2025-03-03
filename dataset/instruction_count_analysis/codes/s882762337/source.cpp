#include"stdc++.h"

using namespace std;

static const int MAX_N=10e5;

struct P{int maxs,num;};

pair<int,int > A[MAX_N+1];

P B[MAX_N+1];

bool C[MAX_N+1];

stack <int>D;





int main(void){

	int N,K;

		cin >> N >> K;

	for(int i=0;i<N;i++)

		B[i].num=-1;

	

	for(int i=0;i<N;i++){

		int s,o;

			cin >> s >> o;

		s--;

		A[i].first=o*-1;

		A[i].second=i;

		if(B[s].maxs<o){

			B[s].maxs=o;

			B[s].num=i;

		}

	}

	for(int i=0;i<N;i++){

		if(B[i].num==-1)continue;

		C[B[i].num]=true;

	}

	sort(A,A+N);

	

	

	

	long long res=0,typer=0;

	for(int i=0;i<K;i++){

		res+=(long long)A[i].first*(-1);

		typer+=C[A[i].second];

		if(!C[A[i].second])

			D.push(A[i].first);

	}

	long long ans=res+typer*typer;

	for(int i=K;i<N && D.size();i++){

		if(C[A[i].second]){

			res-=D.top()*(-1);

			res+=(long long)A[i].first*(-1);

			D.pop();

			typer++;

			ans=max(ans,res+typer*typer);

		}

	}

	cout << ans << endl;

	return 0;

}
