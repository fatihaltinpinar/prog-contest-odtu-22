#include <iostream>
#include <vector>
#include <set>
using namespace std;

int returnBeauty(const vector<int> &treeVector, int start, int duvarsayisi){
    if(start == treeVector.size())
        return 0;

    if(duvarsayisi > 0){
        duvarsayisi--;
        int cursor = start;
        int beauty = 0;
        for(int i = cursor ; i < treeVector.size(); i++){
            int newBeauty = 0;
            set<int> ass;
            for(int tmp = start; tmp <= i ; tmp++)
                ass.insert(treeVector[tmp]);
            newBeauty = static_cast<int>(ass.size() + returnBeauty(treeVector, i + 1, duvarsayisi));
            if(newBeauty > beauty)
                beauty = newBeauty;
        }
        return beauty;
    }else{
        set<int> popo;
        for(int i = start; i < treeVector.size() ; i++){
            popo.insert(treeVector[i]);
        }
        return static_cast<int>(popo.size());

    }

}


int main(){
    int n, duvarsayisi;
    int tmp;

    vector<int> treeVector;

    cin >> n >> duvarsayisi;


    for(int i = 0; i < n; i++){
        cin >> tmp;
        treeVector.push_back(tmp);
    }

    cout << returnBeauty(treeVector, 0, duvarsayisi);
    return 0;
}