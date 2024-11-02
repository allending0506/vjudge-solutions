//CCC '03 S3 - Floor Plan
//https://dmoj.ca/problem/ccc03s3

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <utility>
using namespace std;

bool floorplan[27][27] {false};
bool visited[27][27] {false};

pair<int, int> findStart(bool floorplan[27][27], int sizeX, int sizeY, bool visited [27][27]){ //iterates through floorplan to find first empty space, returns {-1, -1} if none found
  int startX {-1};
  int startY {-1};
  for (int i = 0; i < sizeX; i++){
    if (startX != -1){
      break;
    }
    for (int j = 0; j < sizeY; j++){
      if (floorplan[i][j] && !visited[i][j]){
        startX = i;
        startY = j;
        break;
      }
    }
  }
  return {startX, startY};
}

vector<int> findRooms(bool floorplan[27][27], int sizeX, int sizeY){ //sizeX = r + 2, sizeY = c + 2
  vector<int> sizes {0};
  stack<pair<int, int>> visitNext;
  visitNext.push(findStart(floorplan, sizeX, sizeY, visited));
  while (visitNext.top().first != -1){ //iterates through each room
    while (!visitNext.empty()){ //iterates within room
      int temX = visitNext.top().first;
      int temY = visitNext.top().second;
      sizes[sizes.size() - 1]++; //update size of current room
      visited[temX][temY] = true;
      visitNext.pop();
      if (!visited[temX + 1][temY] && floorplan[temX + 1][temY]){ //add neighbours of each cell
        visitNext.push({temX + 1, temY});
        visited[temX + 1][temY] = true;
      }
      if (!visited[temX - 1][temY] && floorplan[temX - 1][temY]){
        visitNext.push({temX - 1, temY});
        visited[temX - 1][temY] = true;
      }
      if (!visited[temX][temY + 1] && floorplan[temX][temY + 1]){
        visitNext.push({temX, temY + 1});
        visited[temX][temY + 1] = true;
      }
      if (!visited[temX][temY - 1] && floorplan[temX][temY - 1]){
        visitNext.push({temX, temY - 1});
        visited[temX][temY - 1] = true;
      }
    }
    visitNext.push(findStart(floorplan, sizeX, sizeY, visited));
    sizes.push_back(0); //add new room
  }
  return sizes;
}

int main(){
  int n, r, c;
  cin >> n >> r >> c;
  for (int i = 1; i <= r; i++){
    for (int j = 1; j <= c; j++){
      char tem;
      cin >> tem;
      if (tem == '.'){
        floorplan[i][j] = true;
        continue;
      }
    }
  }
  vector<int> sizes = findRooms(floorplan, r+2, c+2);
  multiset<int, greater<int>> sorted; //sort rooms from largest to smallest
  for (auto& i : sizes){
    //cout << i;
    if (i != 0){
      sorted.insert(i);
    }
  }
  int rooms{};
  for (auto& i : sorted){ //compute # of rooms and leftover
    if (n < i){
      break;
    }
    n -= i;
    rooms++;
  }
  cout << rooms << (rooms == 1? "room, " : "rooms, ") << n << " square metre(s) left over";
  return 0;
}
