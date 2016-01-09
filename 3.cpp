#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ifstream infile("3.in");
  set< pair<int, int> > visited;
  int currentX = 0, currentY = 0;
  int inputSize = 8192;
  visited.insert(make_pair(0, 0));
  for(int i = 0; i < inputSize; i++ ) {
    char c;
    infile >> c;
    switch(c) {
      case '^': 
      currentY++;
      break;
      case 'v':
      currentY--;
      break;
      case '>':
      currentX++;
      break;
      case '<':
      currentX--;
      break;
    }
    visited.insert(make_pair(currentX, currentY));
  }
  cout << visited.size() << endl;
  return 0;
}
