#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n, m;
        cin >> n >> m;
        int totalPerimeter = 4 * m * n;
    
        vector<pair<int, int>> steps(n);
 
        for(int i = 0; i < n; i++) {
            cin >> steps[i].first >> steps[i].second;
        }

        for(int i = 1; i<n; i++){
            totalPerimeter-=2*(m-steps[i].first+m-steps[i].second);
        }

        
        cout << totalPerimeter << endl;
    }

    return 0;
}