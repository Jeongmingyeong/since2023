#include <iostream>
#include <array>

int main() {
    int kg = 0; /* weight of sugar */
    int result = 0; /* number of bag */
    //std::array<int, 1000> arr;
    std::cin >> kg;

    int a = kg / 5; /* maximum number of 5kg bag */

    while(true) {
        if (a < 0) {
            result = -1;
            break;
        }

        /* Calculate by reducing 5kg bags one by one */
        if((kg - (5*a)) % 3 == 0) {
            int b = (kg - (5*a)) / 3;
            result = a + b;
            break;
        }

        a--;
    }

    std::cout << result << std::endl;

}
