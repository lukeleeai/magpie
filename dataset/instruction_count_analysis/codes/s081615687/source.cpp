#include <iostream>

using namespace std;



const int t[8] = { 0, 1, 2, 3, 5, 7, 8, 9 };



/*void solve(int n){

    if(n >= 8)

        solve(n / 8);

    cout << table[n % 8] ;

}*/



long long int solve(int n){

	long long int s=0;

	for(int i=1 ; n >0; i *= 10 , n /= 8)

		s += (long long int)t[n%8]*i;

	return s;

}

int main(){

    int n;

    

    while( cin >> n , n ){

		cout << solve(n) << endl;

    }

    

}