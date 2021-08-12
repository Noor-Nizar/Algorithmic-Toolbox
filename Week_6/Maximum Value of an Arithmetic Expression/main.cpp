#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


long long maxVal(string seq){
    int n = seq.size();
    int digs = (1+n)/2;

    vector<long long> nums(digs);
    for (int i = 0; i < digs; i++){
        nums[i] = seq[i*2] - '0';
    }
    
    vector<vector<long long>> maT(digs,vector<long long>(digs));
    vector<vector<long long>> miT(digs,vector<long long>(digs));
    for (int s = 0; s <= digs; s++)
    {
        for (int i = 0; i < digs-s; i++)
        {
            if(s == 0){
                maT[i][i] = nums[i];
                miT[i][i] = nums[i];
                continue;
            }
            long long minv = 2147483646;
            long long maxv = -2147483646;
            int j = i + s;
            for (int k = i; k < j; k++)
            {
                long long a,b,c,d;
                if(seq[((k+1)*2)-1] == '-'){
                    a = maT[i][k] - maT[k+1][j];
                    b = maT[i][k] - miT[k+1][j];
                    c = miT[i][k] - maT[k+1][j];
                    d = miT[i][k] - miT[k+1][j];
                }else if(seq[((k+1)*2)-1] == '+'){
                    a = maT[i][k] + maT[k+1][j];
                    b = maT[i][k] + miT[k+1][j];
                    c = miT[i][k] + maT[k+1][j];
                    d = miT[i][k] + miT[k+1][j];
                }else {
                    a = maT[i][k] * maT[k+1][j];
                    b = maT[i][k] * miT[k+1][j];
                    c = miT[i][k] * maT[k+1][j];
                    d = miT[i][k] * miT[k+1][j];
                }
                minv = min(min(min(min(minv,a),b),c),d);
                maxv = max(max(max(max(maxv,a),b),c),d);
            }
            miT[i][j] = minv;
            maT[i][j] = maxv;
        }
    }

    return maT[0][digs-1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string in;
    cin >> in;

    cout << maxVal(in);
    return 0;
}