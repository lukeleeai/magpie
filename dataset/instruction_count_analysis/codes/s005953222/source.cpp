#include "stdc++.h"

using namespace std;

const int c = 300000;

int main(){

   int n,b[c]={},w[c]={},ans=c;

   string s;

   cin >> n >> s;

   for(int i=0;i<n;i++){

       int flag = 0,flag1=0;

       if(s[i]=='#') flag++;

       b[i+1] = b[i] + flag;

       if(s[n-i-1]=='.') flag1++;

       w[i+1] = w[i] + flag1;

   }

   reverse(w,w+n+1);

   for(int i=0;i<=n;i++) ans = min(ans,b[i]+w[i]);

   cout << ans << endl;

}