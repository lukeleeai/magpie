#include"stdc++.h"

using namespace std;

 

int main()

{

    string s;

    while(cin>>s)

    {

        cout << ( (s[0]==s[s.length()-1])^(s.length()%2)?"First":"Second") << endl;

    }

    return 0;

}