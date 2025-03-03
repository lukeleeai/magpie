// ALDS1_7_A

#include <iostream>

#include <vector>

using namespace std;



struct Node {

	int parent;

	int depth;

	vector<int> children;

};



void cal_depth(vector<Node> &Tree, int p) {

	if (Tree[p].parent != -1)

		Tree[p].depth = Tree[Tree[p].parent].depth + 1;



	for (int i = 0; i < Tree[p].children.size(); i++)

		cal_depth(Tree, Tree[p].children[i]);

}



void printTree(vector<Node> Tree) {

	for (int i = 0; i < Tree.size(); i++) {

		cout <<"node "<< i << ": parent = " << Tree[i].parent << ", depth = " << Tree[i].depth << ", ";

		

		if (Tree[i].parent == -1)

			cout << "root, ";

		else if (Tree[i].children.size() == 0)

			cout << "leaf, ";

		else

			cout << "internal node, ";

		

		cout << "[";

		for (int j = 0; j < Tree[i].children.size(); j++) {

			cout << Tree[i].children[j];

			if (j != Tree[i].children.size() - 1)

				cout << ", ";

		}

		cout << "]" << endl;

	}

}



int main() {

	

	int n, id, c, k, root;

	cin >> n;



	vector<Node> Tree;



	for (int i = 0; i < n; i++) {

		Node node;

		node.parent = -1;

		node.depth = 0;

		Tree.push_back(node);

	}



	for (int i = 0; i < n; i++) {

		cin >> id >> k;

		

		for (int j = 0; j < k; j++) {

			cin >> c;

			Tree[c].parent = id;

			Tree[id].children.push_back(c);

		}

	}



	for (int i = 0; i < n; i++) {

		if (Tree[i].parent == -1)

			root = i;

	}



	cal_depth(Tree, root);



	printTree(Tree);



	return 0;

}


