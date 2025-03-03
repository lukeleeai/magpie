// #include<stdio.h>

#include<iostream>

#include<string.h>

using namespace std;

int main(void) {

	int j = 0;

    string s,t;

//	char s[200000], t[200000];

	// scanf("%s", &s);

	// scanf("%s", &t);

    cin >> s >> t;



	for (int i = 0; i <s.size(); i++){

		if (s[i] != t[i]){

			j++;

        }

    }



	// printf("%d", j);

    cout << j << endl;

	return 0;

}