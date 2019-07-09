#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;




int main(){
    int n, t;
    unsigned long input;

    cin >> n;

    set<unsigned long> kume;
    vector<int> results;

    for(int i = 0; i < n; i++){
        cin >> t >> input;
        if(t == 1){
            kume.insert(input);
        }else{
            if(kume.count(input)){
                cout << 0 << endl;
                continue;
            }
            int minBirSayisi = 65;

            for(auto itr = kume.begin(); itr != kume.end(); itr++){
                int birSayisi = __builtin_popcount(input ^ *itr);
                if(birSayisi < minBirSayisi){
                    minBirSayisi = birSayisi;
                }
            }
        cout << minBirSayisi << endl;
        }

    }

    return 0;
}