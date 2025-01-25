#include<iostream>

#include<string>

#include<algorithm>

#include<cctype>

#include<vector>

#include<map>

#include<iomanip>

using namespace std;

#define fr first

#define sc second

typedef pair<int,int> P;

int main(){

  int X,Y,Z,N,E,A;

  while(cin >> X >> Y >> Z , X){

    int jump[X];

    P ivent[Y+1];

    for(int i = 0 ; i <= Y ; i++ ) ivent[i] = P( 0 , 0 );

    double dp[51][5001]={{}};

    dp[0][0] = 1.0;



    for(int i = 0 ; i < X ; i++ ){

      cin >> jump[i];

    }

    for(int i = 0 ; i < Z ; i++ ){

      cin >> N >> E >> A;

      switch(E){

      case 1: ivent[N].fr = A; break;

      case 2: ivent[N].sc = A; break;

      case 3: ivent[N].sc = -A; break;

      }

    }

    for(int i = 0 , limit = 0 ; i < Y ; i++ , limit += 100 ){

      for(int j = 0 ; j <= limit ; j++ ){

        if(dp[i][j]){

          for(int k = 0 , p_mas , p_money ; k < X ; k++ ){

            p_mas = min( i + jump[k] , Y );

            p_money = max(0,ivent[p_mas].sc + j );

            p_mas = min( p_mas + ivent[p_mas].fr , Y );



            dp[p_mas][p_money] += dp[i][j] / X;

          }

        }

      }

    }

    double ans = 0.0;

    for(int i = 0 ; i < 5001 ; i++ ){

      ans += dp[Y][i] * i;

    }

    cout << (int)ans << endl;

  }

}