#include "stdc++.h"

using namespace std;

using ii = pair<int, int>;

using edge = tuple<int, int, int>;

using ll = long long;

using pq = priority_queue <int>;

using minHeap = priority_queue <int, vector<int>, greater<int> >;

// INSERIR EM TUPLA std::get<0>(mytuple) = 0 << " and " << std::get<1>(mytuple);

// std::map<key, value> map;



int main(int argc, char const *argv[])

{

  int n;

  std::cin >> n;

  int total;

  std::cin >> total;

  std::vector<int> v;;

  int aux = 0;

  int gram;

  for (size_t i = 0; i < n; i++)

  {

    std::cin >> gram;

    v.push_back(gram);

  }

  sort(v.begin(),v.end());

  for (size_t i = 0; i < v.size(); i++)

  {

    aux = aux + v[i];

  }

  int menor = v[0];

  int cont = n;

  total  = total - aux;



  while (total>=menor)

  {

    total = total - menor;

    cont++;

  }



  std::cout << cont << '\n';

  return 0;

}
