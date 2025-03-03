#include <iostream>

using namespace std;



int main()

{

    int x, y;

    string s;

    cin >> x >> s >> y;

    if(s == "+") cout << x + y << '\n';

    else cout << x - y << '\n';

    return 0;

}
