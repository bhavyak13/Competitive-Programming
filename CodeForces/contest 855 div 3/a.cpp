    #include <bits/stdc++.h>
     
    using i64 = long long;
     
    void solve() {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        
        int j = 0;
        for (int i = 0; i < 4; i++) {
            char lo = "meow"[i];
            char up = "MEOW"[i];
            if (j == n || (s[j] != lo && s[j] != up)) {
                std::cout << "NO\n";
                return;
            }
            while (j < n && (s[j] == lo || s[j] == up)) {
                j++;
            }
        }
        if (j == n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
     
    int main() {
        // std::ios::sync_with_stdio(false);
        // std::cin.tie(nullptr);
        
        int t;
        std::cin >> t;
        
        while (t--) {
            solve();
        }
        
        return 0;
    }