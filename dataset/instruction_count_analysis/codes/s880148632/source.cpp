#include"stdc++.h"

using namespace std;



int a[5][5];

bool vis[5][5];



int main()

{

	ios::sync_with_stdio(false),cin.tie(0);

	for(int i=1;i<=3;i++){

		for(int j=1;j<=3;j++){

			cin>>a[i][j];

		}

	}

	int n;cin>>n;

	int num;

	for(int i=1;i<=n;i++){

		cin>>num;

		for(int k=1;k<=3;k++){

			for(int j=1;j<=3;j++){

				if(num==a[k][j])vis[k][j]=1;

			}

		}

	}

	bool flag=0;

	for(int i=1;i<=3;i++){

		if(vis[i][1]+vis[i][2]+vis[i][3]==3){

			flag=true;break;

		}

	}

	for(int i=1;i<=3;i++){

		if(flag)break;

		if(vis[1][i]+vis[2][i]+vis[3][i]==3){

			flag=true;break;

		}

	}

	if(!flag&&(vis[1][1]+vis[2][2]+vis[3][3]==3||vis[3][1]+vis[2][2]+vis[1][3]==3))flag=true;

	if(flag)cout<<"Yes"<<endl;

	else cout<<"No"<<endl;

	return 0;

}