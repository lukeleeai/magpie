#include <iostream>

#include <algorithm>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {

	int A,B,C,D;

	while(cin>>A>>B>>C>>D)

	{

		int ta=max(A,C),tc=min(B,D);

		if(tc-ta<0)

			ta=0;

		else

			ta=tc-ta;

		cout<<ta<<endl;

	}

	

	return 0;

}