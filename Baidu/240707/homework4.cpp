#include<iostream> 
#include<vector>
#include<cstring>
using namespace std;


// 10/10
int main()
{
    int n, m;
    char cmd;
    int a, b;
    cin >> n >> m;
    int node[100000] = { 0 };
    bool is_visited[100000] = { false };
    while (m--) {
        cin >> cmd >> a >> b;
        if (cmd == 'A') {
            if (node[b] == a)
                node[b] = 0;
            node[a] = b;
        }else{
            int index = a;
            memset(is_visited, 0, sizeof(is_visited));
            is_visited[a] = true;
            while (true) {
                index = node[index];
                if (is_visited[index]) {
                    cout << "No" << endl;
                    break;
                }
                if (node[index] == b) {
                    cout << "Yes" << endl;
                    break;
                }
                is_visited[index] = true;
            }
        }
    }
    return 0;
}