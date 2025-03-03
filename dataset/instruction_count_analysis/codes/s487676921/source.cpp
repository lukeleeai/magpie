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

  int freq[100001] = {0};

  for (int i=0; i<n; i++){

      cin >> arr[i];

      freq[arr[i]]++;

  }

  

  set<int> modded[100001];

  for (int i=0; i<n; i++){

      modded[arr[i]%m].insert(arr[i]);

  }

  int pairs = 0;

  set<int> zeros = modded[0]; 

  int summ = 0;

  for (int i : zeros){

      summ += freq[i];

  }

  pairs += summ/2;

 

  int cur;

  set<int> mids = modded[m/2];

  if (m%2 == 0){

      summ = 0;

      for (int i : mids){

          summ += freq[i];

      }

      pairs += summ/2;

  }

  

  // for rest, for least similar ones pair w/ other num

  for (int i=1; i<m/2+m%2; i++){

      set<int> one = modded[i];

      set<int> two = modded[m-i];

      vector<int> freq11;

      vector<int> freq22;

      int sum1 = 0;

      int sum2 = 0;

      for (int j : one){

          freq11.push_back(freq[j]);

          sum1 += freq[j];

      }

      for (int j : two){

          freq22.push_back(freq[j]);

          sum2 += freq[j];

      }

      int left = abs(sum1-sum2)-abs(sum1-sum2)%2;

      pairs += min(sum1, sum2);



      if (sum1 > sum2){

          for (int i=0; i<freq11.size() && left > 0; i++){

              if (freq11[i]-freq11[i]%2 >= left){

                  pairs += left/2;

                  break;

              }else{

                  pairs += freq11[i]/2;

                  left -= freq11[i]-freq11[i]%2;

              }

          }

      }else{

          for (int i=0; i<freq22.size() && left > 0; i++){

              if (freq22[i]-freq22[i]%2 >= left){

                  pairs += left/2;

                  break;

              }else{

                  pairs += freq22[i]/2;

                  left -= freq22[i]-freq22[i]%2;

              }

          }

      }

  }

  cout << pairs;

  return 0; 

}