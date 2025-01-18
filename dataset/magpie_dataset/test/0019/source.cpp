#include <iostream>



using namespace std;



int main()

{

    long int K;

    cin >> K;

    string palabra;

    cin >> palabra;

    int lon= palabra.size();

    if(lon>K){

            for(int i=0; i<K; i++){

            cout<<palabra[i];

        }

        cout<<"...";



    }

    else{

        cout << palabra;

    }

    return 0;

}