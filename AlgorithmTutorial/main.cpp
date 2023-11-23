#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1)
{
    int answer = 0;
    int tmp = num1;

    for (int i = 100000000; i > 0; i /= 10)
    {
        answer += tmp / i;
        tmp = num1 % i;
    }
        

    return answer;
}

void main()
{
    printf("%d\n", solution(987));
}