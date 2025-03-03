#include"stdc++.h"



using namespace std;

template <class T> string toStr(T par) {

	ostringstream oss;

	oss<<par;

	return oss.str();

}

string s;

int n, k, q, dislikes[11];

int main()

{

    cin >> n >> k;

    for(int i = 0; i < k ; i++)

    {

        cin >> q;

        dislikes[q] = 1;

    }



    while(true)

    {

        int prev_n = n, cnt = 0;

        bool ok = false;

        s = toStr(n);

        for(int i = s.size() - 1; i >= 0; i--)

        {

            if(dislikes[s[i] - '0'])

                ok = true;

        }

        if(ok) n++;

        else break;

    }

    cout << n << endl;

    return 0;

}
