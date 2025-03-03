#include<iostream>

#include<set>

using namespace std;

int main()

{

    set<int> s;

    int a;

    for(int i=0;i<3;i++)

    {

        cin>>a;

        s.insert(a);

    }

    cout<<s.size()<<endl;

    return 0;

}
