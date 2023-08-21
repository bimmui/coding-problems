#include <algorithm>
#include <vector>
// This one timed out
class Solution {
public:
    bool checkBeautiful(vector<int> arrangement) {
        bool is_beautiful = true;
        for (int i = 0; i < arrangement.size(); i++) {
            if (not((arrangement[i] % (i + 1) == 0) or ((i + 1) % arrangement[i] == 0))) {
                is_beautiful = false;
                return is_beautiful;
            }
        }
        return is_beautiful;
    }

    int countArrangement(int n) {
        vector<int> num_arr;
        int beautifularrangments = 0;
        int x = 1;

        while (x <= n) {
            num_arr.push_back(x);
            x++;
        }

        vector<vector<int>> perms;
        do {
            perms.push_back(num_arr);
        } while (next_permutation(num_arr.begin(), num_arr.end()));

        for (vector<int> vec:perms) {
            bool results = checkBeautiful(vec);
            if (results) {
                beautifularrangments++;
            }
        }

        return beautifularrangments;
    }
};

// This one worked
class Solution {
public:
    void permute(vector <int> v, int index, int &ans){
        if(index == v.size()) {
            ans++;
            return;
        }
        for(int i = index; i < v.size(); i++) {
            if(v[i] % (index+1) == 0 || (index+1) % v[i] ==  0){
                swap(v[i], v[index]);
                permute(v, index+1, ans);
                swap(v[i], v[index]);
            }
        }
    }
        
    int countArrangement(int n) {
        vector<int> v;
        int ans = 0;
        for(int i=1; i <= n; i++){
            v.push_back(i);
        }
        permute(v, 0, ans);
        return ans;
    }
};

// This one also worked, which is Approach #3 Backtracking [Accepted]
class Solution {
public:
    bool seen[16] = {};
    int res = 0;
    int countArrangement(int n, int pos = 1) {
        // This just works for every array of numbers less than 4
        if (n < 4) return n;
        // Base case, 
        if (pos > n) return res++;
        for (int i = 1; i <= n; i++) {
            if (!seen[i] && (i % pos == 0 || pos % i == 0)) {
                // marking i as seen
                seen[i] = true;
                // This works bc if you have a beautiful arrangement by the time
                // you reach the max num of characters in the array, you will 
                // call the recursie function again with +1 greater than n which
                // indicates you found a beautiful arrangement and increments the 
                // num of results
                countArrangement(n, pos + 1);
                // backtracking
                seen[i] = false;
            }
        }
        return res;
    }
};