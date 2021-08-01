#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int nDigs(int a){
    int i = 1;
    while((a /= 10) > 0) {
        i++;
    }
    return i;
}
int digX(int a, int p){
    int paw = pow(10,p);
    return a%paw/(paw/10);
}
int main(){
    int n;
    cin >> n;
    vector <int> db(n);
    while(n--)
        cin >> db[n];

    while(db.size()){
        int best = db[0];
        int indx = 1;int bestIndx = 0;
        while(indx < db.size()){
            int nbest = nDigs(best);
            int ncurr = nDigs(db[indx]);
            for (int i = nbest, j = ncurr; i >= 1 || j >= 1; i--, j--)
            {
                i = max(i, 1);j = max(j, 1);
                if(digX(best,i) < digX(db[indx],j)){
                    best = db[indx];
                    bestIndx = indx;
                    break;
                }else if(digX(best,i) > digX(db[indx],j))
                    break;
            }indx++;

            
        }
        cout << *(db.begin()+bestIndx);
        db.erase(db.begin()+bestIndx);
    }

    return 0;
}