#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char* solution(int month, int day) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(4);
    int frontYear = 20;
    int lastYear = 16;//16년도 고정
    int num = 0;

    //첼러 공식
    num = day + ((month + 1) * 26 / 10) + lastYear + (lastYear + frontYear) / 4 - (2 * frontYear);

    switch (num % 7)
    {
    case 0:
        strcpy_s(answer, 4, "SAT");
        break;
    case 1:
        strcpy_s(answer, 4, "SUN");
        break;
    case 2:
        strcpy_s(answer, 4, "MON");
        break;
    case 3:
        strcpy_s(answer, 4, "TUE");
        break;
    case 4:
        strcpy_s(answer, 4, "WED");
        break;
    case 5:
        strcpy_s(answer, 4, "THU");
        break;
    case 6:
        strcpy_s(answer, 4, "FRI");
        break;
    }

    return answer;
}

void main()
{
    char* result = solution(12, 5);
    printf("%s\n", result);
    free(result);
    //12월 5일은 월요일
    //5월 24일은 화요일
    return;
}