#include <iostream>

using namespace std;

int solution(float num1, float num2) {
    int answer = 0;

    answer = (num1 / num2) * 1000;

    return answer;
}

void main()
{
    printf("%d\n", solution(3, 2));
}