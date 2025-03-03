#include<iostream>

using namespace std;

int t[10][10],u[10][10],ans[10][10],n,flg;

int compute();

void dfs(int);

void change(int,int);

int main(){

  cin>>n;

  while(n--){

    flg=0;

    for(int i=0;i<10;i++){

      for(int j=0;j<10;j++){

	cin>>t[i][j];

	ans[i][j]=0;

      }

    }

    dfs(0);

  }

  return 0;

}

void dfs(int x){

  if(x==10){

    /*

    for(int i=0;i<10;i++)cout<<ans[0][i];

    cout<<endl;

    */

    

    if(compute()){

      for(int i=0;i<10;i++){

	for(int j=0;j<10;j++){

	  if(j)cout<<' ';

	  cout<<ans[i][j];

	}

	cout<<endl;

      }

    }

    

    return;

  }

  ans[0][x]=0;

  dfs(x+1);

  ans[0][x]=1;

  dfs(x+1);

}



int compute(){

  for(int i=0;i<10;i++){

    for(int j=0;j<10;j++){

      u[i][j]=t[i][j];

      if(i)ans[i][j]=0;

    }

  }



  for(int i=0;i<10;i++){

    if(ans[0][i])change(0,i);

  }



  for(int i=1;i<10;i++){

    for(int j=0;j<10;j++){

      if(u[i-1][j]){

	ans[i][j]=1;

	change(i,j);

      }

    }

  }

  for(int i=0;i<10;i++){

    if(u[9][i])return 0;

  }

  return 1;

}



void change(int y,int x){

  u[y][x]=!u[y][x];

  if(y>0)u[y-1][x]=!u[y-1][x];

  if(x>0)u[y][x-1]=!u[y][x-1];

  if(y<9)u[y+1][x]=!u[y+1][x];

  if(x<9)u[y][x+1]=!u[y][x+1];

}