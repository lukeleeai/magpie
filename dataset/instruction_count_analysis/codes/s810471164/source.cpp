#include"stdc++.h"

#define ll long long int

using namespace std;

ll a[200010], ans;

bool visited[200010];

int main()

{

    int i, v, u, edges, nodes;

    cin  >> nodes >> edges;

    for(i=1;i<=nodes;i++)

    {

        cin >> a[i];

        visited[i] = true;

    }

    for(i=1;i<=edges;i++)

    {

        cin >> u >> v;

        if(a[u]==a[v])

        {

            visited[u] = false;

            visited[v] = false;

        }

        else if(a[u]>a[v])

        {

            visited[v] = false;

        }

        else{

            visited[u] = false;

        }

    }

    for(i=1;i<=nodes;i++)

        ans += visited[i];

    cout << ans << endl;

    return 0;

}

/*8 9

1 2

1 3

2 5

2 4

4 5

5 6

6 8

6 7

3 7*/
