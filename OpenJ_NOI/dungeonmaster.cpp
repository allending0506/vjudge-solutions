//https://vjudge.net/problem/OpenJ_NOI-CH0205-1253

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
  int x, y, z, layer;
  void set(int ix, int iy, int iz, int l){
    x = ix;
    y = iy;
    z = iz;
    layer = l;
  }
};

int bfs(bool dungeon[32][32][32], Node start, Node exit){
  queue<Node> q;
  bool visited[32][32][32];
  memset(visited, false, sizeof(visited));
  q.push(start);
  while (!q.empty()){
    Node tem;
    tem.set(q.front().x, q.front().y, q.front().z, q.front().layer);
    q.pop();
    if (tem.x == exit.x && tem.y == exit.y && tem.z == exit.z){
      return tem.layer;
    }
    if (dungeon[tem.x - 1][tem.y][tem.z] && !visited[tem.x - 1][tem.y][tem.z]){
      visited[tem.x - 1][tem.y][tem.z] = true;
      Node p;
      p.set(tem.x - 1, tem.y, tem.z, tem.layer + 1);
      q.push(p);
    }
    if (dungeon[tem.x + 1][tem.y][tem.z] && !visited[tem.x + 1][tem.y][tem.z]){
      visited[tem.x + 1][tem.y][tem.z] = true;
      Node p;
      p.set(tem.x + 1, tem.y, tem.z, tem.layer + 1);
      q.push(p);
    }
    if (dungeon[tem.x][tem.y - 1][tem.z] && !visited[tem.x][tem.y - 1][tem.z]){
      visited[tem.x][tem.y - 1][tem.z] = true;
      Node p;
      p.set(tem.x, tem.y - 1, tem.z, tem.layer + 1);
      q.push(p);
    }
    if (dungeon[tem.x][tem.y + 1][tem.z] && !visited[tem.x][tem.y + 1][tem.z]){
      visited[tem.x][tem.y + 1][tem.z] = true;
      Node p;
      p.set(tem.x, tem.y + 1, tem.z, tem.layer + 1);
      q.push(p);
    }
    if (dungeon[tem.x][tem.y][tem.z - 1] && !visited[tem.x][tem.y][tem.z - 1]){
      visited[tem.x][tem.y][tem.z - 1] = true;
      Node p;
      p.set(tem.x, tem.y, tem.z - 1, tem.layer + 1);
      q.push(p);
    }
    if (dungeon[tem.x][tem.y][tem.z + 1] && !visited[tem.x][tem.y][tem.z + 1]){
      visited[tem.x][tem.y][tem.z + 1] = true;
      Node p;
      p.set(tem.x, tem.y, tem.z + 1, tem.layer + 1);
      q.push(p);
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int l, r, c;
  cin >> l >> r >> c;
  bool dungeon[32][32][32];
  Node start, exit;
  while (l || r || c){
    memset(dungeon, false, sizeof(dungeon));
    for (int i = 1; i <= l; i++){
      for (int j = 1; j <= r; j++){
        for (int k = 1; k <= c; k++){
          char tem;
          cin >> tem;
          if (tem == '#'){
            dungeon[i][j][k] = false;
            continue;
          }
          dungeon[i][j][k] = true;
          if (tem == 'S'){
            start.set(i, j, k, 0);
            continue;
          }
          if (tem == 'E'){
            exit.set(i, j, k, 0);
          }
        }
      }
    }
    int tem = bfs(dungeon, start, exit);
    if (tem == -1){
      cout << "Trapped!\n";
    } else {
      cout << "Escaped in " << tem << " minute(s).\n";
    }
    cin >> l >> r >> c;
  }
  return 0;
}
