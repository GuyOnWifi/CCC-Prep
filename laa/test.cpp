#include <iostream>
#include <cstring> // for memset

int main() {
    int water[50][50];

    // Set all elements to -1 using memset
    memset(water, -1, sizeof(water));

    // Optionally, print the array to verify
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            std::cout << water[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
