#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 0,dist,fuel;
    cin >> dist;
    cin >> fuel;
    cin >> n;
    vector<int> arr(n);
    arr.push_back(0);
    for (int i = 1; i <= n; i++)
        cin >>  arr[i];

    arr.push_back(dist);
    int i = 1;int refs = 0;
    while(i < arr.size()){
        while(arr[i] - arr[0] <= fuel && i < arr.size()){
            i++;
        }
        if(i == 1){
            refs = -1;
            break;
        }
        refs += i < arr.size() ? 1 : 0;
        arr.erase(arr.begin(),arr.begin()+i-1);
        i = 1;
    }
    cout << refs;
    return 0;
}