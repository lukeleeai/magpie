#include"stdc++.h"

using namespace std;

int main(){

	string s;

	cin>>s;

	int q;

	cin>>q;

	int flag=0;

	while(q--){

		int k;

		cin>>k;

		if(k==1)flag++;

		else{

			int f;

			char c;

			cin>>f>>c;

			if(f==1){

				if(flag%2==0)

				s.insert(s.begin(),c);

				else s.insert(s.end(),c);

				

			}

			else{

				if(flag%2==0)s.insert(s.end(),c);

				else s.insert(s.begin(),c);

			}

		}

	}

	if(flag%2)reverse(s.begin(),s.end());

	cout<<s<<endl;

	return 0;

}