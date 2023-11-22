#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1) {
    unsigned long long answer = num1;

    if (num1 == 1)
        return 0;

    for (int i = 0; i < 500; i++)
    {
        if (answer == 1)
            return i;

        if (answer % 2 == 0)
        {
            answer /= 2;

        }
        else
        {
            answer = answer * 3 + 1;
        }
    }

    return -1;
}

void main()
{
    printf("%d\n", solution(626331));
}