#include <iostream>
#include <vector>
#include <string>

using namespace std;

int EditDistance(vector<int> s1, vector<int> s2, vector<int>s3){
    int lenS1 = s1.size()+1;
    int lenS2 = s2.size()+1;
    int lenS3 = s3.size()+1;
    vector<vector<vector<int>>> DPT(lenS2,vector<vector<int>>(lenS1,vector<int>(lenS3)));

    for (int i = 0; i < lenS2; i++)
        DPT[i][0][0] = 0;

    for (int i = 0; i < lenS1; i++)
        DPT[0][i][0] = 0;

    for (int i = 0; i < lenS3; i++)
        DPT[0][0][i] = 0;

    for (int k = 1; k < lenS3; k++)
       for (int i = 1; i < lenS2; i++)
        for (int j = 1; j < lenS1; j++)
            if(s1[j-1] == s2[i-1] && s1[j-1] == s3[k-1])
                DPT[i][j][k] = DPT[i-1][j-1][k-1]+1;
            else
                DPT[i][j][k] = max(max(DPT[i-1][j][k], DPT[i][j-1][k]), DPT[i][j][k-1]);
    
    
    return DPT[lenS2-1][lenS1-1][lenS3-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int>seq1(n);
    for (int i = 0; i < n; i++)
        cin >> seq1[i];
    
    cin >> n;
    vector<int>seq2(n);
    for (int i = 0; i < n; i++)
        cin >> seq2[i];
    
    cin >> n;
    vector<int>seq3(n);
    for (int i = 0; i < n; i++)
        cin >> seq3[i];

    cout << EditDistance(seq1,seq2,seq3);
    return 0;
}