#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-magic-numbers"
//
// Created by limo on 1/20/2019.
//

#ifndef OJ_UTILS_H
#define OJ_UTILS_H

#include <vector>
#include <climits>
#include <algorithm>
#include <cstdint>

namespace algorithm {

    namespace utils {

        using namespace std;

        constexpr int FIVE = 5;

        /*
         * @brief Count the tailing zeros at the end of n!
         *
         * COST of time/space O(n)/O(1)
         */
        template<typename T>
        T tailing_zeroes(T n) {
            auto zeros = 0;
            for (long long rem = n, factor = FIVE; rem > 0; factor *= FIVE) {
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
        template<typename T>
        T single_number_2(vector<T> const &nums) {
            T single_num = 0;
            for (auto const &num : nums)
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
        template<typename T>
        T single_number_3(vector<T> const &nums) {
            T one = 0, two = -1;
            for (auto const &num : nums) {
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
        template<typename T>
        T maximum_gap(vector<T> const &nums) {

            if (nums.size() < 2) return 0;

            auto const upper_bound = *max_element(nums.begin(), nums.end());
            auto const lower_bound = *min_element(nums.begin(), nums.end());

            if (upper_bound == lower_bound) return 0;

            auto const box_size = static_cast<double>(upper_bound - lower_bound) / (nums.size() - 1);

            vector<pair<int, int>> boxes(nums.size(), make_pair(INT_MAX, INT_MIN));
            for (auto num : nums) {
                auto &box = boxes[static_cast<size_t>((num - lower_bound) / box_size)];
                box.first = min(box.first, num);
                box.second = max(box.second, num);
            }

            auto max_gap = 0;
            for (auto pre = boxes.front().second, i = 1; i < boxes.size(); ++i) {
                if (boxes[i].first == INT_MAX) continue;
                max_gap = max(max_gap, boxes[i].first - pre);
                pre = boxes[i].second;
            }
            return max_gap;
        }

        /*
         * @brief There are several useful functions to count bit 1 in a given binary num
         */
        namespace bit_count {
            //types and constants used in the functions below
            //uint64_t is an unsigned 64-bit integer variable type (defined in C99 version of C language)
            const uint64_t m1 = 0x5555555555555555;   //binary: 0101...
            const uint64_t m2 = 0x3333333333333333;   //binary: 00110011..
            const uint64_t m4 = 0x0f0f0f0f0f0f0f0f;   //binary:  4 zeros,  4 ones ...
            const uint64_t m8 = 0x00ff00ff00ff00ff;   //binary:  8 zeros,  8 ones ...
            const uint64_t m16 = 0x0000ffff0000ffff;  //binary: 16 zeros, 16 ones ...
            const uint64_t m32 = 0x00000000ffffffff;  //binary: 32 zeros, 32 ones
            const uint64_t h01 = 0x0101010101010101;  //the sum of 256 to the power of 0,1,2,3...

            //This is a naive implementation, shown for comparison,
            //and to help in understanding the better functions.
            //This algorithm uses 24 arithmetic operations (shift, add, and).
            int pop_count64a(uint64_t x) {
                x = (x & m1) + ((x >> 1) & m1);     //put count of each  2 bits into those  2 bits
                x = (x & m2) + ((x >> 2) & m2);     //put count of each  4 bits into those  4 bits
                x = (x & m4) + ((x >> 4) & m4);     //put count of each  8 bits into those  8 bits
                x = (x & m8) + ((x >> 8) & m8);     //put count of each 16 bits into those 16 bits
                x = (x & m16) + ((x >> 16) & m16);  //put count of each 32 bits into those 32 bits
                x = (x & m32) + ((x >> 32) & m32);  //put count of each 64 bits into those 64 bits
                return x;
            }

            //This uses fewer arithmetic operations than any other known
            //implementation on machines with slow multiplication.
            //This algorithm uses 17 arithmetic operations.
            int pop_count64b(uint64_t x) {
                x -= (x >> 1) & m1;              //put count of each 2 bits into those 2 bits
                x = (x & m2) + ((x >> 2) & m2);  //put count of each 4 bits into those 4 bits
                x = (x + (x >> 4)) & m4;         //put count of each 8 bits into those 8 bits
                x += x >> 8;    //put count of each 16 bits into their lowest 8 bits
                x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
                x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
                return x & 0x7f;
            }

            //This uses fewer arithmetic operations than any other known
            //implementation on machines with fast multiplication.
            //This algorithm uses 12 arithmetic operations, one of which is a multiply.
            int pop_count64c(uint64_t x) {
                x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
                x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits
                x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits
                return (x * h01) >> 56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
            }

            //This is better when most bits in x are 0
            //This is algorithm works the same for all data sizes.
            //This algorithm uses 3 arithmetic operations and 1 comparison/branch per "1" bit in x.
            int pop_count64d(uint64_t x) {
                int count;
                for (count=0; x; count++)
                    x &= x - 1;
                return count;
            }
        }

    }

}

#endif //OJ_UTILS_H

#pragma clang diagnostic pop