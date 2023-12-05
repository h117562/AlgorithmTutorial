#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;
    int near = 0;
    int temp = temperature;
  
    near = abs(temp - t1) < abs(temp - t2) ? t1 : t2;//t1, t2 중 근사값 찾기

    for (int i = 0; i < onboard.size(); i++)
    {
        if (onboard[i] == 1)//에어컨이 켜있을 때,
        {

            if (temp == near)
            {
                answer += b;//실내, 희망 온도가 같을 경우 b전력을 소비하여 유지

                continue;//이후 연산 무시하고 건너뛰기
            }
           
            temp < near ? temp++ : temp--;//실내 온도가 희망 온도와 다를 경우 a전력 소비하여 희망 온도와 가까워짐
            answer += a;
        }
        else//에어컨 껏을 때,
        {
           
            if (temp == temperature)//실내, 실외 온도가 다를 경우 1씩 실외 온도와 가까워짐
            {
                temp < temperature ? temp++ : temp--;
            }
        }
        
        
    }

    return answer;
}

void print(int temperature, int t1, int t2, int a, int b, vector<int> onboard, int result)
{
    cout.width(11);
    cout << temperature << " ";

    cout.width(3);
    cout << t1 << " ";

    cout.width(3);
    cout << t2 << " ";

    cout.width(3);
    cout << a << " ";

    cout.width(3);
    cout << b << " ";

    cout.width(6);
    cout << result << "     ";
    
    cout << "[";
    for (int i = 0; i < onboard.size(); i++)
    {
        cout << onboard[i] << ", ";
    }
    cout << "]" << endl;


}

void main()
{
    vector<int> list;
    int temp, t1, t2, a, b, answer;
    
   
    cout << "temperature  t1  t2   a   b result  onboard" << endl;

    list = { 0 ,0 ,1 ,1 ,1 ,1 ,1 };
    temp = 28; t1 = 18; t2 = 26; a = 10; b = 8; 
    answer = solution(temp, t1, t2, a, b, list);
    print(temp, t1, t2, a, b, list, answer);

    list = { 0 ,0 ,0 ,0 ,0 ,1 ,0 };
    temp = -10; t1 = -5; t2 = 5; a = 5; b = 1;
    answer = solution(temp, t1, t2, a, b, list);
    print(temp, t1, t2, a, b, list, answer);


}