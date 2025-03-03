#include<iostream>

#include<string>

#include<cstdlib>

#include<vector>

#include<algorithm>

#include<functional>



#define REP(i,n) for(int i=0;i<n;i++)

#define ll long long int



using namespace std;



int to_int(string s) {

  return atoi(s.c_str());

}



//vector<ll> a;



int main() {

  int n;

  cin >> n;



 // a.reserve(n);

  vector<int> a(300000);

  for(int i=0;i<n;i++) {

    cin >> a[i];

    a[i] -= i+1;

  }



  sort(a.begin(), a.begin()+n);

  long long  b;

  if(n%2 == 0) {

    b = a[n/2 -1];

  } else {

    b = a[(n-1)/2];

  }



  long long  r = 0;



  for(int i=0;i<n;i++) {

    r += abs(a[i] - b);

  }



  cout << r << endl;

return 0;

}
