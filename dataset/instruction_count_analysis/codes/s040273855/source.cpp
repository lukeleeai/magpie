#include <string>

#include <vector>

#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

    string S; cin >> S;

    

    vector<char> v1;

    

    vector<int> v2; int c = 1;

    

    for(int i = 1; i < S.size(); i++)

    {

        if(S[i - 1] != S[i])

        {

            v1.push_back(S[i - 1]);

            v2.push_back(c);

            

            c = 0;

        }

        

        c++;

    }

    

    v1.push_back(S[S.size() - 1]);

    v2.push_back(c);

    

    int ret = 0;

    

    for(int i = 1; i < v1.size() -1; i++)

    {

        if(v1[i - 1] == 'J' && v1[i] == 'O' && v1[i + 1] == 'I' && v2[i - 1] >= v2[i] && v2[i] <= v2[i + 1])

        {

            ret = max(ret, v2[i]);

        }

    }

    

    printf("%d\n", ret);

    

    return 0;

}