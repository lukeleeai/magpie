#include<iostream>

#include<algorithm>

using namespace std;



typedef long long ll;



int main(){

  ll i,n,num,len,p,l[100000];

  while(cin >> n,n){

    num = n; len = 0;

    for(i=0;i<n;i++){

      cin >> p; len += p;

    }



    for(i=0;i<n-1;i++)cin >> l[i];

    sort(l,l+n-1);



    for(i=n-2;i>=0;i--){

      if( (num-1)*(len+l[i]) < num*len )break;

      num--; len += l[i];

    }

    cout << num*len << endl;

  }

}

   