#include <iostream>
#include <vector>

using namespace std;

int maxGold(int cap, vector<int>bars){

    vector<vector<int>> DPT(bars.size()+1, vector<int>(cap + 1));

    for (int i = 0; i < cap+1; i++)
        DPT[0][i] = 0;
        
    for (int i = 0; i < bars.size()+1; i++)
        DPT[i][0] = 0;

    for (int j = 1; j < bars.size()+1; j++){
        for (int i = 1; i < cap+1; i++){
            if(bars[j-1] <= i){
                DPT[j][i] = max(DPT[j-1][i], DPT[j-1][i-bars[j-1]]+bars[j-1]);
            }
            else
                DPT[j][i] = DPT[j-1][i];
        }
    }
    

    return DPT[bars.size()][cap];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cap;
    int n;
    cin >> cap >> n;

    vector<int> bars(n);
    for (int i = 0; i < n; i++)
        cin >> bars[i];
    

    cout << maxGold(cap, bars);
    return 0;
}