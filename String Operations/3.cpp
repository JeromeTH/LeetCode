#include <iostream>
#include <cstdio>
#include <string> 
#include <map> 
using namespace std;
map<char, int> used;// map needs explicit initialization
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, cnt = 0;// r is the first place where it repeats
        int ans= 0;
        //cout << s.length() << endl;
        for(l= 0; l < s.length(); l++){
            //cout << l << endl;
            if(l > 0){
                used[s[l - 1]]--;
                if(used[s[l - 1]] == 0) cnt--;
            }
            while(r < s.length() && used[s[r]] == 0){
                used[s[r]]++;
                cnt ++;
                r++;
            }
            cout << l << "  " << r << endl;
            ans = max(ans, r - l);
        }
        return ans;
    }
};
int main(){
    string s; 
    getline(cin, s);
    Solution solutions;
    cout << solutions.lengthOfLongestSubstring(s) << endl;
    return 0;
}