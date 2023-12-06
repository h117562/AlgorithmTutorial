#include <iostream>

using namespace std;

bool solution(int num) {
    bool answer = true;
    int temp = num;
    int sum = 0;

    if (num > 10000) return false;

    for (int i = 10000; i >= 1; i /= 10)
    {
        sum += temp / i;
        temp = temp % i;
    }

    if (num % sum != 0)
    {
        return false;
    }

    return answer;
}

void main()
{
    cout << solution(18) << endl;
}