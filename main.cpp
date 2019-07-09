#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n, t, input;
    cin >> n;
    vector<long> kume;
    vector<int> results;
    for (int i = 0; i < n ; i++){
        cin >> t >> input;
        if(t == 1){
            if(!(find(kume.begin(), kume.end(), input) != kume.end()))
                kume.push_back(input);

        }else{
            int minBirSayisi = 1000000000;

            for(int j = kume.size() - 1; j>=0; j--) {
            //            for(int j = 0; j < kume.size(); j++) {

//                while(tmp > 0){
//                    if(tmp % 2 == 1){
//                        birSayisi++;
//                        tmp--;
//                    }
//                    tmp /= 2;
//                }
                int birSayisi = __builtin_popcount(input ^ kume[j]);
                if(birSayisi == 0){
                    minBirSayisi = 0;
                    break;
                }else if(birSayisi < minBirSayisi){
                    minBirSayisi = birSayisi;
//                    cout << endl << "Bir sayisi " << birSayisi << endl;
                }
            }
            results.push_back(minBirSayisi);
        }
    }
    for(int i = 0; i < results.size() ; i++){
        cout << results[i] << endl;
    }

    return 0;
}









//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <iomanip>
//
//using namespace std;
//int main(){
//
//    vector<int> vk;
//    int n,l,t,tmp;
//
//    cin >> l >> n;
//
//    for(int i = 0; i < n; i++){
//        cin >> tmp;
//        tmp = abs(tmp);
//        vk.push_back(tmp);
//    }
//    cin >> t;
//
//    double result = 1;
//    for(int i=0; i<n; i++){
//        if(vk[i] * t < l){
//            result *= (double(l - (vk[i]*t)) / double(l));
//        }else{
//            result = 0;
//            break;
//        }
//    }
////    float k = n - 1 - float(t) / float(l) * sum;
//    cout << setprecision(8);
//    cout << 1 - result << endl;
//    return 0;
//}














//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main() {
//    int arr[16] = {1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588, 18373, 52119, 147700, 422016};
//
//    int n;
//    cin >> n;
//    int a;
//    vector<int> sonuc;
//    for(int i = 0; i<n; i++){
//        cin >> a;
//        sonuc.push_back(arr[a-1]);
//    }
//
//    for(int i=0;i<n;i++){
//        cout << sonuc[i] << endl;
//    }
//
//    return 0;
//}