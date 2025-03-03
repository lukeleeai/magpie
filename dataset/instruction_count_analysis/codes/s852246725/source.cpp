#include<iostream>

#include<set>

using namespace std;

struct A{

	int is = 0;

	int num;

}pp[500000];

int main(){

	pp[1].is = 1;

	int n, i, y = 0;

	cin >> n;

	for(i = 1; i <= n; i++){

		cin >> pp[i].num;

	}

	int Count = 0, t = 1;

	while(pp[2].is!=1){

		pp[t].is = 1;

		t = pp[t].num;

		Count++;

		if(Count>200000){

			cout << -1 << endl;

			y = 1;

			break;

		}

	} 

	if(!y){

		cout << Count-1 << endl;

	}

	return 0;

} 