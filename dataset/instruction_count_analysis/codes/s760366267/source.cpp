#include<iostream>

#include<algorithm>

#include<set>

#include<vector>

#include<queue>

#include<deque>

#include<map>

#include<cstdio>

#include<cstring>

#include<string>

#include<cstdlib>

#include<cmath>

using namespace std;



#define REP(i,a,n) for(int i = a; i < n ; i++)

#define rep(i,n) REP(i,0,n)



typedef long long ll;



string ts;

string s;

int idx;



int NOT[] = {2,1,0};

int AND[3][3] = {{0,0,0},{0,1,1},{0,1,2}};

int OR[3][3] = {{0,1,2},{1,1,2},{2,2,2}};



int solve();



int getDigit(){

  int cnt = 0;

  while(s[idx] == '-'){

    cnt++;

    idx++;

  }



  int digit = -1;

  if(s[idx] == '('){

    idx++;

    digit = solve();

  }

  else{

    digit = s[idx] - '0';

    idx++;

  }



  if(cnt % 2 == 1){

    return NOT[digit];

  }

  return digit;

}



int solve(){

  int res = 0;



  //cout<<":"<<idx<<endl;



  int left = -1;

  int right = -1;



  if(s[idx] == '('){

    idx++;

    left = solve();

  }

  else{

    left = getDigit();

  }



  if(idx < s.length()){

    if(s[idx] == '*'){

      idx++;

      if(s[idx] == '('){

        idx++;

        right = solve();

      }

      else{

        right = getDigit();

      }



      res = AND[left][right];

    }

    else if(s[idx] == '+'){

      idx++;

      if(s[idx] == '('){

        idx++;

        right = solve();

      }

      else{

        right = getDigit();

      }



      res = OR[left][right];

    }

  }

  idx++;



  if(right == -1){

    return left;

  }

  else{

    return res;

  }

}



void replace(int R,int P,int Q){

  s = "";

  rep(i,ts.size()){

    if(ts[i] == 'R') s += (char)('0' + R);

    else if(ts[i] == 'P') s += (char)('0' + P);

    else if(ts[i] == 'Q') s += (char)('0' + Q);

    else{

      s += ts[i];

    }

  }

}



int main(){

  while(cin>>ts,ts!="."){

    int ans = 0;

    rep(R,3) rep(P,3) rep(Q,3){

      replace(R,P,Q);

      idx = 0;

      if(solve() == 2) ans++;

    }

    cout<<ans<<endl;

  }

}