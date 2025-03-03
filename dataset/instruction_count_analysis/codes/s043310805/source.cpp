#include"stdc++.h"

using namespace std;

int main()

{

    double a,b,c;

    cin>>a>>b>>c;

    c=min(c,b-1);

    cout<<floor(a*c/b)-a*floor(c/b)<<endl;

    return 0;

}
