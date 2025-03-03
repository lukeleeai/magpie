#include "stdc++.h"



#define REP(i,n) for(int i=0;i<(int)(n);i++)



using namespace std;



pair<string, int> cipher(const string& s, int pos = 0);



pair<string, int> letter(const string& s, int pos) {

  if (s[pos] == '+') {

    string res;

    tie(res, pos) = letter(s, pos+1);

    if (res == "?") {

      return make_pair(res, pos);

    } else if (res == "Z") {

      res[0] = 'A';

      return make_pair(res, pos);

    } else {

      ++res[0];

      return make_pair(res, pos);

    }

  } else if (s[pos] == '-') {

    string res;

    tie(res, pos) = letter(s, pos+1);

    if (res == "?") {

      return make_pair(res, pos);

    } else if (res == "A") {

      res[0] = 'Z';

      return make_pair(res, pos);

    } else {

      --res[0];

      return make_pair(res, pos);

    }

  } else {

    return make_pair(s.substr(pos, 1), pos+1);

  }

}



pair<string, int> string_p(const string& s, int pos) {

  if (s[pos] == '[') {

    string res;

    tie(res, pos) = cipher(s, pos+1);

    reverse(begin(res),end(res));

    return make_pair(res, pos+1);

  } else {

    return letter(s, pos);

  }

}



pair<string, int> cipher(const string& s, int pos) {

  string res;

  string str;

  do {

    tie(str, pos) = string_p(s, pos);

    res += str;

  } while(pos < s.size() && s[pos] != ']');

  return make_pair(res, pos);

}



string convert(const string& s) {

  auto p = cipher(s).first;

  replace(begin(p),end(p),'?','A');

  return p;

}



int main() {

  while(1){

    string s;

    cin>>s;

    if (s == ".") break;

    cout << convert(s) << endl;

  }

  return 0;

}