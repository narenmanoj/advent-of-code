#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;

int powerOfTen(int i) {
  if(i == 0) return 1;
  return 10 * powerOfTen(i - 1);
}

int solve(string s) {
  int currentNum;
  int ans = 0;
  currentNum = 0;
  int placeVal = 0;
  vector<int> numbers(3);
  int numCount = 0;
  for(int i = s.length() - 1; i >= 0; i-- ) {
    if(s[i] == 'x' || i == 0) {
      // ans *= currentNum;
      if(i == 0) {
        currentNum += (powerOfTen(placeVal) * (s[i] - '0'));
      }
      numbers[numCount] = currentNum;
      numCount++;
      currentNum = 0;
      placeVal = 0;
      continue;
    }
    currentNum += (powerOfTen(placeVal) * (s[i] - '0'));
    placeVal++;
  }
  cout << "first: " << numbers[0] << " second: " << numbers[1] << " third: " << numbers[2] << endl;
  ans = 2 * (numbers[0] * numbers[1] + numbers[0] * numbers[2] + numbers[1] * numbers[2]);
  int prod = (numbers[0] * numbers[1] * numbers[2]) / max(max(numbers[1], numbers[2]), numbers[0]);
  ans += prod;
  return ans;
}

int main() {
  int numLines = 1000;
  ifstream infile("2.in");
  ll ans = 0;
  cout << solve("2x3x4") << endl;
  for(int i = 0; i < numLines; i++ ) {
    string toConsider;
    getline(infile, toConsider);
    ans += solve(toConsider);
  }
  cout << ans << endl;
  return 0;
}
