#include <iostream>



using namespace std;



int main()

{

    string s[100000];

    int i , n ;

    int AC=0 , WA=0 , TLE=0, RE=0;

    cin>>n;

    for(i=0;i<n; i++){

        cin>>s[i];}

    for(i=0;i<n;i++){

        if(s[i]=="AC"){ AC+=1;}

        else if (s[i]=="WA"){WA+=1;}

        else if (s[i]=="TLE"){TLE+=1;}

        else if (s[i]=="RE"){RE+=1;}

        }

    cout<<"AC"<<" "<<"x"<<" "<<AC<<endl;

    cout<<"WA"<<" "<<"x"<<" "<<WA<<endl;

    cout<<"TLE"<<" "<<"x"<<" "<<TLE<<endl;

    cout<<"RE"<<" "<<"x"<<" "<<RE<<endl;



    return 0;

}
