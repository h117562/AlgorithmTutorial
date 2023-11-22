#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
 
    if (num1 == num2)
        return 1;

    return -1;
}

void main()
{
    printf("%d\n", solution(11, 11));
}