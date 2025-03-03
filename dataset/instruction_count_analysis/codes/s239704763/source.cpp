#include <iostream>

#include <vector>

#include <string>



using namespace std;

typedef long long int llint;



struct Node {

	llint parent;

	llint depth;

	string state;

	vector<llint> children;

	Node():parent(-1),depth(0){

	}

};

struct faster_io{

	faster_io() {

		cin.tie(0);

		ios::sync_with_stdio(false);

	}

};



void set_depth(vector<Node> &Nodes, Node &node, int depth) {

	node.depth = depth;

	for (int i = 0; i < node.children.size(); i++) {

		set_depth(Nodes, Nodes[node.children[i]], depth + 1);

	}

}





int main() {

	llint const N_MAX = 100000;

	faster_io io;



	llint n;

	cin >> n;



	vector<Node> Nodes;

	Nodes.resize(N_MAX);



	for (llint i = 0; i < n; i++) {

		llint id, k;

		cin >> id >> k;

		Node &x = Nodes[id];

		for (llint j = 0; j < k; j++) {

			llint c;

			cin >> c;

			x.children.push_back(c);

			Nodes[c].parent = id;

		}

	}



	Node root;

	for (llint i = 0; i < n; i++) {

		Node &x = Nodes[i];

		if (x.parent == -1) {

			x.state = "root";

			root = x;

		}

		else if (x.children.size() == 0) {

			x.state = "leaf";

		}

		else {

			x.state = "internal node";

		}

	}



	set_depth(Nodes, root, 0);



	for (llint i = 0; i < n; i++) {

		Node x = Nodes[i];

		cout << "node " << i

			<< ": parent = " << x.parent

			<< ", depth = " << x.depth

			<< ", " << x.state

			<< ", [";

		for (llint j = 0; j < x.children.size(); j++)	{

			if (j != x.children.size() - 1) cout << x.children[j] << ", ";

			else cout << x.children[j];

		}

		cout << "]\n";

	}

}