#include "stdc++.h"

 

using namespace std;

inline void prep ()

{

  cin.tie (0);

  cin.sync_with_stdio (0);

};

const double pi = acos(-1.);

//printf(%.12lf\n,mid);

// __builtin_popcount(int) count 1's in binary

// get decimal part of number

/*

double intpart;

double thiss = modf((double)(n*m)/(double)k, &intpart);

*/

// round = (int)(num+.5)

long long mod = 1000000007;

 

long long mymod(long long num){

  if (num< 0 && !(num%mod == 0)){

    if (mod == 1){

      return 0;

    }

    return mod-abs(num)%mod;

  }else{

    return num%mod;

  }

}

 

/*string sentence = And I feel fine...;

    istringstream iss(sentence);

*/  

 

double eps = .000000001;

 

 

int main ()

{

  prep();

  int n, m;

  cin >> n >> m;

  int arr[n];

  int modfreq[100001] = {0};

  int freq[100001];

  int divmodfreq[100001] = {0};

  for (int i=0; i<n; i++){

      cin >> arr[i];

      freq[arr[i]]++;

      modfreq[arr[i]%m]++;

  }

  for (int i=0; i<=100001; i++){

      divmodfreq[i%m] += freq[i]/2;

  }

  int pairs = modfreq[0]/2;



  if (m%2 == 0){

      pairs += modfreq[m/2]/2;

  }

  

  // for rest, for least similar ones pair w/ other num

  for (int i=1; i<m/2+m%2; i++){

      int one = modfreq[i];

      int two = modfreq[m-i];

      // subtract intersection

      int diff = abs(one-two)/2;

      pairs += min(one, two);

      if (one > two){

          // get div 2

          int many = divmodfreq[i];

          pairs += min(many, diff);

      }else{

          int many = divmodfreq[m-i];

          pairs += min(many, diff);

      }

  }

  cout << pairs;

  return 0; 

}