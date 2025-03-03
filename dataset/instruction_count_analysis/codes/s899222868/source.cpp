#include<iostream>

#include <algorithm>

#include <vector>

using namespace std;



int N;



typedef long long ll;



ll T = 0,AO = 0,ans = 0;



struct Data {

  ll  A,B,C;

};



int main() {

  cin >> N;

  vector<Data> data(N);

  for ( int i = 0; i < N; i++ ) {

    cin >> data[i].A >> data[i].B;

    data[i].C = data[i].A + data[i].B;

  }



   sort(data.begin(),data.end(),[](const Data &l, const Data&r){

  				 return (l.C > r.C); });

 

  

 bool f = true;

 for ( int i = 0; i < N; i++ ) {

    if (f)  {

      T += data[i].A;

       f = false;

    }

    else {

      AO += data[i].B;

       f = true;

    }

  }

  ans = T - AO;

    cout << ans << endl;

  

  return 0;

}
