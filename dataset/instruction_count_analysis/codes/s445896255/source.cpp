#include <iostream>

#include <algorithm>

using namespace std;



int main()

{

    long long n, m;

    cin >> n >> m;

    if(n == 2 || m == 2) cout << 0;

    else if(min(n, m) == 1){

        int maximum = max(n, m);

        cout << (maximum == 1 ? 1 : maximum - 2);

    } else 

        cout << (m-2)*(n-2);

    

    return 0;

}