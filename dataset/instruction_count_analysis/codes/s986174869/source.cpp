#include <iostream>

#include <algorithm>

using namespace std;

long long n , x;



int main(){

  cin >> n >> x;

  cout << 3 * (n - __gcd(n , x)) << endl;

  return 0;

}
