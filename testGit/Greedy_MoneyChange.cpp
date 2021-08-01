#include <iostream>

using namespace std;

int main(){
    int money;
    int change[3] = {10,5,1};
    cin >> money;
    int count;
    while(money != 0)
        for (int i = 0; i < 3; i++)
            if(money - change[i] >= 0){
                money -= change[i];
                count++;
                break;
            }
            
    cout << count;
    return 0;
}