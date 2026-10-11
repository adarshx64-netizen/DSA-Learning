class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for(auto c : s) {
            if(c == '#') {
                if(s1.empty()) continue;
                s1.pop();
            }

            else {
                s1.push(c);
            }
        }

        for(auto c : t) {
            if(c == '#') {
                if(s2.empty()) continue;
                s2.pop();
            }
            
            else {
                s2.push(c);
            }
        }

        while(!s1.empty() && !s2.empty()) {
            if(s1.top() != s2.top()) return false;
            s1.pop();
            s2.pop();
        }

        if(!s1.empty() || !s2.empty()) return false;

        return true;
    }
};