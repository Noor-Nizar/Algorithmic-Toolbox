#include <iostream>
#include <vector>
#include <string>

using namespace std;

int EditDistance(string s1, string s2){
    int lenS1 = s1.length()+1;
    int lenS2 = s2.length()+1;
    vector<vector<int>> DPT(lenS2,vector<int>(lenS1));

    for (int i = 0; i < lenS2; i++)
        DPT[i][0] = i;

    for (int i = 0; i < lenS1; i++)
        DPT[0][i] = i;

    for (int i = 1; i < lenS2; i++)
        for (int j = 1; j < lenS1; j++)
            if(s1[j-1] == s2[i-1])
                DPT[i][j] = DPT[i-1][j-1];
            else
                DPT[i][j] = min(min(DPT[i-1][j-1],DPT[i-1][j]), DPT[i][j-1])+1;
    

    return DPT[lenS2-1][lenS1-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s1; string s2;
    cin >> s1;
    cin >> s2;

    cout << EditDistance(s1,s2);
    return 0;
}