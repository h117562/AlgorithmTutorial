#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

};

enum Direction//m_compare 알아보기 쉽게
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};


//가장 턴수가 적게 드는 경우 탐색
int solution(vector<vector<int>>& m_beforeboard, Point& m_first, Point m_last, int m_level) 
{
    int answer = m_level;//진행된 턴 수
    vector<vector<int>> m_newboard;
    Point m_nextposition = m_first;
    int m_compare[4] = {0,0,0,0};
    m_newboard = m_beforeboard;//보드판 복사
    m_newboard[m_first.y][m_first.x] = 0;//원래 있던 자리는 0으로 만들고 이동하고 다음 패턴 예측
    answer++;
    
    
    if (m_first.x == m_last.x && m_first.y == m_last.y)//패배 확정일 경우 쓸데없는 연산 무시하고 0리턴
    {
        return 0;
    }
   
        if (0 <= m_first.y - 1)//위쪽으로 이동했을 경우 턴 예측
        {
            if (m_newboard[m_first.y - 1][m_first.x] != 0)
            {
                m_nextposition = Point(m_first.x, m_first.y - 1);
                m_compare[UP] = solution(m_newboard, m_last, m_nextposition, answer);
            }
            
        }

        if (m_newboard.size() > m_first.y + 1)//아래쪽으로 이동했을 경우 턴 예측
        {
            if (m_newboard[m_first.y + 1][m_first.x] != 0)
            {
                m_nextposition = Point(m_first.x, m_first.y + 1);
                m_compare[DOWN] = solution(m_newboard, m_last, m_nextposition, answer);
            }
              
        }
    
        if (0 <= m_first.x - 1)//왼쪽으로 이동했을 경우 턴 예측
        {
            if (m_newboard[m_first.y][m_first.x - 1] != 0)
            {
                m_nextposition = Point(m_first.x - 1, m_first.y);
                m_compare[LEFT] = solution(m_newboard, m_last, m_nextposition, answer);
            }
        }
 
        if (m_newboard[0].size() > m_first.x + 1)//오른쪽으로 이동했을 경우 턴 예측
        {
            if (m_newboard[m_first.y][m_first.x + 1] != 0)
            {
                m_nextposition = Point(m_first.x + 1, m_first.y);
                m_compare[RIGHT] = solution(m_newboard, m_last, m_nextposition, answer);
            }
        }

        int min = INT_MAX;

        for (int obj : m_compare)
        {
            if (obj < min && obj != 0)
                min = obj;
        }

        if (answer == 1)//최상위 노드일 경우
        {
            int m_direction = 5;

            for (int i = 0; i < 4; i++)//어느 방향으로 이동해야 하는지 찾기
            {
                if (m_compare[i]==min)
                {
                    m_direction = i;
                }
            }

            m_beforeboard[m_first.y][m_first.x] = 0;//이전 위치는 0으로 만들고 이동

            switch (m_direction)//이동
            {
            case UP:
                m_nextposition = Point(m_first.x, m_first.y - 1);
                m_first = m_nextposition;
                break;
            case DOWN:
                 m_nextposition = Point(m_first.x, m_first.y + 1);
                 m_first = m_nextposition;
                break;
            case LEFT:
                 m_nextposition = Point(m_first.x - 1, m_first.y);
                 m_first = m_nextposition;
                break;
            case RIGHT:
                 m_nextposition = Point(m_first.x + 1, m_first.y);
                 m_first = m_nextposition;
                break;
            default:
                cout << "이동할 곳이 없습니다." << endl;
                return 0; 
                break;
            }
        }

        if (min != INT_MAX)
            answer = min;//가장 작은 턴수를 리턴

        m_newboard.clear();
        vector<vector<int>>().swap(m_newboard);

    return answer;
}

int solution2(vector<vector<int>>& m_beforeboard, Point& m_first, Point m_last, int m_level)
{
    int answer = m_level;//진행된 턴 수
    vector<vector<int>> m_newboard;
    Point m_nextposition = m_first;
    int m_compare[4] = { 0,0,0,0 };
    m_newboard = m_beforeboard;//보드판 복사
    m_newboard[m_first.y][m_first.x] = 0;//원래 있던 자리는 0으로 만들고 이동하고 다음 패턴 예측
    answer++;

    if (m_first.x == m_last.x && m_first.y == m_last.y)//패배 확정일 경우 쓸데없는 연산 무시하고 0리턴
    {
        return 0;
    }

    if (0 <= m_first.y - 1)//위쪽으로 이동했을 경우 턴 예측
    {
        if (m_newboard[m_first.y - 1][m_first.x] != 0)
        {
            m_nextposition = Point(m_first.x, m_first.y - 1);
            m_compare[UP] = solution2(m_newboard, m_last, m_nextposition, answer);
        }

    }

    if (m_newboard.size() > m_first.y + 1)//아래쪽으로 이동했을 경우 턴 예측
    {
        if (m_newboard[m_first.y + 1][m_first.x] != 0)
        {
            m_nextposition = Point(m_first.x, m_first.y + 1);
            m_compare[DOWN] = solution2(m_newboard, m_last, m_nextposition, answer);
        }

    }

    if (0 <= m_first.x - 1)//왼쪽으로 이동했을 경우 턴 예측
    {
        if (m_newboard[m_first.y][m_first.x - 1] != 0)
        {
            m_nextposition = Point(m_first.x - 1, m_first.y);
            m_compare[LEFT] = solution2(m_newboard, m_last, m_nextposition, answer);
        }
    }

    if (m_newboard[0].size() > m_first.x + 1)//오른쪽으로 이동했을 경우 턴 예측
    {
        if (m_newboard[m_first.y][m_first.x + 1] != 0)
        {
            m_nextposition = Point(m_first.x + 1, m_first.y);
            m_compare[RIGHT] = solution2(m_newboard, m_last, m_nextposition, answer);
        }
    }

    int max = 0;

    for (int obj : m_compare)
    {
        if (obj > max)
            max = obj;
    }

    if (answer == 1)//최상위 노드일 경우
    {
        int m_direction;

        for (int i = 0; i < 4; i++)//어느 방향으로 이동해야 하는지 찾기
        {
            if (m_compare[i] == max)
            {
                m_direction = i;
            }

            if (max == 0)//이동할 곳이 없으면
                m_direction = 5; //default로
        }

        m_beforeboard[m_first.y][m_first.x] = 0;//이전 위치는 0으로 만들고 이동

        switch (m_direction)//이동
        {
        case UP:
            m_nextposition = Point(m_first.x, m_first.y - 1);
            m_first = m_nextposition;
            break;
        case DOWN:
            m_nextposition = Point(m_first.x, m_first.y + 1);
            m_first = m_nextposition;
            break;
        case LEFT:
            m_nextposition = Point(m_first.x - 1, m_first.y);
            m_first = m_nextposition;
            break;
        case RIGHT:
            m_nextposition = Point(m_first.x + 1, m_first.y);
            m_first = m_nextposition;
            break;
        default:
            cout << "이동할 곳이 없습니다." << endl;
            break;
        }


    }

    if (max != 0)
        answer = max;//가장 작은 턴수를 리턴

    m_newboard.clear();
    vector<vector<int>>().swap(m_newboard);

    return answer;
}

void ShowBoard(vector<vector<int>> m_board, Point m_player1, Point m_player2)
{
    
    for (int i = 0; i < m_board.size(); i++)
    {
        for (int j = 0; j < m_board[0].size(); j++)
        {
            cout.width(2);
            if (m_player1.x == j && m_player1.y == i)
            {
                cout << "■";
            }else if (m_player2.x == j && m_player2.y == i)
            {
                cout << "□";
            }
            else
            {
                cout << m_board[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}


//대각선 이동 불가능
//땅따먹기 일종의 게임
void main()
{
    vector<vector<int>> m_board;//보드 원본
    Point m_player1(0, 2), m_player2(4, 2);//두 플레이어의 초기 위치
    
    m_board = { {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} }; //5x5 보드

    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution(m_board, m_player1, m_player2, 0);//가장 적게 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
    solution2(m_board, m_player2, m_player1, 0);//가장 오래 걸리는 턴만 계산
    ShowBoard(m_board, m_player1, m_player2);//보드판 출력
}

