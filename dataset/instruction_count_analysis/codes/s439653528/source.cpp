#include<iostream>

#include<vector>

#include<algorithm>



using namespace std;



int main(void) {

	int n;



	cin >> n;



	vector<int> a(n);



	for (int i = 0; i < n; i++) {

		cin >> a[i];

	}



	sort(a.begin(), a.end());

	

	a.erase(unique(a.begin(), a.end()),a.end());



	if (a.size() % 2 == 0) {

		cout << a.size()-1 << endl;

	}

	else {

		cout << a.size() << endl;

	}

	return 0;

}