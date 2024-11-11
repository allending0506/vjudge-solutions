//CCC '01 S3 - Strategic Bombing
//https://dmoj.ca/problem/ccc01s3

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> roads;

vector<char> connections(char search, string elim){
  vector<char> val;
  for (auto& i : roads){
    if (i == elim){
      continue;
    }
    if (search == i[0]){
      val.push_back(i[1]);
    }
    if (search == i[1]){
      val.push_back(i[0]);
    }
  }
  return val;
}

vector<string> disconnecting(vector<string>& roads){
  vector<string> disconnectingRoads;
  for (int i = 0; i < roads.size(); i++){
    bool visited[26] {false};
    queue<char> visitNext;
    bool connected = false;
    visitNext.push('A');
    while (!visitNext.empty()){
      if (visitNext.front() == 'B'){
        connected = true;
        break;
      }
      visited[visitNext.front() - 'A'] = true;
      vector<char> tem = connections(visitNext.front(), roads[i]);
      for (int j = 0; j < tem.size(); j++){
        if (!visited[(tem[j] - 'A')]){
          visitNext.push(tem[j]);
        }
      }
      visitNext.pop();
    }
    if (!connected){
      disconnectingRoads.push_back(roads[i]);
    }
  }
  return disconnectingRoads;
}

int main(){
  while (true){
    string tem;
    cin >> tem;
    if (tem == "**"){
      break;
    }
    roads.push_back(tem);
  }
  for (auto& i : disconnecting(roads)){
    cout << i << "\n";
  }
  cout << "There are " << disconnecting(roads).size() << " disconnecting roads.\n";
  return 0;
}
