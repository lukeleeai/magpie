#include<iostream>



using namespace std;

int main(){

   int x, y;

   cin >> x >> y;

   int hi = max(x, y);

   int n;

   cin >> n;

   int op;

   if(n % hi == 0)

    op = (n / hi);

   else op = (n / hi) + 1;

   cout << op;

}
