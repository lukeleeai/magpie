#include<iostream>

#include<string>

#include<algorithm>

#include<map>

#include<set>

#include<utility>

#include<vector>

#include<cmath>

#include<cstdio>

#define loop(i,a,b) for(int i=a;i<b;i++) 

#define rep(i,a) loop(i,0,a)

#define pb push_back

#define mp make_pair

#define it ::iterator

#define all(in) in.begin(),in.end()

const double PI=acos(-1);

const double ESP=1e-10;

using namespace std;

int main(){

  int n;

  cin>>n;

  rep(i,n){

    string s;

    string ans;

    bool han=false;

    if(i==0)getline(cin,s);

    getline(cin,s);

    rep(a,27){

      rep(b,27){

	string tmp=s;

	rep(j,tmp.size())if(isalpha(tmp[j]))tmp[j]=(a*(tmp[j]-'a')+b)%26+'a';

	rep(j,tmp.size()-3){

	  if(tmp.substr(j,4)=="this"){ans=tmp;han=true;}

	  if(tmp.substr(j,4)=="that"){ans=tmp;han=true;}

	}

	if(han==true)break;

      }

      if(han==true)break;

    }

    cout<<ans<<endl;

  }





}