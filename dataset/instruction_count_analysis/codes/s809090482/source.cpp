#include "stdc++.h" 

using namespace std; 

  

// Return the maximum volume. 

float maxvolume(float s) 

{ 

    // finding length 

    float length = s / 3; 

  

    s -= length; 

  

    // finding breadth 

    float breadth = s / 2; 

  

    // finding height 

    float height = s - breadth; 

  

    return length * breadth * height; 

} 

  

// Driven Program 

int main() 

{ 

    float s ;cin>>s; 

    float ans=maxvolume(s); 

    cout<<""<<fixed<<setprecision(6)<<ans<<'\n';

    return 0; 

} 