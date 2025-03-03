#include"stdc++.h"

using namespace std;



int main(){

    int n;

    cin>>n;

    char num[101];



    for(int i=0;i<n;i++)

        cin>>num[i];



    set<char> color;

    for(int i=0;i<n;i++)

        color.insert(num[i]);



    if(color.size()==4)

        cout<<"Four";

    else

        cout<<"Three";

    return 0;

}