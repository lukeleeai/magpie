#include"stdc++.h"



using namespace std;





typedef long long ll;

const ll maxn=1e5;

string str[maxn];

int idex;

void solve(string a ){

	int len=a.length();

	for(int i=0;i<len-2;i++){

		if(a[i]=='A'&&a[i+1]=='B') idex++;

	}

}

int main()

{

	int n;

	cin>>n;

	idex=0;

	int ta=0,tb=0;

	int ans;

	int res=0;

	for(int i=0;i<n;i++){

		cin>>str[i];

		int len=str[i].length();

		if(str[i][0]=='B') tb++;

		if(str[i][len-1]=='A') ta++;

		if(str[i][0]=='B'||str[i][len-1]=='A') res+=1;

 	}

	for(int i=0;i<n;i++){

		solve(str[i]);

	}	

	if(res==0) ans=min(ta,tb); 

	else ans=min(min(ta,tb),res-1);

	idex+=ans;

	cout<<idex<<endl;

	return 0;

}
