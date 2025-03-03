// CodeForces - 1A

#include"stdc++.h"

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);

    int a, b;

    cin >> a >> b;

    

    if((a % 2 == 0) || (b % 2 == 0))    cout << "Even";

    else    cout << "Odd";

    

    return 0;

}