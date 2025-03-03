#include <iostream>

using namespace std;

int main() {

   long long x,y,answer=0;

   cin>>x>>y;

   for(long long i=x;i<=y;i*=2)

   answer++;

   cout<<answer;

}
