#include"stdc++.h"

#include<string.h>

using namespace std;



main() {

    char A[100],B[100],C[100];

    int a,b,c;

    cin>>A;

    cin>>B;

    cin>>C;



    a=strlen(A);

    b=strlen(B);

    c=strlen(C);



    if(A[a-1]==B[0] && B[b-1]==C[0])

        cout<<"YES";

    else

        cout<<"NO";

}