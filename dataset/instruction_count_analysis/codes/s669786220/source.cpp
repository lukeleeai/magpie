#include <iostream>

#include <math.h>

using namespace std;

//#define ll long long int

int main()

{

    double n;

    cin >> n;

    double ans  = ceil(n/1000);

    //cout << ans << endl;

    double s =(ans*1000) - n;

    if(s == 0)

        cout << 0 << endl;

    else cout << s << endl;

    return 0;



}
