#include <iostream>

#include <algorithm>



using namespace std;



struct Point{

    int x, y, i;



    bool operator<(const Point &that)const {

        return i < that.i;

    }

    void print(){

//        cout << i << endl;

        printf("%d\n", i);

    }

};

bool lessX(const Point &p1, const Point &p2){ return p1.x < p2.x; }

bool lessY(const Point &p1, const Point &p2){ return p1.y < p2.y; }



struct Node{

    int ld_id, ru_id;

    int p_id;

};



// kd tree DST

static const int MAX_N = 500000;

Point pts[MAX_N];

Node ns[MAX_N]; // nodes of ketree

int tindex;

int makeKdTreeNode(int i, int n, int i1);



void queryRect(int sx, int sy, int tx, int ty, int nodeId, int depth, vector<Point> &inPts);



int main(){

    int n;

//    cin >> n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {

        Point &p = pts[i];

        p.i = i;

//        cin >> p.x >> p.y;

        scanf("%d %d",&p.x,&p.y);

    }





    tindex = 0;

    int rootNodeId = makeKdTreeNode(0, n, 0);



    int q;

//    cin >> q;

    scanf("%d", &q);

    vector<Point> inPts;

    for (int i = 0; i < q; i++) {

        int sx, tx, sy, ty;

//        cin >> sx >> tx >> sy >> ty;

        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);



        inPts.clear();

        queryRect(sx, sy, tx, ty, rootNodeId, 0, inPts);



        sort(inPts.begin(), inPts.end());

        for (Point p : inPts) {

            p.print();

        }

        printf("\n");

    }



    return 0;





}



int makeKdTreeNode(int left, int right, int depth) {

    if (left >= right) {

        return -1;

    }



    int curNodeIndex = tindex++;



//    bool (*c)(const Point &p1, const Point &p2) =  depth % 2 == 0 ? lessX : lessY;

//    sort(pts + left, pts + right, c);

    if(depth%2 == 0){

        sort(pts+left,pts+right,lessX);

    }else{

        sort(pts+left,pts+right,lessY);

    }



    int mid = (left + right) / 2;

    ns[curNodeIndex].p_id = mid;



    ns[curNodeIndex].ld_id = makeKdTreeNode(left, mid, depth + 1);

    ns[curNodeIndex].ru_id = makeKdTreeNode(mid + 1, right, depth + 1);



    return curNodeIndex;

}



void queryRect(int sx, int sy, int tx, int ty, int nodeId, int depth, vector<Point> &inPts){



    Point &p = pts[ns[nodeId].p_id];

    int x = p.x, y = p.y;



    if ((sx <= x && tx >= x && sy <= y && ty >= y)) {

        inPts.push_back(p);

    }



    if (depth % 2 == 0) {

        if (ns[nodeId].ru_id !=-1 && tx >= x)

            queryRect(sx, sy, tx, ty, ns[nodeId].ru_id, depth + 1, inPts);

        if (ns[nodeId].ld_id !=-1 && sx <= x)

            queryRect(sx, sy, tx, ty, ns[nodeId].ld_id, depth + 1, inPts);

    }

    else{

        if (ns[nodeId].ru_id !=-1 && ty >= y)

            queryRect(sx, sy, tx, ty, ns[nodeId].ru_id, depth + 1, inPts);

        if (ns[nodeId].ld_id !=-1 && sy <= y)

            queryRect(sx, sy, tx, ty, ns[nodeId].ld_id, depth + 1, inPts);

    }

}


