//CCC '00 J1 - Calendar
//https://dmoj.ca/problem/ccc00j1

#include <iostream>
using namespace std;

int main(){
  int d, n;
  cin >> d >> n;
  cout << "Sun Mon Tue Wed Thr Fri Sat\n";
  int dayOfWeek = 1;
  for (int i = 0; i < d - 1; i++){
    cout << "    ";
    dayOfWeek++;
  }
  for (int i = 1; i <= n; i++){
    if (i <= 9){
      cout << " ";
    }
    cout << " " << i;
    if (dayOfWeek % 7 != 0 && i != n){
      cout << " ";
    }
    if (dayOfWeek % 7 == 0 || i == n){
      cout << "\n";
    }
    dayOfWeek++;
  }
  return 0;
}
