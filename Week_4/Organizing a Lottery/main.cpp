#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sol(int sNum, int ptNum){
    sNum*=2;
    vector<vector<int>> db(sNum + ptNum,vector<int>(3));
    int i = 0;
    while(i < sNum)
    {
        cin >> db[i][0];
        db[i][1] = -1;
        cin >> db[++i][0];
        db[i][1] = -2;
        i++;
    }
    for (int i = sNum; i < sNum + ptNum; i++)
    {
        cin >> db[i][0];
        db[i][1] = 0;
        db[i][2] = i;
    }

    sort(db.begin(), db.end(), [](const vector<int>&v1, const vector<int>&v2){
        if(v1[1] < 0 && v2[1] < 0) {
            return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] > v2[1];
            }
        if(v1[1] == -1 || v2[1] == -1) {
            return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] < v2[1];
            }
        else return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] > v2[1];
    });

    int incrementor = 0;
    for (int i = 0; i < sNum+ptNum; i++)
    {
        if(db[i][1] == -1) {
            incrementor++;
            continue;
            }
        if(db[i][1] == -2){
            incrementor--;
            continue;
        } 

        db[i][1] += incrementor;
    }
    sort(db.begin(), db.end(), [](const vector<int>&v1, const vector<int>&v2){
        return v1[2] < v2[2];
    });

    vector<int> Res(ptNum);
    for (int i = sNum; i < ptNum+sNum; i++)
        Res[i-sNum] = db[i][1];
    return Res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int sNum;int ptNum;
    cin >> sNum >> ptNum;
    vector<int> ResFast = sol(sNum,ptNum);

    for (int i = 0; i < ResFast.size(); i++)
    {
        cout << ResFast[i] << " ";
    }
    
    return 0;
}
