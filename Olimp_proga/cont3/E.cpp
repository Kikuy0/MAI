#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n, count = 0;
  bool fl = true;
  cin >> n;
  stack<char> arr;
  arr.push('0');
  for (int i = 0; i < n; ++i) {
    char k;
    cin >> k;
    if ((k == '(') || (k == '{') || (k == '[')) {
      arr.push(k);
      count++;
    } else {
      if ((k == ')') && (arr.top() == '(')) {
        arr.pop();
        count--;
      } else if ((k == ']') && (arr.top() == '[')) {
        arr.pop();
        count--;
      } else if ((k == '}') && (arr.top() == '{')) {
        arr.pop();
        count--;
      } else {
        fl = false;
        break;
      }
    }
  }
  if ((fl) && (count == 0)) {
    cout << "Ja"
         << "\n";
  } else {
    cout << "Nein"
         << "\n";
  }
}
