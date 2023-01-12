#include <iostream>
#include <cctype>
#include <string>
#include <array>

int main() {
    std::string S = ""; /* input string */

    std::getline(std::cin, S);

    char arr[S.length()]; /* store upper case */
    int index = 0;
    for(unsigned long i = 0; i < S.length(); i++) {
        if(isupper(S.at(i))) {
            if(S.at(i) == 'U' || S.at(i) == 'C' || S.at(i) == 'P') {
                arr[index] = S.at(i);
                index++;
            }
        }
    }

    /* check exist "UCPC" in array */
    int a = 0;
    for(unsigned long i = 0; i < index; i++) {
        if(arr[i] == 'U' && a == 0) {
            a++;
        } else if (arr[i] == 'C' && a == 1) {
            a++;
        } else if (arr[i] == 'P' && a == 2) {
            a++;
        } else if (arr[i] == 'C' && a == 3) {
            a++;
            break;
        }
    }    

    /* print output */
    if(a == 4) {
        std::cout << "I love UCPC" << std::endl;
    } else {
        std::cout << "I hate UCPC" << std::endl;
    }

    return 0;


}