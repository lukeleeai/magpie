#include<iostream>

#include<cstring>

using namespace std;

int main(){

	string a;

	int len;

	cin>>a;

	len=a.length()-1;

	if(a[len]=='2'||a[len]=='4'||a[len]=='5'||a[len]=='7'||a[len]=='9'){

		cout<<"hon"<<endl;

	}else if(a[len]=='0'||a[len]=='1'||a[len]=='6'||a[len]=='8'){

		cout<<"pon"<<endl;

	}else if(a[len]=='3'){

		cout<<"bon"<<endl;

	}

	return 0;

}