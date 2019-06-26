//
// Created by limo on 1/20/2019.
//

#ifndef OJ_UTILS_H
#define OJ_UTILS_H

#include <vector>
#include <climits>
#include <algorithm>

namespace algorithm {

    namespace utils {

        using namespace std;

        /*
         * @brief Count the tailing zeros at the end of n!
         *
         * COST of time/space O(n)/O(1)
         */
        template <typename T>
        T tailing_zeroes(T n) {
            auto zeros = 0;
            for (long long rem = n, factor = 5; rem > 0; factor *= 5) {
                zeros += (rem = n / factor);
            }
            return zeros;
        }

        /*
         * @brief Get the number which occurs only once in an array where the others
         * will occur exactly 2 times
         *
         * COST of time/space O(n)/O(1)
         */
        template <typename T>
        T single_number_2(vector<T> const& nums) {
            T single_num = 0;
            for (auto const& num : nums)
                single_num ^= num;
            return single_num;
        }

        /*
         * @brief Get the number which occurs only once in an array where the others
         * will occur exactly 3 times
         *
         * COST of time/space O(n)/O(1)
         *
         * @see-also https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions
         * @see-also https://en.wikipedia.org/wiki/Karnaugh_map
         */
        template <typename T>
        T single_number_3(vector<T> const& nums) {
            T one = 0, two = -1;
            for (auto const& num : nums) {
                one = (one ^ num) & two;
                two = (two ^ num) | one;
            }
            return one;
        }

        /*
         * @brief Find the maximum gap in the sorted version of an array
         * @param nums An array may not be sorted
         *
         * COST of time/space O(n)/O(n)
         * return The maximum gap
         *
         * @see-also https://leetcode.com/problems/maximum-gap/discuss/50644/Pigeon-hole-principle
         * @see-also Pigeon hole principle
         */
        template <typename T>
        T maximum_gap(vector<T> const& nums) {

            if (nums.size() < 2) return 0;

            auto const upper_bound = *max_element(nums.begin(), nums.end());
            auto const lower_bound = *min_element(nums.begin(), nums.end());

            if (upper_bound == lower_bound) return 0;

            auto const box_size = static_cast<double>(upper_bound-lower_bound) / (nums.size()-1);

            vector<pair<int, int>> boxes(nums.size(), make_pair(INT_MAX, INT_MIN));
            for (auto num : nums) {
                auto& box = boxes[static_cast<size_t>((num - lower_bound) / box_size)];
                box.first = min(box.first, num);
                box.second = max(box.second, num);
            }

            auto max_gap = 0;
            for (auto pre = boxes.front().second, i = 1; i < boxes.size(); ++i) {
                if (boxes[i].first == INT_MAX) continue;
                max_gap = max(max_gap, boxes[i].first-pre);
                pre = boxes[i].second;
            }
            return max_gap;
        }

    }

}

#endif //OJ_UTILS_H
