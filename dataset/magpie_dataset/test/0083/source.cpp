#include <iostream>

#include <string>

using namespace std;

int main(){

	

	string s="", ent;

	cin>>ent;

	

	for(int i=0 ; i<ent.size() ; i++){

		if(ent[i]=='0')

		s += '0';

		else if(ent[i]=='1')

		s += '1'; 

		else if(s.size()>=1){

				s.erase(s.end()-1); 

			}

		

		

	}

	cout<<s<<"\n";

	

	return 0;

	}