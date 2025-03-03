#include <iostream>



using namespace std;



int main()

{

    long long n;

    long long num[1000000];

    long long min1;

    long long sum=0;

    cin>>n;

    cin>>num[0];

    min1=num[0];

    for(int i=1;i<n;i++)

    {

        cin>>num[i];

        if(num[i]<min1)

            {

                sum++;

                min1=num[i];

            }

    }

    cout<<sum+1<<endl;

    return 0;

}