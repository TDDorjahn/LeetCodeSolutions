#include <set>
#include <vector>

class Solution{

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        std::multiset<int> cache;
        
        for(const auto& num : nums1) { cache.emplace(num); }
        for(const auto& num : nums2) { cache.emplace(num); }

        std::vector<int> sorted_vec;
        sorted_vec.reserve(cache.size());

        for(const auto& key : cache) {

            sorted_vec.emplace_back(key);

        }

       if(cache.size() % 2 == 0) {

            return static_cast<double>((sorted_vec[(cache.size() - 1) / 2] + sorted_vec[cache.size() / 2]) / 2.0f);

       } else {

            return static_cast<double>(sorted_vec[cache.size() / 2]);

       }

    }

};