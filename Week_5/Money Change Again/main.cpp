#include <iostream>
#include <vector>

using namespace std;

int getChangeCount(int m){
    int Denom[] = {1,3,4};
    vector<int> DPT(m+1);
    for (int moni = 1; moni < m+1; moni++)
    {
        int minIndx = 2147483647;
        for (int coin = 0; coin < 3; coin++)
            if(Denom[coin] <= moni)
                minIndx = min(minIndx, DPT[moni - Denom[coin]] + 1);

        DPT[moni] = minIndx;
    }


    return DPT[DPT.size()-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int money;
    cin >> money;
    cout << getChangeCount(money);
    return 0;
}