#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<pair<lli, lli>> points(n);
        vector<pair<lli, lli>> y0_points;  // Points with y = 0
        vector<pair<lli, lli>> y1_points;  // Points with y = 1
        set<pair<lli, lli>> point_set;

        // Read points and categorize them
        for (lli i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
            point_set.insert(points[i]);
            if (points[i].second == 0) {
                y0_points.push_back(points[i]);
            } else {
                y1_points.push_back(points[i]);
            }
        }

        // Sort points based on x-coordinate
        sort(points.begin(), points.end());
        sort(y0_points.begin(), y0_points.end());
        sort(y1_points.begin(), y1_points.end());

        // If there are no points with y = 0 or y = 1, no triangles can be formed
        if (y0_points.empty() || y1_points.empty()) {
            cout << "0" << endl;
            continue;
        }

        lli cnt = 0;

        // Check for right triangles with base along y = 0
        for (lli i = 1; i < y0_points.size(); ++i) {
            if (point_set.find({y0_points[i].first - 2, 0}) != point_set.end()) {
                lli r1 = y0_points[i].first - 2;
                if (((y0_points[i].first + r1) % 2 == 0) && 
                    point_set.find({(y0_points[i].first + r1) / 2, 1}) != point_set.end()) {
                    cnt++;
                }
            }
        }

        // Check for right triangles with base along y = 1
        for (lli i = 1; i < y1_points.size(); ++i) {
            if (point_set.find({y1_points[i].first - 2, 1}) != point_set.end()) {
                lli r1 = y1_points[i].first - 2;
                if (((y1_points[i].first + r1) % 2 == 0) && 
                    point_set.find({(y1_points[i].first + r1) / 2, 0}) != point_set.end()) {
                    cnt++;
                }
            }
        }

        // Check for vertical right triangles
        for (const auto& p : y0_points) {
            if (point_set.find({p.first, 1}) != point_set.end()) {
                cnt += y0_points.size() - 1 + y1_points.size() - 1;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}