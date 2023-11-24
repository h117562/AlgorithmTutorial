#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1) {
    
    for (int answer = 1; answer < 1000000; answer++)
    {
        if ((num1 % answer) == 1)
        {
            return answer;
        }
    }

    return 0;
}

void main()
{
    printf("%d\n", solution(10));
}