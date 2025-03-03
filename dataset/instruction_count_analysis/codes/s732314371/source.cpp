#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

#include <string>

#include <queue>

#define ll long long



using namespace std;





int main(void){

   ll n, m;

   cin >> n >> m;

   vector<pair<ll, ll>> check;

   for(ll i = 0; i <= 1000; i++){

      check.emplace_back(i, 0);

      //cout << check[i].first << " " << check[i].second << endl;

   }

   if(m > 0){

      for(ll i = 0; i < m; i++){

         ll s, c;

         cin >> s >> c;

         for(ll i = 0; i < 1000; i++){

            string str = to_string(i);

            string cc = to_string(c);

            if(str[s-1] != cc[0] || str.length()!=n)

               check[i].second = 1;

         }

      }

      for(ll i = 0; i < 1000; i++){

         //cout << i << " " << check[i].second << endl;

         if(check[i].second==0){

            cout << i << endl;

            break;

         }

         if(i == 999)

            cout << -1 << endl;

      }

   }

   else if(m == 0){

      if(n==1)

         cout << 0 << endl;

      if(n==2)

         cout << 10 << endl;

      if(n==3)

         cout << 100 << endl;

   }

   return 0;

}
