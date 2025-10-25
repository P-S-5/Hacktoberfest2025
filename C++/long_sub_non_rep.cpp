#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int left = 0, max_len = 0;
    for(int right = 0; right < s.size(); right++) {
        while(set.find(s[right]) != set.end()) {
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
