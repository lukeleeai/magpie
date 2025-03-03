/*Lucky_Glass*/

#include"stdc++.h"

using namespace std;

string A,B;

int totA[26],totB[26];

int main(){

	cin>>A>>B;

	for(int i=0;i<A.length();i++)

		totA[A[i]-'a']++;

	for(int i=0;i<B.length();i++)

		totB[B[i]-'a']++;

	sort(totA,totA+26);

	sort(totB,totB+26);

	for(int i=0;i<26;i++)

		if(totA[i]!=totB[i]){

			printf("No\n");

			return 0;

		}

	printf("Yes");

	return 0;

}//