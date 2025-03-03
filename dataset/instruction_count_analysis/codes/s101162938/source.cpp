#include <iostream>

#include <deque>



using namespace std;



int d[114514];



int main()

{

	int k;

	cin >> k;

	d[1] = 1;

	deque<int> q;

	q.push_back(1);

	while (q.front()) {

		int u = q.front();

		q.pop_front();

		for (int i = 0; i < 2; i++) {

			int v = (i ? u + 1 : u * 10) % k;

			if (d[v] && d[v] <= d[u] + i)

				continue;

			d[v] = d[u] + i;

			i ? q.push_back(v) : q.push_front(v);

		}

	}

	cout << *d << endl;

	return 0;

}
