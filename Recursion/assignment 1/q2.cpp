#include <iostream>

int steps(int start, int n) {
    if (start == n) return 1;
    if (start > n) return 0;
    return steps(start + 1, n) + steps(start + 2, n) + steps(start + 3, n);
}

int main() {
    int n = 7;
    int start = 0;
    int num_ways = steps(start, n);
    std::cout << "There are " << num_ways << " ways to reach the target " << n << " from the start position " << start << ".\n";
    return 0;
}