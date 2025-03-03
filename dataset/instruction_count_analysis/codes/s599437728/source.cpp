#include <iostream>                           

using namespace std;                          

                                              

int main()                                    

{                                             

  int N;                                      

  cin >> N;                                   

  int h[N];                                   

  for (int i = 0; i < N; i++ ){               

    cin >> h[i];                              

  }                                           

  h[0]--;                                     

  bool flag = true;                           

  for (int i = 1; i < N && flag ; i++){       

    if (h[i] - h[i-1] < 0) flag = false;      

    else if (h[i] - h[i-1] == 0) h[i]++;      

    h[i]--;                                   

  }                                           

  if (flag) cout << "Yes" << endl;            

  else cout << "No" << endl;                  

}                                             