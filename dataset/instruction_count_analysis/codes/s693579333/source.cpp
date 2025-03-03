#include "stdc++.h"

using namespace std;



int main(){

	int n;

  	cin>>n;

    string s;

  	cin>>s;

  	int mymax=0;

  	int ans=0;

  	

  	for (int i=0;i<n;i++){

  		if(s.at(i)=='I'){

        	ans++;	

        }

      	if(s.at(i)=='D'){

        	ans--;

        }

      	mymax=max(mymax,ans);

    }

  	cout<<mymax<<endl;

  	

}    


