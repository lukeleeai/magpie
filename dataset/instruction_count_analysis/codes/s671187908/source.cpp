#include <iostream>

#include <set>

using namespace std;

int main() {

    set<string> dd;

    int n;

    cin>>n;

    string ss;

    while(n--){

    	cin>>ss;

    	dd.insert(ss);

    }cout<<dd.size();

    return 0;

}
