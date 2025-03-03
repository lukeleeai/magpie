#include"stdc++.h"

using namespace std;

#define lp(i,n) for(int i=0;i<n;i++)

#define lps(i,j,n) for(int i=j;i<n;i++)

#define fordebug int hoge;cin>>hoge;

#define DEKAI 1000000007;

#define INF (1<<28)

#define int long long

#define double long double

#define floot10 cout<<fixed<<setprecision(10)

bool dp[1100][1100];



signed main(){

  int w,h;

  cin>>w>>h;

  char a[1100][1100];

  lp(i,1100)lp(j,1100){

    dp[i][j]=false;

    a[i][j]='#';

  }

  int gx,gy;

  lp(i,h){

    lp(j,w){

      cin>>a[i+1][j+1];

      if(a[i+1][j+1]=='t'){

	gx=i+1;

	gy=j+1;

      }

    }

  }

  queue<pair<int,int>> q;

  q.push({1,1});

  dp[1][1]=true;

  int ax[4]={0,0,-1,1};

  int ay[4]={-1,1,0,0};

  int n;

  cin>>n;

  int hox[1010],hoy[1010];

  lp(i,n){

    cin>>hox[i]>>hoy[i];

  }

  lp(z,n+1){

    while(!q.empty()){

      int x,y;

      x=q.front().first;

      y=q.front().second;

      //cout<<x<<y<<endl;

      q.pop();

      lp(i,4){

	int nex=x+ax[i];

	int ney=y+ay[i];

	if(nex==gx&&ney==gy){

	  cout<<z<<endl;

	  return 0;

	}

	if(dp[nex][ney]==false){

	  dp[nex][ney]=true;

	  if(a[nex][ney]=='.'){

	    q.push({nex,ney});

	  }

	}

      }

    }

    if(z==n) break;/*

    lp(i,10){

      lp(j,10){

	if(dp[i+1][j+1]==false){

	  cout<<0;

	}

	else cout<<1;

      }

      cout<<endl;

    }

    lp(i,10){

      lp(j,10){

	cout<<a[i+1][j+1]

      }

      cout<<endl;

      }*/

    int bx,by;

    bx=hoy[z];

    by=hox[z];

    bx++;

    by++;

    if(a[bx][by]=='#'){

      a[bx][by]='.';

      if(dp[bx][by]==true){

	q.push({bx,by});

      }

    }

  }

  cout<<-1<<endl;

  return 0;

}




