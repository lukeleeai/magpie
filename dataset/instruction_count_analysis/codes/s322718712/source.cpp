#include<iostream>

#include<algorithm>

#include<vector>



using namespace std;



int main()

{

    int n;

    cin>>n;

    int A[1000000];

    for(int i=0;i<n;i++)

        cin>>A[i];

    sort(A,A+n);

    if(A[n/2] == A[n/2-1])

    {

        cout<<0;

        return 0;

    }

    else

    {

        cout<<A[n/2] - A[n/2-1];

        return 0;

    }

    return 0;

}