#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int num1) {
    int answer = num1;
    int ary[20];

    int i = 0;
    while (answer > 1)
    {  
        ary[i] =answer % 3;
        answer /= 3;

        i++;
    }

    ary[i] = answer;
    answer = 0;
 

    for (int j = 0; j <= i; j++)
    {
        answer += ary[j] * pow(3, i - j);
    }

    
    return answer;
}

void main()
{
    int num = 100000000;
    printf("%d, %d\n", num, solution(num));
}