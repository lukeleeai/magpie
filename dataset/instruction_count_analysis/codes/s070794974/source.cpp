#include <algorithm>

#include <bitset>

#include <cmath>

#include <ctime>

#include <iostream>

#include <list>

#include <map>

#include <math.h>

#include <numeric>

#include <queue>

#include <set>

#include <stack>

#include <stdio.h>

#include <string>

#include <tuple>

#include <vector>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); i++)

#define all(a) begin(a),end(a)

typedef long long ll;

typedef pair<int,int> P;

const int inf=1e+9;

const ll mod=1000000007;

const double PI=3.14159265358979323846;

int dx[] = {1,-1,0,0};

int dy[] = {0,0,1,-1};

ll gcd(ll a, ll b){

  if (b==0) return a;

  else return gcd(b,a%b);

}

int cans(bool f){

  if(f) cout << "Yes" << endl;

  else cout << "No" << endl;

  return 0;

}













int main() {

  int N;

  cin >> N;

  if(N==1) cout << "Hello World" << endl;

  else {

    int a,b;

    cin >> a >> b;

    cout << a + b << endl;

  }

  return 0;

}


