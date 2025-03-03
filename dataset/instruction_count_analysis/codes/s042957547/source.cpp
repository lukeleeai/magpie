#include<cstdio>

#include<iostream>

#include<cstring>

 

using namespace std;

//初始化 

void initial(string &a, string &b){

	while (a.size()<b.size())a = '0' + a;

	while (b.size()<a.size())b = '0' + b;

}

//找出最大的字符串 

void findMax(string &a, string &b){

	string tmp;

	if (a<b){

		tmp = b;

		b = a;

		a = tmp;

	}

}

//删除第一个字符'0' 

bool del(string &a){

	if (a[0] == '0'){

		a.erase(0, 1);

		return true;

	}

	else

		return false;

}

//删除前面所有的 0 

void delAllZroe(string &a){

	while (del(a)){

		del(a);

	};

}

//大数加法 

string bigItergeAdd(string a, string b){

	initial(a, b);

	a = '0' + a;

	b = '0' + b;

	for (int i = a.size() - 1; i >= 0; i--){

		int num1 = a[i] - '0';

		int num2 = b[i] - '0';

		if (num1 + num2>9){

			a[i - 1] = a[i - 1] - '0' + 1 + '0';

			a[i] = (num1 + num2) - 10 + '0';

		}

		else{

			a[i] = (num1 + num2) + '0';

		}

	}

	del(a);

	//	cout<<a<<endl;

	return a;

}

//大数乘法(大数加法实现) 

void bigItergeMul(string a, string b){

	delAllZroe(a);

	delAllZroe(b);

	if (a == "" || b == ""){ printf("0\n"); return; }

	initial(a, b);

	findMax(a, b);

	string res = "0";

	int count = 0;

	delAllZroe(b);

	for (int i = b.size() - 1; i >= 0; i--){

		int num1 = b[i] - '0';

		if (i != b.size() - 1)		a = a + '0';

		for (int i = 1; i <= num1; i++){

			res = bigItergeAdd(res, a);

		}

	}

	delAllZroe(res);

	if (res.size()<3){ printf("0\n"); return; }

	res=res.erase(res.size()-2,2);

	cout << res << endl;

}

 

int main(){

	string a, b, t=".";

	cin>>a>>b;

	int p=b.find(t);

	b=b.erase(p,1);

	bigItergeMul(a,b);	

	return 0;

}