#include "stdc++.h"

using namespace std;

#define show(x) cout << #x << " : " << x << endl;



int main ()

{

 string s;

 cin >> s;

 map < char, int > mp;

 int i, cnt = 0;

 for(i = 0; i < 4; i++)

 {

   mp[s[i]]++;

   if(mp[s[i]] == 2) cnt++;

   if(cnt == 2)

   {

     cout << "Yes" << endl;

     exit(0);

   }

 }

 cout << "No" << endl;

}