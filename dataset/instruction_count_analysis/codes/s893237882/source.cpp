#include <iostream>

#include <string>

#include <cmath>



using namespace std;





int main()

{

    ios::sync_with_stdio(0);

  string s;

    cin>>s;

    int n=s.length(),c=0;

    for(int i=0;i<n/2;i++)

    {

        if(s[i]!=s[n-i-1])

           c++;

    }

    cout<<c;

}
