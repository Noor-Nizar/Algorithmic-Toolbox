#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

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
    // for (int i = 0; i < sNum+ptNum; i++)
    // {
    //     cout << db[i][0] << " : " << db[i][1] << endl;
    // }
    

    sort(db.begin(), db.end(), [](const vector<int>&v1, const vector<int>&v2){
        if(v1[1] < 0 && v2[1] < 0) {
            return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] > v2[1];
            }
        if(v1[1] == -1 || v2[1] == -1) {
            return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] < v2[1];
            }
        else return v1[0] < v2[0] || v1[0] == v2[0] &&  v1[1] > v2[1];
    });

    //cout << endl;
    for (int i = 0; i < sNum+ptNum; i++)
    {
        //cout << db[i][0] << " : " << db[i][1] << " : " << db[i][2] << endl;
    } //cout << endl;

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

    for (int i = 0; i < sNum+ptNum; i++)
    {
        //cout << db[i][0] << " : " << db[i][1] << " : " << db[i][2] << endl;
    } //cout << endl;
    vector<int> Res(ptNum);
    for (int i = sNum; i < ptNum+sNum; i++)
    {
        Res[i-sNum] = db[i][1];
    }
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
    


    // //Naive for debugging 
    // int m = ptNum;
    // vector<int> starts(sNum), ends(sNum);
    // for (size_t i = 0; i < starts.size(); i++) {
    //     std::cin >> starts[i] >> ends[i];
    // }
    // vector<int> points(m);
    // for (size_t i = 0; i < points.size(); i++) {
    //     std::cin >> points[i];
    // }
    // //use fast_count_segments
    // vector<int> cnt = naive_count_segments(starts, ends, points);
    // for (size_t i = 0; i < cnt.size(); i++) {
    //     std::cout << cnt[i] << ' ';
    // }
    
    return 0;
}