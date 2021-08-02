#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int> A, vector<int> B){
    vector<int>Res(A.size() + B.size());
    for (int i = 0,j = 0; i < A.size() || j < B.size();)
    {
        if(i == A.size()){
            Res[i+j] = B[j];
            j++;
        }
        else if(j == B.size()){
            Res[i+j] = A[i];
            i++;
        }
        else if(A[i] <= B[j]){
            Res[i+j] = A[i];
            i++;
        }
        else if(A[i] > B[j]){
            Res[i+j] = B[j];
            j++;
        }
    }
    return Res;
}

vector<int> MergeSort(vector<int> V){
    if(V.size() == 1)
        return V;

    int mid = V.size()/2;
    vector<int> V1(V.begin(), V.begin()+mid);
    vector<int> A = MergeSort(V1);

    vector<int> V2(V.begin()+mid,V.begin()+V.size());
    vector<int> B = MergeSort(V2);
    return Merge(A,B);
}






int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> sorted = MergeSort(arr);
    int Max = 0;int cur =sorted[0];int indx = 0;
    for (int i = 0; i < sorted.size(); i++)
    {
        if(sorted[i] == cur){
            Max++;
            if(Max > sorted.size()/2) {
                indx = i;
                break;
            }
        }
        else{
            Max = 1;
            cur = sorted[i];
        }
    }
    cout << (sorted.size()>1?(indx == 0 ? 0 : 1):1);
    return 0;
}