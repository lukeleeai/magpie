#include "stdc++.h"



#define REP(i,n) for(int i=0;i<(int)(n);i++)



using namespace std;



const string lts = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



pair<string, int> parse(const string &, int);



pair<string, int> letter(const string &s, int i) {

  if (i >= s.size()) throw "last";

  if (s[i] == '+') {

    auto res = letter(s, i+1);

    if (res.first[0] != 'Z')

      ++res.first[0];

    else

      res.first[0] = 'A';

    return res;

  } else if (s[i] == '-') {

    auto res = letter(s, i+1);

    if (res.first[0] != 'A')

      --res.first[0];

    else

      res.first[0] = 'Z';

    return res;

  }

  if ('A' <= s[i] && s[i] <= 'Z')

    return make_pair(string(1, s[i]), i+1);

  else

    throw "bad";

}



pair<string, int> str(const string &s, int i) {

  if (i >= s.size()) throw "last";

  if (s[i] == '[') {

    auto res = parse(s, i+1);

    reverse(begin(res.first),end(res.first));

    if (res.second >= s.size() || s[res.second] != ']') throw "bad";

    ++res.second;

    return res;

  }

  return letter(s, i);

}



pair<string, int> parse(const string &s, int i) {

  auto res = str(s, i);

  while(res.second < s.size() && s[res.second] != ']'){

    auto res2 = str(s, res.second);

    res.first += res2.first;

    res.second = res2.second;

  }

  return res;

}



string search(string &s, int i = 0) {

  if (i >= s.size()) {

    try {

      //cout<<s<<':';

      return parse(s, 0).first;

    } catch(...) {

      return "";

    }

  }

  if (s[i] != '?') return search(s, i+1);

  string res = "";

  for (char c:lts){

    if(!c) break;

    s[i] = c;

    string t = search(s, i+1);

    //cout<<t<<endl;

    if ((t != "" && t < res) || res == "") {

      res = t;

    }

  }

  s[i] = '?';

  return res;

}



int main() {

  while(1){

    string s;

    cin>>s;

    if(s==".") break;

    cout << search(s) << endl;

  }

  return 0;

}