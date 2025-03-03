#include <iostream>

#include <string>

using namespace std;



int main()

{

    int n; cin>>n;

    string s; cin>>s;



    for(int j=0; j<4; ++j) {

        int x=j/2, y=j%2;

        int a[n]={};

        a[0]=x;

        a[1]=y;

        for(int k=1; k+1<n; ++k) a[k+1]=(s[k]%2^a[k]^a[k-1]);

        if (a[0]==(s[n-1]%2^a[n-2]^a[n-1]) and a[1]==(s[0]%2^a[0]^a[n-1])) {

            for(int e: a) cout<<(e?'S':'W');

            cout<<endl;

            return 0;

        }

    }

    cout<<-1<<endl;

}
