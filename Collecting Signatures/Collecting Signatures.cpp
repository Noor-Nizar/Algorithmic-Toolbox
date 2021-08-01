#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> db(n, vector<ll>(2));
    for (int i = 0; i < n; i++){
        cin >> db[i][0] >> db[i][1];
    }
    sort(db.begin(), db.end(), [](const vector<ll>&v1,const vector<ll>&v2){
        return v1[0] < v2[0];
    });
    
    int counter = 0;
    vector<ll>pts(n,-1);
    while(db.size()){
        int i = 1;ll maxS = db[0][0];ll minE = db[0][1];
        while(i < db.size()){
            if(db[i][0] <= minE){
                minE = min(minE, db[i][1]);
                maxS = max(maxS, db[i][0]);
                i++;
            }else break;
        }
        pts[counter] = maxS;
        counter++;
        db.erase(db.begin(), db.begin()+i);
    }
    cout << counter << endl;
    while(counter--)
        if(pts[counter] != -1)
            cout << pts[counter] << " ";
    return 0;
}
