#include<iostream>

#include<vector>

using namespace std;



class Section

{

private:

  int _begin, _end;

public:

  Section(int b, int e)

  {

    _begin = b;

    _end = e;

  }



  int begin()

  {

    return _begin;

  }



  int end()

  {

    return _end;

  }



  int length()

  {

    return end() - begin();

  }

};



vector<Section> sections;

bool card[100002];

int K, N;

int main()

{

loop:

  fill(card, card + 100002, false);

  sections.clear();



  cin >> N >> K;

  if(!N)

    return 0;

  for(int i = 0; i < K; i++)

  {

    int a;

    cin >> a;

    card[a] = true;

  }



  bool keep = false;

  int st, ans = 0;

  for(int i = 1; i <= N + 1; i++)

  {

    if(keep && !card[i])

    {

      sections.push_back(Section(st, i));

      keep = false;

    }

    if(!keep && card[i])

    {

      st = i;

      keep = true;

    }

  }

    

  for(auto it = sections.begin(); it != sections.end(); ++it)

  {

    if(card[0] && (it + 1) != sections.end() && it->end() + 1 == (it + 1)->begin())

      ans = max(ans, it->length() + (it + 1)->length() + 1);

    if(card[0])

      ans = max(ans, it->length() + 1);

    ans = max(ans, it->length());

  }

  cout << ans << endl;

  goto loop;

}