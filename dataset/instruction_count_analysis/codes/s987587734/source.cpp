#include<iostream>

using namespace std;



#define INFTY 1 << 30;







int Merge(int A[],int left,int mid,int right){



  int k;

  int n1 = mid-left;

  int n2 = right-mid;



  int L[n1+1];

  int R[n2+1];



  for(int i=0;i<n1;i++){

    L[i] = A[left+i];

  }



  for(int i=0;i<n2;i++){

    R[i] = A[mid+i];

  }



  L[n1] = INFTY;

  R[n2] = INFTY;



  int i=0;

  int j=0;



  for(k=left;k<right;k++){

    if(L[i]<=R[j]){

      A[k] = L[i];

      i++;

    }else{

      A[k] = R[j];

      j++;

    }

  }

  return k - left;

}



int MergeSort(int A[],int left,int right){

  int count = 0;

  if(left+1 < right){

    int mid = (left+right)/2;

    count += MergeSort(A,left,mid);

    count += MergeSort(A,mid,right);

    count += Merge(A,left,mid,right);

  }

  return count;

}



int main(){

  int n,m;

  cin >> n;



  int S[500000];

  for(int i=0;i<n;i++){

    cin >> S[i];

  }



  m = MergeSort(S,0,n);



  for(int i=0;i<n-1;i++){

    cout << S[i];

    cout << " ";

  }

  cout << S[n-1];

  cout << endl;



  cout << m << endl;



  return 0;

}


