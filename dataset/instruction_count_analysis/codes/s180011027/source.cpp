#include<iostream>

#include<vector>

#include<algorithm>

#include<string>



using namespace std;



int main()

{int N;cin >> N;

 vector<int> H(N,0); vector<int> J(N-1,0);

 if(N == 1){cout << 1 << endl;}

 else{

   for(int i = 0; i < N; i++){

   cin >> H[i];}

 

 int max_height = 0;

 

 for(int i = 0; i < N; i++)

 {max_height = max(H[i],max_height);

  J[i] = max_height;}

   

  int cnt = 1;

   

   for(int j = 1 ; j < N; j++)

   {if(J[j-1] <= H[j]){cnt++;}}

   

   cout << cnt << endl;}

 

   return 0;}
