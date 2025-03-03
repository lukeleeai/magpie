#include <iostream>

#include <vector>

using namespace std;



int main()

{

    ios::sync_with_stdio(false);



    int n, s1 = 0, s2 = 0, ans = 10001, temp = 0;

    cin >> n;

    vector<int> v(n);



    for (int i = 0; i < n; i++)

    {

        cin >> v[i];

    }



    for (int i = 0; i < n; i++)

    {

        temp += v[i];

        int aux = 0;

        for (int j = i + 1; j < n; j++)

        {

            aux += v[j];

        }

        ans = min(ans, abs(aux - temp));

    }



    cout << ans << '\n';



    return 0;

}