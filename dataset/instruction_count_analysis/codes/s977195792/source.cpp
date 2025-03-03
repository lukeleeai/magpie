#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<cmath>

#include<ctime>

#include<iostream>

#include<algorithm>

#include<map>

#include<stack>

#include<queue>

#include<vector>

#include<set>

#include<string>

#define ll long long

#define dd double

using namespace std;



int main(){

	string s[10005];

	string st="";

	ll a[10005][3]={0};

	memset(a,0,sizeof(a));

	ll n;cin>>n;

	for(ll i=0;i<n;i++){

		cin>>s[i];

		if(s[i][0]=='B'){

			a[i][0]++;

		}

		if(s[i][s[i].size()-1]=='A'){

			a[i][1]++;

		}

	}

	ll flag=0;

	for(ll i=0;i<n;i++){

		if(a[i][0]==0&&a[i][1]!=0){

			flag=1;

			st+=s[i];

			a[i][2]=-1;

			break;

		}

	}

	ll q=0;

	if(flag==1){

		for(ll i=0;i<n;i++){

			if(a[i][2]==-1){

				continue;

			}

			else{

				if(a[i][0]!=0&&a[i][1]!=0){

					st+=s[i];

					a[i][2]=-1;

				}

			}

		}

		for(ll i=0;i<n;i++){

			if(a[i][2]==-1){

				continue;

			}

			else{

				if(a[i][0]!=0){

					st+=s[i];

					a[i][2]=-1;

					break;

				}

			}

		}

		for(ll i=0;i<n;i++){

			if(a[i][2]==-1){

				continue;

			}

			else{

				if(q%2==0){

					if(a[i][1]!=0){

						st+=s[i];

						a[i][2]=-1;

						i=-1;

						q++;

					}

				}

				else{

					if(a[i][0]!=0){

						st+=s[i];

						a[i][2]=-1;

						i=-1;

						q++;

					}

				}

			}

		}

		for(ll i=0;i<n;i++){

			if(a[i][2]!=-1){

				st+=s[i];

				a[i][2]=-1;

			}

		}

	}

	if(flag==0){

		for(ll i=0;i<n;i++){

			if(a[i][1]!=0&&a[i][2]!=-1){

				st+=s[i];

				a[i][2]=-1;

				break;

			}

		}

		for(ll i=0;i<n;i++){

			if(a[i][2]==-1){

				continue;

			}

			else{

				if(a[i][0]!=0&&a[i][1]!=0){

					st+=s[i];

					a[i][2]=-1;

				}

			}

		}

		for(ll i=0;i<n;i++){

			if(a[i][2]==-1){

				continue;

			}

			else{

				if(a[i][0]!=0){

					st+=s[i];

					a[i][2]=-1;

				}

			}

		}

		for(ll i=0;i<n;i++){

			if(a[i][2]!=-1){

				st+=s[i];

				a[i][2]=-1;

			}

		}

	}

	ll count = 0;

	for(ll i=0;i<st.size()-1;i++){

		if(st[i]=='A'&&st[i+1]=='B'){

			count++;

		}

	}

	cout<<count<<endl;

} 