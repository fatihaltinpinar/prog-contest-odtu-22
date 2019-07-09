#include <iostream>
#include <map>
#include <set>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int beauty = 0;

    map<int, int> lastOccurance;
    set<pair<int, int>> arr[n];

    for (int entry_number = 0; entry_number < n; entry_number++) {
        int entry;
        cin >> entry;

        auto mapLoc = lastOccurance.find(entry);

        if (mapLoc == lastOccurance.end()) {
            lastOccurance.insert({entry, entry_number});
            beauty++;
        } else {
            for(int i = mapLoc->second; i < entry_number; i++)
                arr[i].insert({mapLoc->second, entry_number});
            mapLoc->second = entry_number;
        }
    }

    m--;
    for (int i = 0; i < m; i++) {
        int maxLoc = -1;
        int maxValue = 0;
        for(int j = 0; j < n; j++) {
            if (arr[j].size() > maxValue) {
                maxValue = arr[j].size();
                maxLoc = j;
            }
        }
        beauty += maxValue;
        if (maxLoc >= 0){

            for (int j = 0; j < arr[maxLoc].size(); j++){
                auto itr = arr[maxLoc].begin();
                for (itr; itr != arr[maxLoc].end(); itr++){
                    for (int x = itr->first ; x < itr->second; x++){
                        arr[x].erase(*itr);
                    }
                }
            }
        }
    }

    cout << beauty;
    return 0;
}