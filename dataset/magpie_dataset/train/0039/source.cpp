#include<iostream>

#include<vector>

#include<string>

#include<stack>

using namespace std;

int main(){

  int w,h;

  string line;

  while(true){

    cin>>w>>h;

    if(!w&&!h)

      break;

    vector<string> castle;

    for(int i=0;i<h;i++){

      cin>>line;

      castle.push_back(line);

    }

    int count[w+2][h+2];

    int sx,sy;

    const int MAX = 1000;

    for(int y=1;y<h+1;y++){

      for(int x=1;x<w+1;x++){

	count[x][y] = MAX;

	if (castle[y-1][x-1]=='&'){

	  sx = x;

	  sy = y;

	  castle[y-1][x-1]='.';

	}

      }

    }

    int min = MAX;

    int dx[4] = {1,0,-1,0};

    int dy[4] = {0,1,0,-1};

    count[sx][sy] = 0;

    stack<int> st;

    st.push(sy*(w+2)+sx);

    while(!st.empty()){

      int x = st.top()%(w+2);

      int y = st.top()/(w+2);

      st.pop();

      char c = castle[y-1][x-1];

      int n;

      for(int d=0;d<4;d++){

	n = count[x][y];

	if(x+dx[d]>0&&y+dy[d]>0&&x+dx[d]<w+1&&y+dy[d]<h+1){

	  if(c=='.'&&castle[y+dy[d]-1][x+dx[d]-1]=='#')

	    n++;

	  if(n<count[x+dx[d]][y+dy[d]]){

	    count[x+dx[d]][y+dy[d]] = n;

	    st.push((y+dy[d])*(w+2)+x+dx[d]);

	  }

	}

	else{

	  if(n<min)

	    min = n;

	}

      }

    }

    cout<<min<<endl;

  }

  return 0;

}