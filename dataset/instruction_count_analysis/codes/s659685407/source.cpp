#include <iostream>

#include <queue>



using namespace std;



int main()

{

  int n, m; cin >> n >> m;

  

  priority_queue<int> pq;

  while (n--) {

    int a; cin >> a;

    pq.push(a);

  }

  

  while (m--) {

    pq.push(pq.top()/2);

    pq.pop();

  }

  

  long long ans = 0;

  while (pq.size()) {

    ans += pq.top();

    pq.pop();

  }

  

  cout << ans << endl;

  return 0;

}