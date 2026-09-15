#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "? 1 2" << endl;
    long long int x1;
    cin >> x1;
    
    cout << "? 2 3" << endl;
    long long int x2;
    cin >> x2;
    
    cout << "? 4 5" << endl;
    long long int x3;
    cin >> x3;
    
    cout << "? 5 6" << endl;
    long long int x4;
    cin >> x4;
    vector<int> a = {4, 8, 15, 16, 23, 42};
    do {
        if (a[0] * a[1] == x1 && 
            a[1] * a[2] == x2 && 
            a[3] * a[4] == x3 && 
            a[4] * a[5] == x4) {
            break;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << "! ";
    for (int i = 0; i < 6; i++) {
        cout << a[i] << (i == 5 ? "" : " ");
    }
    cout << endl;
    
    return 0;
}