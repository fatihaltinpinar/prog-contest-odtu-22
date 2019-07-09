#include <iostream>
#include <algorithm>

using namespace std;

//int count_set_bits(long N)
//{
//    int result = 0;
//    while(N)
//    {
//        result++;
//        N &=N-1;
//    }
//    return result;
//}


// Function which counts set bits from 0 to n
int countSetBits(int n)
{
    int i = 0;

    // ans store sum of set bits from 0 to n
    int ans = 0;

    // while n greater than equal to 2^i
    while ((1 << i) <= n) {

        // This k will get flipped after
        // 2^i iterations
        bool k = 0;

        // change is iterator from 2^i to 1
        int change = 1 << i;

        // This will loop from 0 to n for
        // every bit position
        for (int j = 0; j <= n; j++) {

            ans += k;

            if (change == 1) {
                k = !k; // When change = 1 flip the bit
                change = 1 << i; // again set change to 2^i
            }
            else {
                change--;
            }
        }

        // increment the position
        i++;
    }

    return ans;
}


int main(){
    int tmp;
    while (true) {
        cin >> tmp;
        cout << countSetBits(tmp);
    }


    return 0;
}