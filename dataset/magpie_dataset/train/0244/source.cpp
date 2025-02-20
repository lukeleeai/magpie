#include<iostream>

#include<algorithm>

using namespace std;



int main(){

  int n,s,r[20200];



  while(cin >> n >> s,n){

    for(int i=0;i<n;i++)cin >> r[i];

    sort(r,r+n);



    int ans = 0;

    for(int i=0;i<n;i++){

      ans += n - (upper_bound(r+i+1,r+n,s-r[i]) - r);

    }

    cout << ans << endl;

  }

}