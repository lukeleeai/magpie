#include <cstdio>                          

using namespace std;                       

                                           

int main()                                 

{                                          

  int N;                                   

  scanf("%d", &N);                         

  int h[N];                                

  for (int i = 0; i < N; i++ ){            

    scanf("%d", &h[i]);                    

  }                                        

  h[0]--;                                  

  bool flag = true;                        

  for (int i = 1; i < N && flag ; i++){    

    if (h[i] - h[i-1] < 0) flag = false;   

    else if (h[i] - h[i-1] == 0) h[i]++;   

    h[i]--;                                

  }                                        

  if (flag) printf("Yes\n");               

  else printf("No\n");                     

}                                          