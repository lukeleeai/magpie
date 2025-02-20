#include<iostream>

#define MAX 100500



using namespace std;



int main(void){



  int n,m;

  long long int N, M[MAX],d[MAX];

  

  while(cin >> n ){



    cin >> m;



    for(int i = 0 ; i < MAX ; i++){

      M[i] = 0;

      d[i] = 0;

    }



    d[0] = 0;



    for(int i = 1 ; i < n; i++){

      cin >> N;

      d[i] += d[i-1] + N;

      //  cout << "N = " << N << " d[i] = " << d[i] << endl;

    }



    for(int i = 0 ; i < m ; i++) cin >> M[i];



    long long int sum = 0,now = 0;

    

    for(int i = 0 ; i < m ; i++){

     

      // cout << endl << "i = " << i << " now = "  << now << endl;//



      //  cout <<"now + M[i] = " << now + M[i]<<   " d[now + M[i]] = " << d[now + M[i]] << " d[now] =  " <<  d[now] << endl;//

      



      if(M[i] >= 0){

	sum += d[now + M[i]] - d[now];  

	//	cout << "! N = " << d[now + M[i]] - d[now] << endl;//

      }

      else{

	sum += d[now] - d[now + M[i]];

	//	cout << "? N = " <<  d[now] - d[now + M[i]]  << endl;//

      }



      now = now + M[i];//



    }

    cout << sum % 100000 << endl;

  }



  return 0;

}