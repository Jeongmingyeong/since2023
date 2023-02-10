#include <iostream>

int N; /* number of times recursion */

void Bar(int x) {
    for(int i = 0; i < N-x; i++) {
        std::cout << "____";
    }
}

void Print(int x) {
    Bar(x);
    std::cout << "\"����Լ��� ������?\"\n";
    if(!x) {
        Bar(x);
        std::cout<<"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        Bar(x);
        std::cout<<"��� �亯�Ͽ���.\n";
        return;
    }
    Bar(x);
    std::cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    Bar(x);
    std::cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    Bar(x);
    std::cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    Print(x-1);
    Bar(x);
    std::cout << "��� �亯�Ͽ���.\n";
}


int main() {
    std::cin >> N;
    std::cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    Print(N);
}
