#include<iostream>

#include<algorithm>

using namespace std;



int N, K, X, a[1000000];

vector<pair<int, int>> s;

int main()

{

  while(true)

  {

    cin >> N >> K;

    if(!N)

      break;

    for(int i = 0; i < K; i++)

    {

      cin >> a[i];

      if(!a[i])

      {

        a[i] = 1000000000;

        X = 1;

      }

    }

    sort(a, a + K);

    a[K] = -1;

    int st = a[0], ans = 0;

    for(int i = 1; i < K + 1; i++)

    {

      if(a[i] != a[i - 1] + 1)

      {

        s.push_back(make_pair(st, a[i - 1] + 1));

        ans = max(ans, a[i - 1] + 1 - st);

        st = a[i];

      }

    }

    if(X)

    {

      for(int i = 1; i < s.size(); i++)

        if(s[i].first == s[i - 1].second + 1)

          ans = max(ans, s[i].second - s[i - 1].first);

    }

    cout << ans << endl;

  }

}