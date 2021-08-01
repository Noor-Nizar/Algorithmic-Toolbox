#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long>ppc(n);
    vector<long long>slot(n);
    for (int i = 0; i < n; i++)
        cin >> ppc[i];
    for (int i = 0; i < n; i++)
        cin >> slot[i];

    sort(ppc.begin(), ppc.end());
    sort(slot.begin(), slot.end());
    long long sum = 0;
    for (int i = n-1; i >= 0; i--)
       sum += (ppc[i] * slot[i]) > 0 ? (ppc[i] * slot[i]) : 0;
    
    cout << sum;
    return 0;
}