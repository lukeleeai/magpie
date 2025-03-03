/*

#include <iostream>

#include <queue>



using namespace std;



int main() {

	int n;

	int h;

	queue<int> cola;



	cin >> n; cin >> h;

	int *a = new int[n];

	int aux = 0;

	int k = n / h;

	int **matriz = new int*[k];

	for (int i = 0; i < k; i++) {

		matriz[i] = new int[h];

	}

	for (int i = 0; i<n; i++)

	{

		cin >> a[i];

	}

	if (n%h==0){

		

		for (int i=0;i<n;i++)

		{

			for (int j=i+1;j<n;j++)

			{

				if(a[i]>a[j])

				{

					aux = a[i];

					a[i] = a[j];

					a[j] = aux;

				}

			}

			cola.push(a[i]);

		}

		int p = 0;

		for (int i = 0; i < n; i++)

		{

			int cont = 1;

			for (int j = i + 1; j < n; j++)

			{

				if (a[i] == a[j])

					{

						cont += 1;

						if (cont > k)

						{

							cout << "impossible" << endl;

							system("pause");

							return 0;

						}

					}

				else { break; }

			}

							

		}

		for (int i = 0; i < h; i++) {

			for (int j = 0; j < k; j++) {

				matriz[j][i] = cola.front();

				cola.pop();

			}

		}

		for (int i = 0; i < k; i++) {

			for (int j = 0; j < h; j++) {

				cout << matriz[i][j] <<" ";

			}

			cout << endl;

		}

		

	}

	else 

	{

		cout << "impossible" << endl;

		system("pause");

		return 0;

	}





	system("pause");

	return 0;

}*/



	#include <cmath>

	#include <cstdio>

	#include <vector>

	#include <iostream>

	#include <algorithm>

	#include <string>

	#include <stack>

	#include <map>

	using namespace std;





	int main() {

		int N;

		int T;

		cin >> N;

		cin >> T;

		vector<int>primero;

		vector<int>segundo;



		for (int i = 0; i < N; i++) {

			int costo, tiempo;

			cin >> costo; cin >> tiempo;

			primero.push_back(costo);

			segundo.push_back(tiempo);

		}

		vector<int>elegido1;

		vector<int>elegido2;

		for (int i = 0; i < N; i++) {

			if (segundo[i] <= T) {

				elegido1.push_back(primero[i]);

				elegido2.push_back(segundo[i]);

			}

		}

		if (elegido1.empty()) {

			cout << "TLE" << endl;

			

			return 0;

		}

		int min = std::min_element(elegido1.begin(), elegido1.end()) - elegido1.begin();

		cout << elegido1[min];

		

		return 0;

	}
