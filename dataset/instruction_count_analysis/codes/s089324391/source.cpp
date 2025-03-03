#include <iostream>

#include <cstdio>

#include <algorithm>

#include <string>

#include <cstring>



using namespace std;

int main() {

	char str[100];

	int cnt[130] = { 0 };

	cin >> str;

	int len = strlen(str);

	for (int i = 0; i <len; i++) {

		int k = (int)(str[i] - 'a');

		cnt[k]++;

		if (cnt[k] > 1) {

			cout << "no" << endl;

			system("pause");

			return 0;

		}

	}

	cout << "yes" << endl;





	system("pause");

	return 0;

}