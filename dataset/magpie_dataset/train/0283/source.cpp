#include<vector>

#include<iostream>



using namespace std;



class Cake;



vector<Cake> pieces;



class Cake {

public:

  int w;

  int d;



  Cake(int w, int d) {

    this->w = w;

    this->d = d;

  }



  void cut(int s) {

    int t = s%(w+d);

    int a, b;

    if(t<w) {

      // vertical

      if(t<w-t) {

	a = t;

	b = w-t;

      } else {

	a = w-t;

	b = t;

      }

      pieces.push_back(Cake(a, d));

      pieces.push_back(Cake(b, d));

    }

    else {

      // horizontal

      t -= w;

      if(t<d-t) {

	a = t;

	b = d-t;

      } else {

	a = d-t;

	b = t;

      }

      pieces.push_back(Cake(w, a));

      pieces.push_back(Cake(w, b));

    }

  }

};



bool area(const Cake &a, const Cake &b) {

  return a.w*a.d < b.w*b.d;

}



int main() {

  while(1) {

    int n, w, d;

    cin >> n;

    cin >> w;

    cin >> d;



    if(n==0 && w==0 && d==0) break;



    pieces.clear();

    pieces.push_back(Cake(w, d));



    for(int i=0; i<n; i++) {

      int p, s;

      cin >> p;

      cin >> s;

      // p Í 1` ÈÌÅ

      p-=1;

      vector<Cake>::iterator it = pieces.begin()+p;

      Cake cake = pieces.at(p);

      pieces.erase(it);

      cake.cut(s);

    }



    // sort

    int count=0;

    for(int i=0; i<10000; i++) {

      for(int j=0; j<pieces.size(); j++) {

	int s = pieces.at(j).w * pieces.at(j).d;

	if(s==i) {

	  cout << s;

	  count++;

	  if(pieces.size()!=count) {

	    cout << ' ';

	  }

	}

      }

      //sort(pieces.begin(), pieces.end(), area);

    }





    /*

    for(int i=0; i<pieces.size(); i++) {

      cout << (pieces.at(i).w * pieces.at(i).d);

      cout << ' ';

    }

    */

    cout << "\n";

  }

}