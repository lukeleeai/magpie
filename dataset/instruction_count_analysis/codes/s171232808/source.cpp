#include "stdc++.h"

using namespace std;

int main(){

   int n,w=0,b=0;

   string s;

   cin >> n >> s;

   for(int i=0;i<n;i++){

       if(s[i]=='.') w++;

   }

   int ans = w;

   for(int i=0;i<n;i++){

       if(s[i]=='#') b++;

       else w--;

       ans = min(ans,b+w);

   }

   cout << ans << endl;

}