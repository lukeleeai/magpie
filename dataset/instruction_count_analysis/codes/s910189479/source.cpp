#include <iostream>

#include <stdio.h>

#include <vector>

using namespace std;



struct Node{

	int parent;

	int depth;

	vector<int> children;

};



void solve(vector<struct Node> &node, int x){

	for(int i=0;i<node[x].children.size();i++){

		node[node[x].children[i]].depth += node[x].depth + 1;

		solve(node, node[x].children[i]);

	}

}



void printNode(vector<struct Node> node, int n){

	for(int i=0;i<n;i++){

		cout<<"node "<<i<<": parent = "<<node[i].parent<<", depth = "<<node[i].depth<<", ";

		

		if(node[i].parent == -1)

			cout<<"root";

		else if(node[i].children.size() == 0)

			cout<<"leaf";

		else

			cout<<"internal node";



		cout<<", [";

		for(int j=0;j<node[i].children.size();j++){

			cout<<node[i].children[j];

			if(j != node[i].children.size()-1)

				cout<<", ";

		}

		cout<<"]"<<endl;

	}

}



int main(){

	int n, id, k, c, x;

	vector<struct Node> node(100000);



	cin>>n;

	for(int i=0;i<n;i++){

		node[i].parent = -1;

		node[i].depth = 0;

	}



	for(int i=0;i<n;i++){

		cin>>id>>k;

		

		for(int j=0;j<k;j++){

			cin>>c;

			node[id].children.push_back(c);

			node[c].parent = id;

		}

	}



	for(int i=0;i<n;i++)

		if(node[i].parent == -1)

			x = i;



	solve(node, x);

	printNode(node, n);

	return 0;

}