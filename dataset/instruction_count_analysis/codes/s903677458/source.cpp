#include<iostream>

#include<string>

#include<algorithm>

#include<map>

#include<set>

#include<utility>

#include<vector>

#include<cmath>

#include<cstring>

#include<cstdio>

#include<time.h>

#define loop(i,a,b) for(int i=a;i<b;i++) 

#define rep(i,a) loop(i,0,a)

#define pb push_back

#define mp make_pair

#define all(in) in.begin(),in.end()

const double PI=acos(-1);

const double EPS=1e-10;

const int inf=1e8;

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<vi> vvi;

int main(){

	int n;

	cin>>n;

	string s;

	getline(cin,s);

	while(n--){

		getline(cin,s);

		bool h=false;

		rep(i,26){

			string tmp;

			rep(j,26){

				tmp=s;

				rep(k,tmp.size())if(isalpha(tmp[k]))tmp[k]=(i*(tmp[k]-'a')+j)%26+'a';

				rep(k,tmp.size()-3){

					string a=tmp.substr(k,4);

					if(a=="this"||a=="that"){h=true;break;}

				}

				if(h)break;

			}

			if(h){s=tmp;break;}

		}

		cout<<s<<endl;;

	}

}