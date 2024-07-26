#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

//AC
int main() {
    int n, res = 0;
    string s;
    cout<<"cin:";
    cin >> n;
    map<string, int> mp;
    while (n--) {
        cin >> s;
        sort(s.begin(), s.end());
        if (mp.find(s)==mp.end()) {
            res++;
            mp[s] = 1;
        }
    }
    cout << res;
    return 0;
}