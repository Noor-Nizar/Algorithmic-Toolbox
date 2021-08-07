#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

double solveBrute(vector<int>&x, vector<int>&y){
  double minv = 100000000000000;
  for (int i = 0; i < x.size(); i++)
  {
    for (int j = i+1; j < y.size(); j++)
    {
      minv = min(sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)),minv); 
    }
  }
  return minv;
}

double minimal_distance(vector<int> x, vector<int> y) {
  if(x.size() <= 3)
    return solveBrute(x,y);
  
  int mid = x.size()/2;
  vector<int> pt1x(x.begin(), x.begin()+mid);
  vector<int> pt1y(y.begin(), y.begin()+mid);

  vector<int> pt2x(x.begin()+mid, x.begin()+x.size());
  vector<int> pt2y(y.begin()+mid, y.begin()+y.size());
  double min1 = minimal_distance(pt1x,pt1y);
  double min2 = minimal_distance(pt2x,pt2y);

  double minComb = min(min1,min2);
  vector<int>slx(0);vector<int>sly(0);int counter = 0;
  for (int i = 0; i < x.size(); i++)
  {
    //if(x[i] == x[mid]) continue;
    if(x[i] < x[mid]+minComb && x[i] > x[mid] - minComb){
      slx.resize(slx.size()+1);sly.resize(sly.size()+1);
      slx[counter] = x[i];
      sly[counter] = y[i];
      counter++;
    }
  }
  double minRangerRover = minimal_distance(slx,sly);
  return min(minComb,minRangerRover);
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
