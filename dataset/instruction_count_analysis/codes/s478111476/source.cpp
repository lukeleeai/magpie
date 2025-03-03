#include <cstdio>

#include <iostream>

#include <algorithm>





using namespace std;



int main(){

	int n, k, c = 0, an, i;

	char s[100005] = { '\0' };

	

	cin >> n >> k;

	for (i = 0; i < n; i++){

		cin >> s[i];

	}

	int count = 0;

	i = 0;

	if (s[i] == 'R'&&s[i + 1] == 'R') count++;

	for (i = 1; i < n - 1; i++){

		if (s[i] == 'L'&&s[i - 1] == 'L') count++;

		if (s[i] == 'R'&&s[i + 1] == 'R') count++;

	}

	if (s[i] == 'L'&&s[i - 1] == 'L') count++;

//	for(i = 0; i < n-1; i++){

//		if (s[i] != s[i + 1]) c++;

//	}

//	cout << count << endl;

	an = min((count + 2 * k), (n - 1));

	cout << an;

	system("pause");

	return 0;

}