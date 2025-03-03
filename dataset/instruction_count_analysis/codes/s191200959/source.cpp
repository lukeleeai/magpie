#include<iostream>

#include<vector>



using namespace std;



int Top(int j, vector<int> &H) //j番目までの最大値を求める

{ int max_height = 0;

  for(int k = 0; k < j ; k++)//j番目はo-indexedでj-1だからk=j-1まで調べればいい

{ max_height = max (max_height, H[k]);}

 return max_height;

}



int main()

{ int N; vector<int> H(N);

 cin >> N;

 for(int l = 0; l < N; l++)

 {cin >> H[l];}

 

 int cnt = 0;

 

 for(int i = 1; i < N; i++)

 {

   if(Top(i,H) <= H[i]){cnt++;}}

 //cnt に、０番目（無条件）も考慮する

 

 cout << cnt+1 <<endl;

 

 return 0;

}
