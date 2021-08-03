#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int sNum;int ptNum;
    cin >> sNum >> ptNum;
    sNum*=2;
    vector<vector<int>> db(sNum + ptNum,vector<int>(3));
    int i = 0;
    while(i < sNum)
    {
        cin >> db[i][0];
        db[i][1] = -(i+2);
        db[i][2] = 1;
        cin >> db[++i][0];
        db[i][1] = -(i-1+2);
        i++;
    }
    for (int i = sNum; i < sNum + ptNum; i++)
    {
        cin >> db[i][0];
        db[i][1] = 0;
    }
    // for (int i = 0; i < sNum+ptNum; i++)
    // {
    //     cout << db[i][0] << " : " << db[i][1] << endl;
    // }
    

    sort(db.begin(), db.end(), [](const vector<int>&v1, const vector<int>&v2){
        return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] > v2[1] && v1[2] > v2[2];
    });

    cout << endl;
    for (int i = 0; i < sNum+ptNum; i++)
    {
        cout << db[i][0] << " : " << db[i][1] << " : " << db[i][2] << endl;
    } cout << endl;

    vector<int> Res(ptNum);
    int incrementor = 0;
    for (int i = 0; i < sNum+ptNum; i++)
    {
        if(db[i][2] == 1) {
            incrementor++;
            continue;
            }
        if(db[i][1] < 0 &&db[i][2] == 0){
            incrementor--;
            continue;
        } 

        db[i][1] += incrementor;
    }
    for (int i = 0; i < ptNum+sNum; i++)
    {
        if(db[i][1] < 0) continue;
        cout << db[i][1] << " ";
    }
    

    return 0;
}