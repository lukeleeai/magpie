#include <iostream>

#include <map>



using namespace std;



#define repd(i,a,b) for (int i=(a);i<(b);++i)

#define rep(i,n) repd(i,0,n)



int main(){

  string s;

  cin >> s;

  map<char, int> mp;

  rep(i, s.size()){

    mp[s[i]] += 1;

  }

  for(auto value: mp){

    if(value.second != 2){

      cout << "No" << endl;

      return 0;

    }

  }

  cout << "Yes" << endl;

  return 0;

}