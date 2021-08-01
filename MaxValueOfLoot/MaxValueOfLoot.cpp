#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/*
Sort the 2D vector based on best Value instead
*/
int main(){
    int nItems, cap;
    double Value = 0;
    cin >> nItems >> cap;
    vector<vector<int>> db(nItems, vector<int>(1));
    for (int i = 0; i < nItems; i++)
    {
        cin >> db[i][0] >> db[i][1];
    }
    while(cap && db.size()){
        double bestVal = 0;int indx = 0;
        for (int i = 0; i < db.size(); i++)
            if((double)db[i][0]/db[i][1] > bestVal){
                indx = i;
                bestVal = (double)db[i][0]/db[i][1];
            }

        double qt = min(db[indx][1], cap);
        cap -= qt;
        Value += qt*bestVal; 
        if(db[indx][1]-qt >0)
            db[indx][1] -= qt;
        else db.erase(db.begin() + indx);
    }
    cout << setprecision(4) << fixed << Value;
    
    
    return 0;
}