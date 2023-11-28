#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(strlen(s) + 1);
    
    if (answer != NULL)//exception
    {
        strcpy_s(answer, strlen(s) + 1, s);
    }
    else
    {
        return 0;
    }
    

    
   
    for (int x = 0; x < strlen(answer); x++)
    {
        if (x != 0)
        {
            if (*(answer + x) != ' ')
                continue;
            x++;
        }

        for (int y = 0; y < strlen(answer) - x; y++)
        {
            
            if (*(answer +x + y) == ' ')break;

            if (y % 2 == 0)
            {
                *(answer + x + y) = toupper(*(answer + x + y));
            }
            else
            {
                *(answer + x + y) = tolower(*(answer + x + y));
            }
        }
    }

    return answer;
}

void main()
{
    char* rtn = solution("try hello world");
    printf("%s", rtn);
    free(rtn);
}