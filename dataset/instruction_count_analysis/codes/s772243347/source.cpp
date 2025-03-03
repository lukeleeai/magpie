#include <iostream>

#include <regex>



using namespace std;

int main() {

    string s;

    cin >> s;

    int len=0;

    regex re(R"([ACGT]+)");

    sregex_iterator iter(s.cbegin(), s.cend(), re);

    sregex_iterator end;

    for(;iter!=end;++iter) {

        string m = iter->str();

        if (m.length()>len) len = m.length();

    }

    cout << len << endl;

    return 0;

}