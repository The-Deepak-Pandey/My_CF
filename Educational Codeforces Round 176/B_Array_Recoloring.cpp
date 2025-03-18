#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solve(vector<int>& a, int n, int k) {

    if (k == n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        return sum;
    }
    

    int max_cost = 0;
    

    vector<bool> combination(n, false);
    fill(combination.end() - k, combination.end(), true);
    
    while (true) {

        vector<bool> is_blue(n, false);
        vector<int> initial_elements;
        
        for (int i = 0; i < n; i++) {
            if (combination[i]) {
                is_blue[i] = true;
                initial_elements.push_back(a[i]);
            }
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (is_blue[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        vector<int> painted_order;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : {current - 1, current + 1}) {
                if (neighbor >= 0 && neighbor < n && !is_blue[neighbor] && !visited[neighbor]) {
                    is_blue[neighbor] = true;
                    visited[neighbor] = true;
                    painted_order.push_back(a[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        
        int cost = 0;
        for (int val : initial_elements) {
            cost += val;
        }
        
        if (!painted_order.empty()) {
            cost += painted_order.back();
        }
        
        max_cost = max(max_cost, cost);
        
        if (!next_permutation(combination.begin(), combination.end())) {
            break;
        }
    }
    return max_cost;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << solve(a, n, k) << endl;
    }
    
    return 0;
}