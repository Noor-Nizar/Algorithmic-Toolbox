#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void sortByX(vector<int>&x, vector<int>&y){
  
}

double minimal_distance(vector<int> x, vector<int> y) {
  if(x.size() == 2)
    return sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2));
  else if(x.size() == 1)
    return 2*pow(10,3);
  
  int mid = x.size()/2;
  vector<int> pt1x(x.begin(), x.begin()+mid);
  vector<int> pt1y(y.begin(), y.begin()+mid);

  vector<int> pt2x(x.begin()+mid, x.begin()+mid*2);
  vector<int> pt2y(y.begin()+mid, y.begin()+mid*2);
  vector<int> ptMidPTx(x.begin()+mid-1, x.begin()+mid+1);
  vector<int> ptMidPTy(y.begin()+mid-1, y.begin()+mid+1);

  double min1 = minimal_distance(pt1x,pt1y);
  double min2 = minimal_distance(pt2x,pt2y);
  double min3 = minimal_distance(ptMidPTx, ptMidPTy);


  return min(min3,min(min1,min2));
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<vector<int>> pts(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    std::cin >> pts[i][0] >> pts[i][1];
  }
  sort(pts.begin(), pts.end(), [](const vector<int>&v1, const vector<int>&v2){
    return v1[0] < v2[0];
  });
  for (int i = 0; i < n; i++)
  {
    x[i] = pts[i][0];
    y[i] = pts[i][1];
  }
  
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}