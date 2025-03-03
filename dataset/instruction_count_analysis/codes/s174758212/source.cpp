#include<stdio.h>

#include<math.h>

#include<string>

#include<cstring>

#include<iostream>

#include<iomanip>

#include<queue>

#include<stack>

#include<map>

#include<cmath>

#include<fstream>  // 文件读取  ifstream ofstream

#include<algorithm>  

#include<vector>

using namespace std;





int n;



struct List{

	int node;

	List *next;

};



int main()  

{  





	cin>>n;

	List *L;

	L = new List;

	List *end = new List;

	end = L;

	for(int i =0;i<n;i++){

		int temp;

		cin>>temp;

		List *t = new List;

		t->node = temp;

		if(i%2==0){

			end->next = t;

			end = end->next;

		}else{

			t->next = L->next;

			L->next  = t;

		}

	}



	vector<int>sq;



	L=L->next;

	int index = 0;

	while(index<n){

		sq.push_back(L->node);

		L=L->next;

		index++;

	}



	if(n%2==0){

		for(int i = 0;i<sq.size();i++)

			cout<<sq[i]<<" ";

	}else{

		for(int i = sq.size()-1;i>=0;i--)

			cout<<sq[i]<<" ";

	}





	return 0;





} 




