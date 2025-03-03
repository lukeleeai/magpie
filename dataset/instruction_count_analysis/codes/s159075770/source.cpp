#include <iostream>

using namespace std;



int main()

{

    string s; cin >> s;

    for (int i = 0, n = s.length(); i < n; i ++)

    {

        if (s[i] == ',')

        {

            s[i] = ' ';

        }

    }

    std::cout << s << std::endl;

    return 0;

}
