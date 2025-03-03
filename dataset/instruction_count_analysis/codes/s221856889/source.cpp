#include <iostream>

#include <string>

using namespace std;

string arr[100000];

int main()

{

    int n=0,ACs=0,TLEs=0,WAs=0,REs=0;

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>arr[i];

    }

    for(int i=0;i<n;i++){

        if(arr[i]=="AC") {ACs++;}

        else if(arr[i]=="TLE") {TLEs++;}

        else if(arr[i]=="WA") {WAs++;}

        else if(arr[i]=="RE") {REs++;}

    }

    cout<<"AC x "<<ACs<<"\n";

    cout<<"WA x "<<WAs<<"\n";

    cout<<"TLE x "<<TLEs<<"\n";

    cout<<"RE x "<<REs<<"\n";





    return 0;

}
