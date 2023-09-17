// 최대로 날 수 있는 비율 -> 패티 : 치즈 = 2 : 1
// 즉, 만들 수 없는 경우를 확인하는 방법 -> 패티 > 2치즈 인 경우 "NO"
// 만들 수 있는 경우라면 (A - B) 개수만큼의 햄버거를 만들어야 모든 재료 소진 가능.

#include <iostream>
using namespace std;

// 햄버거 정보를 보고 형태 출력 (args : 사용될 치즈 개수)
void print_berger(int number_of_cheese) {
    cout << "a";
    for(int j = 0; j < number_of_cheese; j++) {
        cout << "ba";
    }
    cout << endl;

    return;
}

int main() {
    // A : 패티의 개수, B : 치즈의 개수
    int A = 0, B = 0;
    cin >> A >> B;

    // 패티와 치즈 모두 사용하는 방법이 있는지 확인
    if((A > (2 * B)) || (A <= B)) {
        // 모두 사용하는 방법 없음.
        cout << "NO" << endl;
        return 0;
    }

    // 방법이 있는 경우 "YES" 출력 후 방법 출력
    cout << "YES" << endl;

    // A - B 개의 햄버거 생성
    int num = A - B;

    // 만들 버거의 정보 저장
    // 기본적으로 사용되는 치즈의 개수 : B / (A - B)
    // B % (A - B) 만큼은 추가로 +1 개의 치즈 사용

    int base_cheese = B / num;
    int over_cheese = B % num;
    int temp = num - over_cheese;

    // 총 만들어야할 햄버거 개수 - 여분의 치즈를 더 사용해야하는 햄버거 개수 에 base_cheese 저장
    for(int i = 0; i < temp; i++) {
        print_berger(base_cheese);
    }

    // 나머지 햄버거에는 여분의 치즈를 추가해 저장
    for(int i = 0; i < over_cheese; i++) {
        print_berger(base_cheese + 1);
    }

    return 0;
}
