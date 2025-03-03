#include <iostream>

#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);

    string s;

    cin>>s;

    if (s.size()!=6) {

        

    }else{

        if (s[2]==s[3]&&s[4]==s[5]) {

            cout<<"Yes";

        }else{

            cout<<"No";

        }

    }

    

    return 0;

}
