#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long cap;
    cin >> cap;

    long long i = 1;int nSols = 0;
    vector <long long> sols(1);
    while (cap)
    {
        if(cap == i || cap > i && cap - i >= i + 1){
            cap -= i;
            sols.resize(++nSols);
            sols[nSols-1] = i;
        }i++;
    }

    cout << nSols << endl;
    for (int i = 0; i < nSols; i++)
    {
        cout << sols[i] << " ";
    }
    
    return 0;
}