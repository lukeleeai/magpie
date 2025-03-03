#include"stdc++.h"

using namespace std;

#define ll long long 

#define mod 1000000007

#define first f

#define second s

#define N 1000000

vector<ll>v(N);

ll l,m,n,sum,ans,maximum,minimum,mahakal,a,b,c,t,i,j,k;

ll cnt,cnt1,cnt2,cnt3;

string str,str1,str2;

ll arr[N];

int main(){

    cin>>n;

  cin>>str;

  if(n&1){

    cout<<"No"<<endl;

    return 0;

  }

  str1=str.substr(0,n/2);

  str2=str.substr(n/2,n/2);

  //cout<<str1<<" "<<str2<<endl;

  if(str1==str2){

      cout<<"Yes"<<endl;

  }

  else{

      cout<<"No"<<endl;

  }

  

    return 0;

}