#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//AC
int main() {
    std::string origin = "";
    std::string encode = "";
    int counts1[26] = { 0 };
    int counts2[26] = { 0 };
    int max1, max2;
    cin >> origin >> encode;
    while (origin!="") {

        for (long unsigned int i = 0; i < origin.length(); i++) {
            ++counts1[origin[i] - 65];
            ++counts2[encode[i] - 65];
        }

        max1 = counts1[0];
        max2 = counts2[0];
        for (int i = 0; i < 26; i++) {
            if (counts1[i] > max1)max1 = counts1[i];
            if (counts2[i] > max2)max2 = counts2[i];
        }
        if (max1 != max2) {
            cout << "NO" << endl;
            std::fill(counts1, counts1 + 26, 0);
            std::fill(counts2, counts2 + 26, 0);
            origin = "";
            cin >> origin >> encode;
            continue;
        }
        vector<int> freq1(max1+1, 0);
        vector<int> freq2(max2+1, 0);
        for (int i = 0; i < 26; i++) {
            freq1[counts1[i]]++;
            freq2[counts2[i]]++;
        }
        bool flag = false;
        for (int i = 0; i < max1; i++) {
            if (freq1[i] != freq2[i]) {
                flag = true;
                break;
            }
        }
        if (flag)cout << "NO" << endl;
        else cout << "YES" << endl;
        memset(counts1, 0, sizeof(counts1));
        memset(counts2, 0, sizeof(counts2));
        origin = "";
        cin >> origin >> encode;
    }
    return 0;
}