#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



int descrescator(int a, int b)

{

    return a > b;

}



int checkFather(vector <int>&goodSlimes, vector <int>&s, int n, vector <int>&viz)

{

    int length = goodSlimes.size(), weAreGoodHere = 0;

    int poz = 0, nr = 0;

    //cout << length << " " << n << "\n";



    for (int i = 0; i < n; i++)

    {

        //cout << viz[i] << " " << i << "\n";

        if (viz[i] == 0)

        {

            if (goodSlimes[poz] > s[i])

            {

                viz[i] = 1; poz++;

                goodSlimes.push_back(s[i]);

            }



            if (poz == length)

            {

                return 1;

                i = n + 1;

            }

        }

        if (i == n - 1)

            return 0;

    }

    //cout << "\n";

    //if (nr == length)

      //  weAreGoodHere = 1;



    return 1;

}



int main()

{

    int n, doiLaN;



    cin >> n;



    doiLaN = 1 << n;



    vector <int> s(doiLaN), goodSlimes, viz(doiLaN, 0);



    for (int i = 0; i < doiLaN; i++)

    {

        cin >> s[i];

    }

    //cout << s[0] << " ";



    sort(s.begin(), s.end(), descrescator);



    //cout << s[0];

    int poz = 0;

    goodSlimes.push_back(s[0]);

    viz[0] = 1;



    while(poz < n)

    {

        if (checkFather(goodSlimes, s, doiLaN, viz) == 0)

            {

                cout << "No\n";

                return 0;

            }



        sort(goodSlimes.begin(), goodSlimes.end(), descrescator);

        poz++;

    }



    cout << "Yes\n";



    return 0;

}
