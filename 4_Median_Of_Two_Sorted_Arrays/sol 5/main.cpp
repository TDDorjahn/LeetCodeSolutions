#include <vector>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0, right = m; const int half = (m + n + 1) / 2;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums1[mid] < nums2[half - mid - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        int i = left;
        int j = half - i;
        
        int nums1_left = (i > 0) ? nums1[i - 1] : INT_MIN;
        int nums1_right = (i < m) ? nums1[i] : INT_MAX;
        int nums2_left = (j > 0) ? nums2[j - 1] : INT_MIN;
        int nums2_right = (j < n) ? nums2[j] : INT_MAX;
        
        if ((m + n) % 2 == 1) {
            return std::max(nums1_left, nums2_left);
        }
        
        return (std::max(nums1_left, nums2_left) + std::min(nums1_right, nums2_right)) / 2.0f;
    }
};