#include <iostream>

#include "stdc++.h"

#include <stdio.h>



typedef long long ll;

using namespace std;







bool isPrime(ll n){

    if(n < 2){

        return 0;

    }

    if(n%2 == 0){

        return n==2;

    }

    for(ll i=3;i*i<=n;i++){

        if(n%i == 0) return 0;

    }

    return 1;

}



string toBinary(int x){

    string s = "";

    while(x > 0){

        if(x%2) s += "1";

        else s += "0";

        x /= 2;

    }

    string h = "";

    for(int i=s.size();i<31;i++){

        h += "0";

    }

    reverse(s.begin(),s.end());

    //cout<<"x "<<x<<" "<<(h+s)<<endl;

    return (h+s);

}



int toInt(string s){

    int h =0;

    for(int i=s.size()-1;i>=0;i--){

        if(s[i] ==  '1') h += pow(2,i);

    }

    return h;

}

int main() {

  // int n,m;

   //freopen("test.txt","w",stdout);

//   while(cin>>n){

//       cin>>m;

//       vector<int> v(n);

//       ll maxy = 0;

//       ll miny = 10e10;

//       for(int i=0;i<n;i++) { cin >> v[i];maxy= max(maxy,(ll)v[i]); }

//       int h = n-m+1;

//      // vector<int> vv;

//       ll k = 0;

//       int nn = 0;

//        int prevIndx = 0;

//        for(int i=0;i<h;i++) k += v[i];

//       for(int i=h;i<n;i++){

//          /* int j = i+1;

//            k += v[i];

//            nn++;

//           while(j<n && nn < h){

//               k += v[j];

//               j++;

//               nn++;

//           }

//         //  vv.push_back(k);

//         if(k < miny) miny = k;

//           k -= v[prevIndx];

//           i = j-1;

//           prevIndx++;

//           nn--;

//           */

//           if(k < miny) miny = k;

//           k -= v[prevIndx];

//           prevIndx++;

//           k += v[i];

//

//       }

//       cout<<max(miny,maxy)<<endl;

//

//   }

    ios_base::sync_with_stdio(false);

    cin.tie(0);

ll n;

cin>>n;

int indx= 1;

string s = "";

while(n > 0){

    n--;

    s += ('a'+(n%26));

    n /= (26);

}

reverse(s.begin(),s.end());

cout<<s<<endl;

return 0;

}
