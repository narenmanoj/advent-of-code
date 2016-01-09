#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

bool nice(string s) {
  int length = s.length();
  for(int i = 1; i < length; i++ ) {
    if(s[i - 1] == 'a' && s[i] == 'b') {
      return false;
    }
    if(s[i - 1] == 'c' && s[i] == 'd') {
      return false;
    }
    if(s[i - 1] == 'p' && s[i] == 'q') {
      return false;
    }
    if(s[i - 1] == 'x' && s[i] == 'y') {
      return false;
    }
  }
  for(int i = 1; i < length; i++ ) {
    if(s[i - 1] == s[i]) {
      break;
    }
    if(i == length - 1) {
      if(s[i - 1] != s[i]) {
        return false;
      }
    }
  }
  int vowelCount = 0;
  for(int i = 0; i < length; i++ ) {
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
      vowelCount++;
    }
    if(vowelCount == 3) {
      return true;
    }
  }
  return false;
}

int main() {
  int loi = 1000;
  ifstream infile("5.in");
  int ans = 0;
  for(int i = 0; i < loi; i++ ) {
    string x;
    getline(infile, x);
    ans += nice(x);
  }
  cout << ans << endl;
  return 0;
}
