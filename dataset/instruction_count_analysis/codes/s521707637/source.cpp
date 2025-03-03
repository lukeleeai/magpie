// In the name of God



#include "stdc++.h"



using namespace std;



int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	

	int n;

	cin >> n;



	cout << (1000 - (n % 1000)) % 1000;



	return 0;

}
