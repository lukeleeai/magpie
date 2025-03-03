#include <iostream>



using namespace std;



bool prime_check(int n, int k)

{

    if(k * k > n) { return true; }



    if(n % k == 0) { return false; }



    return prime_check(n, k + 1);

}



int bool_to_int(bool a)

{

    if(a == true) { return -1; }



    return 0;

}



int main()

{

    const int DATASETS = 10000;



    int n, k = 0, data[DATASETS];



    cin >> n;



    for(int i = 0; i < n; i++) { cin >> data[i]; }



    for(int i = 0; i < n; i++) { k -= bool_to_int(prime_check(data[i], 2)); }



    cout << k << endl;



    return 0;

}