#include<iostream>

#include<cstdio>

#include<cstdlib> 

#include<cstring>

#include<string>

#include<algorithm>

#include<map>

#include<set>

#include<queue>

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

#define For(a,b,c) for (int (a)=(b);(a)<(c);(a)++)

#define mp make_pair

string rec_x[20],rec_y[20];

string tri[20],trj[20];

string sx[20],sy[20];

bool vis[20],vi[20];

int n,m,l,r,l1,r1;

inline void init(){

	cin>>n>>m;

	getline(cin,rec_x[0]);

	For(i,0,n)

		getline(cin,rec_x[i]);

	For(i,0,n)	{

		sx[i]=rec_x[i];

		sort(sx[i].begin(),sx[i].end());

	}

}

bool check(){

	For(i,0,m)

		For(j,0,n)

			if (trj[i][j]!=trj[m-i-1][n-j-1])	return 0;

	return 1;

}

void solve_y(int x){

	if (x==0)	{

		if (check()){

			cout<<"YES"<<endl;

			exit(0);

		}

		return; 

	}

	if (x==1){

		For(i,0,m)	

			if (!vi[i]){

				trj[l1]=rec_y[i];

				solve_y(x-1);

			}

		return;

	}

	For(i,0,m)

		For(j,i+1,m)

			if (!vi[i]&&!vi[j]&&sy[i]==sy[j]){

				trj[l1++]=rec_y[i];

				trj[r1--]=rec_y[j];

				vi[i]=vi[j]=1;

				solve_y(x-2);

				vi[i]=vi[j]=0;

				l1--;

				r1++; 

			}	

}

void solve_x(int x){

	if (x==0)	{

		For(i,0,m)

			rec_y[i]="";

		For(i,0,m)

			For(j,0,n)

				rec_y[i]=rec_y[i]+tri[j][i];

		For(i,0,m){

			sy[i]=rec_y[i];

			sort(sy[i].begin(),sy[i].end());

		}

		l1=0;

		r1=m-1;

		memset(vi,0,sizeof(vi));

		solve_y(m);

		return;

	}

	if (x==1){

		For(i,0,n)	

			if (!vis[i]){

				tri[l]=rec_x[i];

				solve_x(x-1);

			}

		return;

	}

	For(i,0,n)

		For(j,i+1,n)

			if (!vis[i]&&!vis[j]&&sx[i]==sx[j]){

				tri[l++]=rec_x[i];

				tri[r--]=rec_x[j];

				vis[i]=vis[j]=1;

				solve_x(x-2);

				vis[i]=vis[j]=0;

				l--;

				r++; 

			}

}

int main(){

	ios_base::sync_with_stdio(false);

	init();

	l=0;r=n-1;

	solve_x(n);

	cout<<"NO"<<endl;

	return 0;

}