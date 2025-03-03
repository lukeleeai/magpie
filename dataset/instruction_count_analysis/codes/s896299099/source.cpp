#include<iostream>

using namespace std;

int H,W,K;

char t[1001][1001];

int J[1001][1001];

int O[1001][1001];

int I[1001][1001];



int main(){

  while(cin>>H>>W>>K){

    for(int i=1;i<=H;i++){

      for(int j=1;j<=W;j++){

	cin>>t[i][j];

	J[i][j]=(t[i][j]=='J'?1:0)+J[i-1][j]+J[i][j-1]-J[i-1][j-1];

	O[i][j]=(t[i][j]=='O'?1:0)+O[i-1][j]+O[i][j-1]-O[i-1][j-1];

	I[i][j]=(t[i][j]=='I'?1:0)+I[i-1][j]+I[i][j-1]-I[i-1][j-1];

      }

    }

    for(int i=0;i<K;i++){

      int ay,ax,by,bx;

      cin>>ay>>ax>>by>>bx;

      cout<<J[by][bx]-J[ay-1][bx]-J[by][ax-1]+J[ay-1][ax-1]<<' ';

      cout<<O[by][bx]-O[ay-1][bx]-O[by][ax-1]+O[ay-1][ax-1]<<' ';

      cout<<I[by][bx]-I[ay-1][bx]-I[by][ax-1]+I[ay-1][ax-1]<<endl;

    }

  }

  return 0;

}