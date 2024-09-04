#include <iostream>
#include <cmath>
#include <algorithm>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, z;
        long long k;
        cin >> x >> y >> z >> k;
        
        long long maxPlacements = 0;
        
        for (int a = 1; a <= cbrt(k); ++a) {
            if (k % a == 0) {
                long long ab = k / a;
                for (int b = 1; b <= sqrt(ab); ++b) {
                    if (ab % b == 0) {
                        int c = ab / b;
                        if (a <= x && b <= y && c <= z) {
                            maxPlacements = max(maxPlacements, (long long)(x - a + 1) * (y - b + 1) * (z - c + 1));
                        }
                        if (a <= x && c <= y && b <= z) {
                            maxPlacements = max(maxPlacements, (long long)(x - a + 1) * (y - c + 1) * (z - b + 1));
                        }
                        if (b <= x && a <= y && c <= z) {
                            maxPlacements = max(maxPlacements, (long long)(x - b + 1) * (y - a + 1) * (z - c + 1));
                        }
                        if (b <= x && c <= y && a <= z) {
                            maxPlacements = max(maxPlacements, (long long)(x - b + 1) * (y - c + 1) * (z - a + 1));
                        }
                        if (c <= x && a <= y && b <= z) {
                            maxPlacements = max(maxPlacements, (long long)(x - c + 1) * (y - a + 1) * (z - b + 1));
                        }
                        if (c <= x && b <= y && a <= z) {
                            maxPlacements = max(maxPlacements, (long long)(x - c + 1) * (y - b + 1) * (z - a + 1));
                        }
                    }
                }
            }
        }
        
        cout << maxPlacements << '\n';
    }
    int lala;
    return (lala ^ lala);
}
