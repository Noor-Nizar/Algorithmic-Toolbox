#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, vector<int>, int> primCalc(int targ)
{
    vector<int> DPT(targ + 1, 0);

    for (int num = 2; num < targ + 1; num++)
    {
        int minRoute = 2147483647;
        if (num % 2 == 0)
            minRoute = min(minRoute, DPT[num / 2] + 1);
        if (num % 3 == 0)
            minRoute = min(minRoute, DPT[num / 3] + 1);
        minRoute = min(minRoute, DPT[num - 1] + 1);

        DPT[num] = minRoute;
    }

    //now backtracking to get the numbers we pass by
    int count = 0;
    int track = DPT.size()-1;
    vector<int> comps(targ+1);
    int curr = DPT[DPT.size()-1];
    for (int i = DPT.size()-1; i > 0; i--)
    {
        if(DPT[i] + 1 == curr && (i+1 == track || i*2 == track || i*3 == track)){
            curr--;
            comps[count++] = i;
            track = i;
        }
    }
    return {DPT[DPT.size() - 1],comps, count};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int targ;
    cin >> targ;

    tuple<int, vector<int>,int> res = primCalc(targ);
    
    cout << get<0>(res) << '\n';
    for (int i = get<2>(res)-1; i >= 0; i--)
    {
        cout << get<1>(res)[i] << " ";
    }
    cout << targ;
    return 0;
}