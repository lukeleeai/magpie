#include"stdc++.h"

using namespace std;

int main()

{

    long long a,b,x,start,end;

	cin>>a>>b>>x;

    if(a%x==0) start=a/x;

    else start=a/x+1;

    end=b/x;

    cout<<end-start+1<<endl;

    return 0;

}