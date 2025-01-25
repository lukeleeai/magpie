#include <iostream>

#include <string>

#include <algorithm>

#include <stack>

#include <queue>

using namespace std;



int func(int kaidan,int now){

	int a=0,b=0,c=0;

	

	if(now==kaidan){

		return 1;

	}else if(now>kaidan){

		return 0;

		}else{

		a+=func(kaidan,now+1);

		b+=func(kaidan,now+2);	

		c+=func(kaidan,now+3);

		}

	

	return a+b+c;

	

}



int main(){

	int n,ans;



	while(cin>>n){

		if(n==0)break;

		ans=func(n,0);

		cout<<ans/10/365+1<<endl;

		

		

		

	}

	

	

	return 0;

}