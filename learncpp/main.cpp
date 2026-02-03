#include <iostream>
#include <limits>

void doNothing(int &) {}

int main() {
    int x{};
    int y{4}, z{2};

    // std::cin >> x >> y >> z;
    x = 5;

    std::cout << x + y + z << '\n';

    doNothing(x);

    std::cout << "Here is the size of an Int:\n";
    std::cout << sizeof(int) << "\n";



    return 0;
}
