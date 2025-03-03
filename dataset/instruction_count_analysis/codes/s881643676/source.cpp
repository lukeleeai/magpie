#include <iostream>

#include <cstring>

using namespace std;



int arr[1005][1005];

int main() {

  int h, w, a, b;

  cin >> h >> w >> a >> b;



  memset(arr, 0, sizeof(arr));



  //if b = 0

  if (b == 0){

    if (a == 0){

      for (int i = 1; i <= h; i++){

        for (int j = 1; j <= w; j++){

          if (j == w)

            cout << "1" << endl;

          else

            cout << "1";

        }

      }

    }

    else{

      for (int i = 1; i <= h; i++){

        for (int j = 1; j <= w; j++){

          if (j <= a)

            arr[i][j] = 1;

        

          if (j == w)

            cout << arr[i][j] << endl;

          else

            cout << arr[i][j];

        }

      }

    }

  }



  else if (a == 0){

    for (int i = 1; i <= h; i++){

      for (int j = 1; j <= w; j++){

        if (i <= b)

          arr[i][j] = 1;



        if (j == w)

          cout << arr[i][j] << endl;

        else

          cout << arr[i][j];

      }

    }

  }





  //if normal

  else{

    for (int i = 1; i <= h; i++){

      for (int j = 1; j <= w; j++){

        //if i and j in square one

        if (i <= b && j <= a)

          arr[i][j] = 1;

        else if ((i >= b+1) && (j >= a+1)){

          arr[i][j] = 1;

        }



        if (j == w)

          cout << arr[i][j] << endl;

        else

          cout << arr[i][j];

      }

    }

  }

  return 0;

}