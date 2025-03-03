#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <set>

#include <cmath>

#include <stdio.h>

#include <list>

#include <numeric>

#include <stack>

#include <queue>

#include <tuple>

#include <bitset>

#include <map>

#include <math.h>

//　ceil(a/b)   (a + (b - 1))/ b

using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

typedef long long ll;

typedef pair<int,int> P;

const int inf = 1012345678;

int dx[] = {1,-1,0,0};

int dy[] = {0,0,1,-1};



// int gcd(int a, int b){

//   if (a%b==0){

//     return(b);

//   }

//   else{

//     return(gcd(b,a%b));

//   }

// }





vector<int> v[100001];

int c[100000];

int y[100000];



int main(){

  int n;

  cin >> n;

  if(n == 1) cout << "Hello World" << endl;

  else {

    int a, b;

    cin >> a >> b;

    cout << a+b << endl;

  }

}


