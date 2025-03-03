#include<iostream>

#include<vector>

#include<set>

using namespace std;



int p,q,a,n;

int ans=0;



class Fraction{//ªð\·

public:

	int bo,shi;//ªêÆªq

	Fraction(int shi,int bo):bo(bo),shi(shi){};

};



Fraction my_plus(Fraction a,Fraction b){//ªÌ«µZ@ñª·éÆTLEµ½

	int new_bo=a.bo*b.bo;

	int new_shi=a.shi*(new_bo/a.bo)+b.shi*(new_bo/b.bo);

	return Fraction(new_shi,new_bo);

}



void dfs(int num,int now_bo,int mul,Fraction now){

	if(p*now.bo<q*now.shi) return;//} è@·ÅÉÚIÌlæèàå«¢ÌÅC±êÈã½ð«µÄà³Ê

	if(num>n) return;//§Àð´¦½

	if(p*now.bo==q*now.shi){//lªêv

		ans++;

		return;

	}

	for(int i=now_bo;i<12000;i++){//Ìlð«·

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