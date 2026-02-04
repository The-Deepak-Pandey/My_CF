#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N, K;
        cin >> N >> K;
        vector<ll> C(N+2, 0);
        for(int i = 1; i <= N; i++){
            cin >> C[i];
        }
        string A;
        cin >> A;

        // Count how many 0‐sales and 1‐sales
        int Z = 0, O = 0;
        for(char c: A)
            if(c=='0') ++Z; else ++O;

        // 1) bestL[d] = best sum of Z picks from C[1..d-1], or -1 if d-1 < Z
        vector<ll> bestL(N+2, -1);
        {
            priority_queue<ll, vector<ll>, greater<ll>> minH;
            ll sum = 0;
            for(int i = 1; i <= N; i++){
                // consider adding C[i] into our running pool of up to Z best picks
                if((int)minH.size() < Z){
                    minH.push(C[i]);
                    sum += C[i];
                } else if(Z>0 && C[i] > minH.top()){
                    sum -= minH.top();
                    minH.pop();
                    minH.push(C[i]);
                    sum += C[i];
                }
                // now minH holds the best Z out of [1..i]
                // so for helper d=i+1, bestL[d] = sum
                if((int)minH.size() == Z){
                    bestL[i+1] = sum;
                }
            }
            // edge‐case Z=0 ⇒ sum=0 for all d
            if(Z==0) {
                for(int d=1; d<=N+1; d++)
                    bestL[d] = 0;
            }
        }

        // 2) bestR[d] = best sum of O picks from C[d+1..N], or -1 if N-d < O
        vector<ll> bestR(N+2, -1);
        {
            priority_queue<ll, vector<ll>, greater<ll>> minH;
            ll sum = 0;
            for(int i = N; i >= 1; i--){
                if((int)minH.size() < O){
                    minH.push(C[i]);
                    sum += C[i];
                } else if(O>0 && C[i] > minH.top()){
                    sum -= minH.top();
                    minH.pop();
                    minH.push(C[i]);
                    sum += C[i];
                }
                // for helper d=i-1, bestR[d] = sum
                if((int)minH.size() == O){
                    bestR[i-1] = sum;
                }
            }
            if(O==0){
                for(int d=0; d<=N; d++)
                    bestR[d] = 0;
            }
        }

        // 3) Try all helper positions d in [Z+1 .. N-O]
        ll ans = 0;
        for(int d = Z+1; d <= N - O; d++){
            if(bestL[d] >= 0 && bestR[d] >= 0){
                ans = max(ans, (bestL[d] + bestR[d]) % MOD);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
