#include <iostream> 

#include <string>

using namespace std;



string arr;

char s[100],n=1;

int main(){

	cin>>arr;

	s[0]=arr[0];

	for(int i=1;i<arr.length();i++){

		int fase=1; 

		for(int j=0;j<n;j++){

			if(arr[i]==s[j]){

				fase=0;

			} 

		}

		if(fase){

			s[n]=arr[i];

			n++; 

		}

	}

	if(n==2){

		cout<<"Yes";

	}else{

		cout<<"No";

	}

	return 0; 

} 