class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return long_method(nums, target);
    }

    int long_method(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivot = findPivot(nums);

        // If array not rotated
        if (pivot == n - 1) return binarySearch(nums, 0, n - 1, target);

        // Decide which side to search
        if (target >= nums[0] && target <= nums[pivot]) return binarySearch(nums, 0, pivot, target);
        else return binarySearch(nums, pivot + 1, n - 1, target);
    }

    int findPivot(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        // If array is not rotated
        if (nums[s] <= nums[e]) return e;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if(nums[mid] > nums[mid + 1]) return mid;
            if(nums[mid] >= nums[s]) s = mid + 1;
            else e = mid;
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }

};
