#include <iostream>

int main() {
    int total = 0; /* total price on the receipt */
    int N = 0; /* number of objects */
    int result = 0; /* sum of price */
    int price = 0; /* input price */
    int num = 0; /* number of thing */

    std::cin >> total;
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> price;
        std::cin >> num;
        result += (price * num);
    }

    if(total == result) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
