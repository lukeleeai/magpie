#include<iostream>

#include<vector>

#include<sstream>

#include<cmath>



using namespace std;



const int MAX = 13;

vector<double> Cake;

double box;

double dp[(1<<MAX)][MAX];



void init(){

  Cake.clear();

  fill(dp[0],dp[0]+(1<<MAX)*MAX,100000000);

  dp[0][0] = 0;

}



void make(){

  string s;

  getline(cin,s);

  stringstream ss(s);

  double num;

  while(ss >> num) Cake.push_back(num);

}



void solve(){





  for(int i = 0; i < (1<<Cake.size()); i++)

    for(int j = 0; j < (int)Cake.size(); j++){

      if(i == 0) {dp[(1<<j)][j] = Cake[j]; continue;}

      for(int k = 0; k < (int)Cake.size(); k++)

	if(!(i&(1<<k)) && j != k){

	  dp[i+(1<<k)][k] = min(dp[i+(1<<k)][k],dp[i][j]+2.0*sqrt(Cake[j]*Cake[k]));

	  //	  if(dp[i][j] == 0) cout << "error" << endl;

	}

    }



  for(int i = 0; i < (int)Cake.size(); i++){

    //    cout << "cake " << Cake[i] << endl;

    //cout << dp[(1<<Cake.size())-1][i]+Cake[i] << endl;

    if(dp[(1<<Cake.size())-1][i]+Cake[i] <= box) {cout << "OK" << endl;return;}

  }

  cout << "NA" << endl;

}



int main(){



  while(cin >> box){

    init();

    make();

    solve();

  }

  return 0;

}