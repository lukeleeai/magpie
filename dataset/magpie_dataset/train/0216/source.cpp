#include <iostream>

#include <cstring>

#include <algorithm>

#define N_F 1010

#define N_CONST 1001

using namespace std;





int v,d,  f1,f2;

unsigned long long int f[N_F];

int node[N_CONST+10][N_CONST+10];



void rmNode( int i ){

  //  cout << "  remove : "<<i<<endl;



  node[i][i] = 0;

  for( int j=0;j<N_CONST;j++ ){

    if( node[j][j]==0 )

      continue;

    if( node[i][j]==1 ){

      rmNode( j );

    }

  }

}



int main(){

  f[0]=1;  f[1]=2;

  for( int i=2;i<N_F;i++ ){

    //  f[i] = f[i-1] + f[i-2];

      f[i] = (f[i-1] + f[i-2])% N_CONST;

      //        cout << i << "\t"<< f[i] << endl;

  }







  while( cin>>v >> d ){

    //    cout << v <<","<< d<< endl;



    memset( node,0,sizeof(node) );



    //    cout << "test1" << endl;

    for( int i=1;i<=v;i++ ){

      f1 = f[i] % N_CONST; // node ÂÃ label

      node[ f1 ][ f1 ]=1;  // nodeÂÂªÂÂ¶ÂÃÂÂ·ÂÃ©ÂÂ±ÂÃÂÃ°Â\ÂÂ·



      //cout << "test3 i="<<i<<" f1="<<f1 << endl;

      for( int j=1;j<=v;j++ ){

	f2 = f[j] % N_CONST;

	//	if( abs( f[i]-f[j] ) < d ){

	//	cout << "test4 j="<<j<<" f[j]="<<f[j]<<" f2="<<f2 << endl;

	if( abs( f1-f2 ) < d ){

	  node[ f1 ][ f2 ] = 1;

	  node[ f2 ][ f1 ] = 1;

	}

      }

    }

    //    cout << "test2" << endl;

    int n=0;

    for( int i=0;i<N_CONST;i++ ){

      if( node[i][i]==0 ) // ÂmÂ[ÂhÂÂªÂÂ¶ÂÃÂÂµÂÃÂÂ¢

	continue;

      n++;

      rmNode( i );     // i ÂÃÂÃÂÂ±ÂÂ³ÂÃªÂÂ½ÂmÂ[ÂhÂÃ°ÂSÂÃÂÃ­ÂÂ

    }

    cout << n << endl;



    //    break;

  }



  return 0;

}