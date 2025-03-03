#include <iostream>

using namespace std;



void print_hash_line(int n){

    

    for(int i=0;i<n+2;i++)

        cout<<"#";

    cout<<endl;

}



int main()

{

    int m,n;

    char x;

    cin>>m>>n;

    

    print_hash_line(n);

    

    for(int i=0;i<m;i++){

        cout<<'#';

        for(int j=0;j<n;j++){

            cin>>x;

            cout<<x;

        }

        cout<<'#'<<endl;

    }

    

    print_hash_line(n);



    return 0;

}
