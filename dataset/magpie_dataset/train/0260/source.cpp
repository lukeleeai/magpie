#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cctype>

#include <vector>

using namespace std;



int W, H;

char field[100][100];

string dp[100][100];



bool compare(const string& s1, const string& s2){

  if(s1.size() != s2.size()) return !(s1.size() > s2.size());

  else return !(s1 > s2);

}



void output(){  

  for(int i = 0 ; i < H ; i++){

    for(int j = 0 ; j < W ; j++){

      cout << dp[i][j] << ' ';

    }

    cout << endl;

  }

}



void init(){

  for(int i = 0 ; i < 71 ; i++){

    for(int j = 0 ; j < 71 ; j++){

      dp[i][j] = "";

    }

  }

}



string adjust(string s){

  if(s.size() == 1) return s;

  bool f = false;

  for(int i = 0 ; i < s.size() ; i++){

    if(s[i] != '0') f = true;

  }

  if(!f) return "0";

  for(int i = 0 ; i < s.size() ; i++){

    if(s[i] == '0') continue;

    else{

      //cout << s.substr(i) << endl;

      return s.substr(i);

    }

  }

}



int main(){

  while(cin >> W >> H){

    if(W == 0 && H == 0) break;

    init();

    vector<string> vec;

    vec.clear();

    for(int i = 0 ; i < H ; i++){

      for(int j = 0 ; j < W ; j++){

	cin >> field[i][j];

      }

    }

    

    string ans = "";

    

    for(int i = 0 ; i < H ; i++){

      for(int j = 0 ; j < W ; j++){

	if(!isdigit(field[i][j])) continue;

	if(i == 0 && j == 0) dp[i][j] = field[i][j];

	else if(i == 0) dp[i][j] = dp[i][j-1] + field[i][j];

	else if(j == 0)	dp[i][j] = dp[i-1][j] + field[i][j];

	else dp[i][j] = max(dp[i][j-1]+field[i][j], dp[i-1][j]+field[i][j], compare);

	vec.push_back(dp[i][j]);

      }

    }

    for(int i = 0 ; i < vec.size() ; i++){

      vec[i] = adjust(vec[i]);

      ans = max(ans, vec[i], compare);

    }

    cout << ans << endl;

  }

  return 0;

}