/*
* Project 5 : 야구게임
* 작성자 : 이원준
* 
* 1) 사용자는 1~9까지 3개의 숫자를 뽑아 컴퓨터가 랜덤으로 뽑은 숫자와 비교 (중복 X)
* 2) 숫자와 자리가 모두 같으면 Strike
* 3) 자리는 다르지만 한개라도 포함되어 있으면 Ball
* 4) 3 Strike or 4 Bal OUT!

*/

#include <iostream>
#include <random>
#include <set>

using namespace std;


// 함수 선언
void usersChoice(int userArr[], set<int>& uniqueUserNumbers);
void computersChoice(int computerArr[], set<int>& uniqueComputersNumbers);
void refree(int userArr[], int computerArr[]);


int main()
{
    bool gameEnd = false;

    while (!gameEnd)
    {
        int userArr[3];
        set<int> uniqueUserNumbers;
        usersChoice(userArr, uniqueUserNumbers);

        int computerArr[3];
        set<int> uniqueComputersNumbers;
        computersChoice(computerArr, uniqueComputersNumbers);

        cout << "판정을 시작합니다!" << endl;
        refree(userArr, computerArr);

    }
    return 0;
}



void usersChoice(int userArr[], set<int> &uniqueUserNumbers)
{

    cout << "야구 게임을 시작합니다. 1부터 9까지의 서로 다른 3개의 숫자를 입력하세요." << endl;
    for (int i = 0; i < 3; i++)
    {
        int userNumber;
        while (true)
        {
            cout << i + 1 << "번째 숫자를 입력하세요. : ";
            cin >> userNumber;
            

            // 예외처리 1 - 범위 오류
            if (userNumber < 1 || userNumber > 9)
            {
                cout << "숫자 범위가 잘못되었습니다. 다시 입력하세요." << endl;
            }
            // 예외처리 2 - 중복
            else if ((uniqueUserNumbers.find(userNumber) != uniqueUserNumbers.end()))
            {
                cout << "중복되었습니다. 다시 입력하세요. " << endl;
            }
            else
            {
                userArr[i] = userNumber;
                uniqueUserNumbers.insert(userNumber);
                break;
            }
        }
    }
}



void computersChoice(int computerArr[], set<int>& uniqueComputersNumbers)
{

    cout << "컴퓨터가 숫자를 선택했습니다." << endl;
    for (int i = 0; i < 3; ++i)
    {
        int a;
        do
        {
            a = rand() % 9 + 1;
        }
        //에러할 필요 없음
        while (uniqueComputersNumbers.find(a) != uniqueComputersNumbers.end());
        computerArr[i] = a;
        uniqueComputersNumbers.insert(a);
    }
}


// 심판: 스트라이크와 볼 계산
void refree(int userArr[], int computerArr[])
{
    int strike = 0;
    int ball = 0;

    // 스트라이크 및 볼 계산
    for (int i = 0; i < 3; i++)
    {
        if (userArr[i] == computerArr[i])
        {
            strike++;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                if (userArr[i] == computerArr[j])
                {
                    ball++;
                    break; // 이미 같은 숫자가 있는 경우 더 이상 탐색할 필요 없음
                }
            }
        }
    }

    // 결과 출력
    cout << "스트라이크: " << strike << ", 볼: " << ball << endl;

    // 게임 종료 조건 확인
    if (strike == 3)
    {
        cout << "3 스트라이크! 게임 종료!" << endl;
    }


}