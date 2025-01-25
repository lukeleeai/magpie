#include<iostream>

using namespace std;



bool visit[26],g[26][26];



bool dfs(int v){

  visit[v] = true;

  bool f = false;

  for(int i=0;i<26;i++)

    if(g[v][i]){

      f = true;

      if(!visit[i])dfs(i);

    }

  return f;

}

 

int graph_num(void){

  int res = 0;

  for(int i=0;i<26;i++)

    if(!visit[i] && dfs(i))res++;

  return res;

}

  

int main(){

  int i,n,pre[26],suf[26],h,t;

  string s;



  while(cin>>n && n){

    for(i=0;i<26;i++){

      visit[i] = false;

      pre[i] = suf[i] = 0;

      for(int j=0;j<26;j++)g[i][j] = false;

    }

    

    for(i=0;i<n;i++){

      cin >> s;

      h = s[0]-'a', t = s[(int)s.size()-1]-'a';

      

      pre[h]++;

      suf[t]++;

      g[h][t] = g[t][h] = true;

    }

  

    if(graph_num() != 1)printf("NG\n");

    else{

      for(i=0;i<26;i++)if(pre[i] != suf[i])break;

      

      if(i==26)printf("OK\n");

      else printf("NG\n");

    }

  }

}