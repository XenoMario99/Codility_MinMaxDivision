#include "minMaxDivision.h"

#include <limits>

std::int32_t howManyElements(const std::int32_t mid, const std::vector<int>& A) {
    std::int32_t sum{0};
    std::int32_t numOfelems{1};
    for (const auto elem : A) {
        sum += elem;
        if (sum > mid) {
            numOfelems++;
            sum = elem;
        }
    }

    return numOfelems;
}

int solution(int K, int M, std::vector<int>& A) {
    std::int32_t min{0};
    std::int32_t max{0};

    for (auto elem : A) {
        max += elem;
        min = std::max(min, elem);
    }

    std::int32_t largeSum{std::numeric_limits<int>::max()};
    while (min <= max) {
        std::int32_t mid{(min + max) / 2};

        if (howManyElements(mid, A) > K) {
            min = mid + 1;
        } else {
            max = mid - 1;

            if (mid < largeSum) {
                largeSum = mid;
            }
        }
    }

    return largeSum;
}
