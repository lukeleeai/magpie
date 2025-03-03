#include "stdc++.h"



using namespace std;





int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    long long a,b,c,d;

    cin>>a>>b>>c>>d;



    vector<long long> arr;

    arr.push_back(a*c);

    arr.push_back(a*d);

    arr.push_back(b*c);

    arr.push_back(b*d);

    



    cout<<*max_element(arr.begin(),arr.end());

    



    return 0;

}
