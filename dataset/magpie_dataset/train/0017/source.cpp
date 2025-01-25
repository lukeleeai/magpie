

// dpの練習

// dpでなく、愚直に組んだプログラミング

// ナップサック問題とほぼ同じ



#include <iostream>

#include <algorithm>

#include <cstring>



using namespace std;



int wei; // 持てる最大の重さ

int n; // お宝の数

int v[1001]; // お宝の価値

int w[1001]; // お宝の重さ

 // グローバル配列は0で初期化されている

int dp[1001][1001]; //メモテーブル



int max_value(int i, int j) {

  int value;



  if( dp[i][j] >= 0 ){

    return dp[i][j];

    //すでに１回は調べている

  }

 

  if (i == n) {

    // 品物がもう残っていないときは、価値の和の最大値は0で確定

    //もうお宝がないつまり、価値は0

    value = 0;

  } else if (j < w[i]) {

    //風呂敷が持てる重さを超えてしまう

    // 残りの容量が足りず品物iを入れられないので、入れないパターンだけ処理

    // i+1 以降の品物のみを使ったときの最大値をそのままこの場合の最大値にする

    value = max_value(i + 1, j);

  } else {

    //左がお宝を入れない、右がお宝を入れた場合

    // 品物iを入れるか入れないか選べるので、両方試して価値の和が大きい方を選ぶ

    value = max( max_value(i + 1, j), max_value(i + 1, j - w[i]) + v[i] );

  } 

  return dp[i][j] = value;

  //メモに記憶させる

}



void max_weight( int ans ){



  int w_min;

   

  for (int i = wei -1 ; i >= 0 ; i--){

    if( ans != max_value( 0 , i ) ){

         w_min = i + 1;

         break;

    }

  }

  cout << w_min << endl;  

}





int main(void){



  int cnt = 1;

  while( cin >> wei ){

    memset( dp , -1 , sizeof(dp) );

    //まだ調べてないところを-1で初期化

    if( wei == 0 )break;

    cin >> n;

    char ten;

    for( int i = 0 ; i < n ; i++ ){

      cin >> v[i] >> ten >> w[i];

    }

    cout << "Case " << cnt << ":" << endl;

    int ans = max_value( 0 , wei );

    cout << ans << endl;

    max_weight(ans);

    cnt++;

  }

  return 0;

}