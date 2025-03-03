#include"stdc++.h"

using namespace std;

#define ll long long 

ll n,m,cur;

int main(){

  vector<ll> ans;

  string s;

  cin>>n>>m>>s;

  cur=n;

  while(cur)

  {

  	 bool check=true;

  	 for(int i=max(0ll,cur-m);i<cur;i++)

  	    if(s[i]=='0'){

  	    	check=false;

  	    	ans.push_back(cur-i);

  	    	cur=i;

  	    	break;

  	    }

  	  if(check){

  	  	cout<<-1<<endl;return 0;

  	  }

  }

  reverse(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++){

  	  cout<<ans[i];

  	  if(i==ans.size()-1)cout<<endl;

  	  else cout<<" ";

  }







	return 0;

}
