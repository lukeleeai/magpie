#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



int descrescator(int a, int b)

{

    return a > b;

}



int doiLaN;

vector <int> s(1 << 18), goodSlimes, viz(1 << 18, 0);



int checkFather(int l)

{

    int length = l, weAreGoodHere = 0;

    int poz = 0, nr = 0, n = doiLaN;

    //cout << length << " " << n << "\n";



    for (int i = n - 1; i >= 0; i--)

    {

        //cout << viz[i] << " " << i << "\n";

        if (viz[i] == 0)

        {

            //cout << goodSlimes[poz] << " " << s[i] << "\n";

            if (goodSlimes[poz] > s[i])

            {

                goodSlimes.push_back(s[i]);

                viz[i] = 1;

                poz++;

            }

            if (poz == length)

            {

                return 1;

                i = n + 1;

            }

        }

        if (i == 0)

        {

            return 0;

        }





    }



    sort(goodSlimes.begin(), goodSlimes.end(), descrescator);

    return 1;

}



int main()

{

    int n;



    cin >> n;



    doiLaN = 1 << n;



    for (int i = 0; i < doiLaN; i++)

    {

        cin >> s[i];

    }

    //cout << s[0] << " ";



    sort(s.begin(), s.begin() + doiLaN);



    //cout << s[0];

    int poz = 0;

    goodSlimes.push_back(s[doiLaN - 1]);

    viz[doiLaN - 1] = 1;



    while(poz < n)

    {

        int l = goodSlimes.size();

        if (checkFather(l) == 0)

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
