#include<stdlib.h>

#include<string.h>

#include<stdio.h>



#define Error(s) {puts(s);exit(0);}

#define INT_MAX (0x3f3f3f3f)



typedef int QueueItem;

typedef struct Node* link;

struct Node {

  QueueItem element;

  link next;

};

link NewNode() {

  link p=(link)malloc(sizeof(Node));

  if(p==NULL)Error("Exhausted memory.");

  p->element=0;

  p->next=NULL;

  return p;

}



typedef struct Queue* queue;

struct Queue {

  link front,rear;

};



queue QueueInit() {

  queue Q=(queue)malloc(sizeof(Queue));

  if(Q==NULL)Error("Exhausted memory.");

  Q->front=Q->rear=0;

  return Q;

}



int QueueEmpty(queue Q) {

  return Q->front==NULL;

}



int QueueFull(queue Q) {

  link p=(link)malloc(sizeof(Node));

  int res=(p==NULL);

  free(p);

  return res;

}



QueueItem QueueFirst(queue Q) {

  if(QueueEmpty(Q))Error("Queue is empty");

  return Q->front->element;

}



void EnterQueue(QueueItem x,queue Q) {

  if(QueueFull(Q))Error("Queue is full");

  link p=NewNode();

  p->element=x;

  p->next=NULL;

  if(QueueEmpty(Q))Q->front=p;

  else Q->rear->next=p;

  Q->rear=p;

}



void DeleteQueue(queue Q) {

  if(QueueEmpty(Q))Error("Queue is empty");

  link p=Q->front;

  Q->front=Q->front->next;

  free(p);

}



int dirx[]={0,0,-1,1};

int diry[]={1,-1,0,0};

int n,m,K;

int **dis;

char **s;

queue queuex,queuey;



void read()

{

  scanf("%d%d%d",&n,&m,&K);

  s=(char**)malloc((n+1)*sizeof(char*));

  int i;

  for(i=1;i<=n;i++)

    s[i]=(char*)malloc((m+2)*sizeof(char));

  for(i=1;i<=n;i++)

    scanf("%s",s[i]+1);

}



void init()

{

  dis=(int**)malloc((n+1)*sizeof(int*));

  int i,j;

  for(i=1;i<=n;i++)

    dis[i]=(int*)malloc((m+1)*sizeof(int));

  for(i=1;i<=n;i++)

    for(j=1;j<=m;j++)

      dis[i][j]=INT_MAX;

  queuex=QueueInit();

  queuey=QueueInit();

  for(i=1;i<=n;i++)

    for(j=1;j<=m;j++)

      if(s[i][j] == 'S')

      {

        EnterQueue(i,queuex);

        EnterQueue(j,queuey);

        dis[i][j]=0;

      }

}



int min(int x,int y)

{

  return x < y ? x : y;

}



void work()

{

  int ans=INT_MAX;

  while(!QueueEmpty(queuex))

  {

    int x=QueueFirst(queuex);

    int y=QueueFirst(queuey);

    DeleteQueue(queuex);

    DeleteQueue(queuey);

    ans = min(ans,

        1 + (min(min(x - 1, n - x), min(y - 1, m - y)) + K - 1) / K);

    if(dis[x][y] == K) continue;

    // 四种方向的拓展

    int d;

    for(d=0;d<4;d++)

    {

      int nx=x+dirx[d];

      int ny=y+diry[d];

      if(1<=nx && nx<=n && 1<=ny && ny<=m && s[nx][ny]=='.')

        if(dis[nx][ny] > dis[x][y]+1)

        {

          // 更新距离

          dis[nx][ny] = dis[x][y] + 1;

          EnterQueue(nx,queuex);

          EnterQueue(ny,queuey);

        }

    }

  }

  printf("%d\n",ans);

}



int main()

{

  read();

  init();

  work();

  return 0;

}
