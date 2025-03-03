#include <iostream>

#include <string>

#include <regex>

#include <algorithm>

using namespace std;

int main()

{

    string s;

    cin>>s;

    int res=0;

    smatch m;

    for(auto it=cbegin(s); regex_search(it, cend(s), m, regex("[ACGT]+")); it=m[0].second)

        res=max<int>(res, m.str().size());

    cout<<res<<endl;

}