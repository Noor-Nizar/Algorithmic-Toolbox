#include <iostream>
#include <vector>


using namespace std;

int BinarySearch(vector<int> &arr, int low, int high, int key){
    if(low > high)
        return -1;
    int mid = low+(high-low)/2;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return BinarySearch(arr, low, mid-1, key);
    else
        return BinarySearch(arr, mid+1, high, key);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    int key;
    for (size_t i = 0; i < k; i++)
    {
        cin >> key;
        cout << BinarySearch(arr, 0, arr.size()-1, key) << " ";
    }
    return 0;
}