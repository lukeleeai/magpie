#include <iostream>

#include <string>

#include <algorithm>



#define LEN 100000

using namespace std;



class Pro{

public:

	string name;

	int time;

};



class Que{

	Pro* p = new Pro[LEN];

public:

	~Que(){ delete[] p; }

	int head=0, tail=0, n;

	void enqueue(Pro x){

		p[tail] = x;

		tail = (tail + 1) % LEN;

	}



	Pro dequeue(){

		Pro x = p[head];

		head = (head + 1) % LEN;

		return x;

	}

};





int main()

{

	int n;//??????????????°

	cin >> n;

	int q;//?????????????????????

	cin >> q;

	

	Que Q;

	for (int i = 0; i < n; i++){

		Pro x;

		cin >> x.name;

		cin >> x.time;

		Q.enqueue(x);

	}



	//????????????

	int t=0;



	while (Q.head != Q.tail){

		Pro c;

		c = Q.dequeue();

		int b = min(c.time, q);

		c.time -= b;

		t += b;



		if (c.time > 0) {

			Q.enqueue(c);

		}

		else{

		cout << c.name << ' ' << t << '\n';

		}

	}

	return 0;

}