#include <iostream>

bool is_power_of_two(int n) {
    if (n == 1) return true;
    else if (n % 2 == 0 && n != 0)
        return is_power_of_two(n / 2);
    else
        return false;
}

int main() {
    int x;
    std::cin>>x;
    std::cout << is_power_of_two(x) << std::endl; 
}