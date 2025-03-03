#include <algorithm>

#include <iostream>

#include <string>

#include <unordered_set>

#include <vector>

using std::cin;

using std::cout;

using std::endl;

using std::ios;

using std::string;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  string str;

  int count = 0;

  cin >> str;

  char t = str[0];

  for (int i = 1; i < str.size(); i++) {

    if (str[i] != t) {

      count++;

      t = str[i];

    }

  }

  cout << count << endl;

  return 0;

}
