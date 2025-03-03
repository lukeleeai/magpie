#include <iostream>

#include <cstring>

#include <utility>

#include <cstdint>

 

using namespace std;

 

uint64_t N;

int8_t L[100000],_L[100000];

 

int main(void)

{

    cin >> N;

    int t;

    for(int i = 0;i < N;i++)

    {

        cin >> t;

        L[i] = t;

    }

    L[N] = -1;

    bool loop = true;

    uint64_t itr1 = 0,itr2 = 0;

    uint64_t result = 0;

    while(loop)

    {

        while(L[itr1] != L[itr1 + 1] && itr1 < N - 1)

        {

            itr1++;

        }

        itr2 = itr1 + 1;

        while(L[itr2] != L[itr2 + 1] && itr2 < N - 1)

        {

            itr2++;

        }

        memcpy(_L,L,sizeof(int8_t[100000]));

        for(uint64_t i = itr1 + 1;i <= itr2;i++)

        {

            if(L[i] == 0)

                _L[i] = 1;

            else if(L[i] == 1)

                _L[i] = 0;

        }

        uint64_t upper = itr1,downer = itr1,count = 1;

        while(upper > 0 && _L[upper] != _L[upper - 1])

        {

            upper--;

            count++;

        }

        while(downer < N - 1 && _L[downer] != _L[downer + 1])

        {

            downer++;

            count++;

        }

        result = max(result,count);

        itr1++;

        if(itr2 >= N - 1)

        {

            loop = false;

        }

    }

    cout << result << endl;

    return 0;

}