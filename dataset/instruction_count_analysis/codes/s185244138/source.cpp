#include <iostream> 

using namespace std;   

int main() 

{ 

  int K ; 

  cin >> K ;

  int Even = K / 2 ; 

  int Odd = K - Even ; 

  cout << Even * Odd ; 

  return 0; 

}