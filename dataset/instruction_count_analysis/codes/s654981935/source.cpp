#include"stdc++.h"

using namespace std;



int main(){

	string s;

	cin>>s;

	

	long long int len;

	len=s.size();

	

long long	i=0;

	long long int lt=0,gt=0,ans=0;

	

	while(i<len){

		

		while(i<len&&s[i]=='<'){

			lt++;

			i++;

		}

		while(i<len&&s[i]=='>'){

			gt++;

			i++;

		}

		

		if(lt==0){

			ans+=(gt*(gt+1))/2;

		}

		else if(gt==0){

			ans+=(lt*(lt+1))/2;

		}

		else{

			ans+=max(gt,lt)+((gt-1)*gt)/2+((lt-1)*lt)/2;

		}

		lt=0;gt=0;

			}

	cout<<ans;

}