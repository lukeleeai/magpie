#include<cstdio>

#include<iostream>



using namespace std;



typedef long long ll;

ll a, b, x, ans;



int main(){

	char c;

	while(~scanf("%c", &c)){

		getchar();

		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

			cout << "vowel" << endl;

		else

			cout << "consonant" << endl;

	}

	return 0;

}