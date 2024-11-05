//CCC '00 J2 - 9966
//https://dmoj.ca/problem/ccc00j2

#include <iostream>
#include <string>
using namespace std;

int flip(int i){
  string tem = to_string(i);
  string build = "";
  for (int i = tem.length() - 1; i >= 0; i--){
    if (tem[i] != '0' && tem[i] != '1' && tem[i] != '8' && tem[i] != '6' && tem[i] != '9'){
      return -1;
    }
    if (tem[i] == '0' || tem[i] == '1' || tem[i] == '8'){
      build += tem[i];
    }
    if (tem[i] == '9'){
      build += '6';
    }
    if (tem[i] == '6'){
      build += '9';
    }
  }
  return stoi(build);
}

int main(){
  int m, n;
  cin >> m >> n;
  int count {};
  for (int i = m; i <= n; i++){
    if (flip(i) == i){
     count++;
    }
  }
  cout << count;
  return 0;
}
