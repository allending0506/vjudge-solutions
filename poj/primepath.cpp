//NOTE: DOES NOT WORK YET
//CURRENTLY TLE
//https://vjudge.net/problem/POJ-3126

#include <iostream>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;

bool prime[10000];
bool visited[10000];

struct Node {
  string val;
  int layer;
  Node(string m, int n){
    val = m;
    layer = n;
  }
};

void cost(Node start, string target){
  queue<Node> visitNext;
  visitNext.push(start);
  memset(visited, false, sizeof(visited));
  while (!visitNext.empty()){
    if (visitNext.front().val == target){
      printf("%d\n", visitNext.front().layer);
      return;
    }
    for (int i = 1; i < 37; i++){
      string tem = visitNext.front().val;
      if (i != 36){
        tem[(i - (i % 9)) / 9] = i % 9 + '0';
      }
      if (i == 36){
        tem[3] = '9';
      }
      int num;
      istringstream(tem) >> num;
      if (prime[num] && !visited[num]){
        Node stem(tem, visitNext.front().layer + 1);
        visitNext.push(stem);
        visited[num] = true;
      }
    }
    visitNext.pop();
  }
  printf("Impossible\n");
}

int main(){
  memset(prime, true, sizeof(prime));
  for (int i = 2; i < 10000; i++){
    if (prime[i]){
      for (int j = 2 * i; j < 10000; j += i){
        prime[j] = false;
      }
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int start, target;
    scanf("%d%d", &start, &target);
    ostringstream tstart, ttarget;
    tstart << start;
    ttarget << target;
    Node sstart(tstart.str(), 0);
    cost(sstart, ttarget.str());
  }
  return 0;
}
