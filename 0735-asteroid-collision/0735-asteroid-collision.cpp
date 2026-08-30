class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        return BF(asteroids, n);
    }

    vector<int> BF(vector<int>& arr, int n) {

        vector<int> ans;
        for(int i = 0; i < n; i++) {

            // ye pata karne k liye ki curr ko ans me rakhna hai ki nhi
            bool ok = true;

            // if ans is not empty and ans.back() > 0 and arr[i] < 0 ho to
            while(!ans.empty() && ans.back() > 0 && arr[i] < 0) {

                // if incoming asteroid is bigger then prev -> pop 
                if(ans.back() < abs(arr[i])) ans.pop_back();

                else {

                    // if incoming == prev then pop and break the loop
                    if(ans.back() == abs(arr[i])) ans.pop_back();
                    ok = !ok;  // means curr ko nhi lena hai
                    break;
                }
            }

            // if ok == true then push otherwise leave it
            if(ok) ans.push_back(arr[i]);
        }

        return ans;
    }
};