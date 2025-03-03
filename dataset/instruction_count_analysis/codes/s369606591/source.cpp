#include<iostream>

#include<algorithm>

using namespace std;

struct P{

	int p,y,d;

	int b[15];

};

int cmp(P x1,P x2){

	if(x1.p==x2.p){

		return x1.y<x2.y;

	}

	return x1.p<x2.p;

}

int cmp1(P x1,P x2){

	return x1.d<x2.d;

}

P a[100010];

int main(){

	int n,m,i,j,k;

	cin >> n >> m;

	for(i=0;i<m;i++){

		cin >> a[i].p >> a[i].y;

		a[i].d=i;

		for(j=0;j<13;j++){

			a[i].b[j]=0;

		}

	}

	sort(a,a+m,cmp);

	int x=1,w;

	for(i=0;i<m;i++){

		if(i==0 || a[i].p!=a[i-1].p){

			x=1;

		}

		else{

			x++;

		}

		j=5;

		w=a[i].p;

		while(w){

			a[i].b[j]=w%10;

			w/=10;

			if(j==0)

				break;

			j--;

		}

		w=x;

		j=11;

		while(w){

			a[i].b[j]=w%10;

			w/=10;

			if(j==6)

				break;

			j--;

		}

	}

	sort(a,a+m,cmp1);

	for(i=0;i<m;i++){

		for(j=0;j<12;j++){

			cout << a[i].b[j];

		}

		cout << endl;

	}

	return 0;

}