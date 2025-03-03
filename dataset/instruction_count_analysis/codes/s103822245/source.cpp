#include"stdc++.h"

#define MAXN 95555

using namespace std;



vector<int> Prime;

int flag[MAXN];

void siv() {

  Prime.push_back(2);

  for(int i = 4 ; i <= MAXN ; i += 2) flag[i] = 1;

  for(int i = 3 ; i * i <= MAXN ; i += 2) {

    if(!flag[i]) {

      for(int j = i * i , k = (i * 2) ; j <= MAXN ; j += k) {

        flag[j] = 1;

      }

    }

  }

  for(int i = 3 ; i < MAXN ; i += 2) {

    if(!flag[i]) {

      Prime.push_back(i);

    }

  }

}



int main()

{

  siv();

  int n;

  cin >> n;

  for(int i = 0 , ans = 0 ; i < Prime.size() && ans != n ; i++) {

    if(Prime[i] % 5 == 1) ans++ , printf("%d ", Prime[i]);

    //if(Prime[i] % 5 == 2) ans++ , printf("%d ", Prime[i]);

    //if(Prime[i] % 5 == 3) ans++ , printf("%d ", Prime[i]);

    //if(Prime[i] % 5 == 4) ans++ , printf("%d ", Prime[i]);

  }

}
