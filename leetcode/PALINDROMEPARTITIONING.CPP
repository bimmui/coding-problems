class Solution {
public:
    string construct_palindrome(string s) {
        string holder = "";
        int len = s.length();
        for (int i = len-1; i > 0; i--) {
            holder+= s[i];
        }
        return holder;
    }

    // Index 0 contains whether or not a palindrome was found
    // Indicies > 0 contains the strings, if found
    vector<string> check_palindrome(string s, int startindex) {
        vector<string> result;
        int len = s.length();
        string holder = "";
        for (int i = startindex; i < len; i++) {
            holder += s[i];
            if (holder == construct_palindrome(holder)) {
                result.push_back("Found");
                result.push_back(s);
                return result;
            }
        } 
        result.push_back("Not Found");
        return result;
    }

    vector<vector<string>> find_palindromes(string s) {
        int len = s.length();
        vector<vector<string>> final_holder;
        for (int i = 0; i < len; i++) {
            vector<string> results = check_palindrome(s, i);
            if (results[0] == "Found") {
                results.erase(results.begin());
                final_holder.push_back(results);
            }
        }
        return final_holder;
    }

    vector<vector<string>> partition(string s) {
        return find_palindromes(s);
    }
};