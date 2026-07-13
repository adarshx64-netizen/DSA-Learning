class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;

        for (int len = 2; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {

                int num = stoi(s.substr(i, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     void func(vector<int>& v) {
//         string s = "123456789";
//         for (int i = 0; i <= 9; i++) {
//             for (int len = 1; i + len <= 9; len++) {
//                 string temp = s.substr(i, len);
//                 v.push_back(stoi(temp));
//             }
//         }
//         sort(v.begin(), v.end());
//     }

//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> v;
//         func(v);

//         vector<int> ans;
//         for(int i = 0; i < v.size(); i++) {
//             int x = v[i];
//             if(x >= low && x <= high) {
//                 ans.push_back(x);
//             }
//         }
//         return ans;
//     }
// };