#include "stdc++.h"

using namespace std;



#define rep(i,n) for(int i=0;i<n;i++)

#define ll long long



int main(){

    string s;

    cin>>s;

    int n=s.size();

    rep(i,n-1){

        if(s[i]=='B'&&s[i+1]=='C') s[i]='K',s[i+1]='D';

    }

    reverse(s.begin(),s.end());

    ll k=0,cnt=0;

    rep(i,n){

        if(s[i]=='K') k++;

        else if(s[i]=='A') cnt+=k;

        else if(s[i]!='D') k=0;

    }

    cout<<cnt<<endl;

}
