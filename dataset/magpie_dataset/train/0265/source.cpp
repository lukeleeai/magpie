#include<iostream>

#include<vector>

#include<set>

using namespace std;



int p,q,a,n;





int gcd(int a, int b){ return a%b ? gcd(b, a%b) : b; }//Ååöñ

int lcm(int a, int b){ return a/gcd(a,b)*b; }//Å¬ö{



class Fraction{

public:

	int bo,shi;

	Fraction(int shi,int bo):bo(bo),shi(shi){};

	Fraction(){};

};



Fraction my_plus(Fraction a,Fraction b){

	if(a.shi==0) return b;

	int new_bo=a.bo*b.bo;

	int new_shi=a.shi*(new_bo/a.bo)+b.shi*(new_bo/b.bo);

	return Fraction(new_shi,new_bo);

}

int ans=0;



void dfs(int num,int now_bo,int mul,Fraction now){

	if(p*now.bo<q*now.shi) return;

	if(num>n) return;

	if(mul>a) return;

	if(p*now.bo==q*now.shi){

		ans++;

		return;

	}

	for(int i=now_bo;i<=12000;i++){

		

		if(mul*i>a) break;

		dfs(num+1,i,mul*i,my_plus(now,Fraction(1,i)));

	}

}





int main()

{

	while(cin>>p>>q>>a>>n && p!=0 && q!=0 && a!=0 && n!=0){

		ans=0;

		dfs(0,1,1,Fraction(0,2));

		cout<<ans<<endl;

	}

	return 0;

}