#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int> A, vector<int> B,int &b){
    vector<int> res(A.size()+B.size());
    int sA = A.size();int sB = B.size();
    for (int i = 0,j = 0; i < sA || j < sB;){
        if(i == sA){
            res[i+j] = B[j];
            j++;
        }else if(j == sB){
            res[i+j] = A[i];
            i++;
        }else if(A[i] <= B[j]){
            res[i+j] = A[i];
            i++;
        }else if(A[i] > B[j]){
            res[i+j] = B[j];
            b+=A.size()-i;
            j++;
        }
    }
    return res;
}

vector<int> MergeSort(vector<int> v,int &b){
    if(v.size() == 1)
        return v;
    
    int mid = v.size()/2;
    vector<int>part1(v.begin(), v.begin()+mid);
    vector<int>part2(v.begin()+mid, v.begin()+v.size());
    vector<int> A = MergeSort(part1, b);
    vector<int> B = MergeSort(part2, b);
    return Merge(A,B,b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    int count = 0;  
    MergeSort(v1,count);
    cout << count;
    return 0;
}

