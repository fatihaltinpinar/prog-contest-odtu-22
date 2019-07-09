#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class connection{
    int x, y;
    set<connection*> *arr;
public:
    connection(int, int, set<connection*> *);
    ~connection();
    void remove();
};

connection::connection(int in_x, int in_y, set<connection*> *in_arr) {
    x = in_x;
    y = in_y;
    set<connection*> *arr = in_arr;
    for(int i = x; i < y; i++){
        cout << x <<", " << y << endl;
        arr[i].insert(this);
        cout << x << ", " << y << endl;
    }
}

connection::~connection() {
    for(int i = x; i < y; i++){
// arr[x].erase(this);
    }
}

void connection::remove() {
    for(int i = x; i < y; i++){
// buradaki i nin yerine x yazan aklimi saskdasldasd
        cout << "Called by "<< x << "," << y << endl;
//        arr[i].erase();
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    int beauty = 0;

    map<int, int> lastOccurance;
    set<connection*> arr[n];


    for(int rcount = 0; rcount < n; rcount++){
        int tmp;
        cin >> tmp;

        auto mapLoc = lastOccurance.find(tmp);

        if(mapLoc == lastOccurance.end()) {
            lastOccurance.insert({tmp, rcount});
            beauty++;
        }else{
            connection(mapLoc->second, rcount, arr);
            mapLoc->second = rcount;
        }
    }

    m--;
    for(int i = 0; i<m; i++){
        int best_option = 0;
        unsigned long best_value = 0;

        for(int j = 0; j<n; j++){
            if(arr[j].size() > best_value){
                best_value = arr[j].size();
                best_option = j;
            }
        }

        if(best_value > 0){
            set<connection*>::iterator itr;

            for(itr = arr[best_option].begin(); itr != arr[best_option].end(); itr++){
                (*itr)->remove();
            }
            beauty += best_value;

        }

    }


    cout << beauty << endl;



    return 0;
}