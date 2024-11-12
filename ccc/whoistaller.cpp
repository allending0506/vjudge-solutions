#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> taller[100000];

void findPath(int p, int q, int n, int m){
  queue<int> visitNextTaller;
  queue<int> visitNextShorter;
  bool visitedTaller[100000] {false};
  bool visitedShorter[100000] {false};
  visitNextTaller.push(p);
  visitNextShorter.push(q);
  while (!visitNextTaller.empty() || !visitNextShorter.empty()){
    if (!visitNextTaller.empty()){
      visitedTaller[visitNextTaller.front()] = true;
      if (visitNextTaller.front() == q){
        cout << "yes";
        return;
      }
      for (auto& i : taller[visitNextTaller.front()]){
        if(!visitedTaller[i]){
          visitNextTaller.push(i);
          visitedTaller[i] = true;
        }
      }
      visitNextTaller.pop();
    }
    if (!visitNextShorter.empty()){
      visitedShorter[visitNextShorter.front()] = true;
      if (visitNextShorter.front() == p){
        cout << "no";
        return;
      }
      for (auto& i : taller[visitNextShorter.front()]){
        if(!visitedShorter[i]){
          visitNextShorter.push(i);
          visitedShorter[i] = true;
        }
      }
      visitNextShorter.pop();
    }
  }
  cout << "unknown";
}

int main(){
  int n, m, p, q;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int tem1, tem2;
    cin >> tem1 >> tem2;
    taller[tem1].push_back(tem2);
  }
  cin >> p >> q;
  findPath(p, q, n, m);
  return 0;
}
