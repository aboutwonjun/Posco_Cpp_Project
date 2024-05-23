/*
Project 3 : 랜덤 숫자 맞추기
작성자 : 이원준
1) 컴퓨터가 1~25까지의 수 중 랜덤으로 6개의 수 지정 (중복 x)
2) 사용자도 1~25까지의 수 중 원하는 숫자 6개 입력 (중복 x)
3) 두 배열을 비교해서 몇 등인지 출력하기!
3-1) 한 개도 맞추지 못하면 7등, 1개만 맞추면 6등, 2개 맞추면 5등...
3-2) 6개를 모두 맞추면 1등!
*/

#include <iostream>
#include <random>
#include <set>

using namespace std;

int main()
{

    srand(time(NULL));

    cout << "랜덤 숫자 맞추기 게임을 시작합니다." << endl;
    cout << "컴퓨터가 1~25 범위에서 랜덤으로 6개 숫자를 지정합니다." << endl;
    int computerArr[6];
    set<int> uniqueNumbers; // 중복 제거를 위함 

    for (int i = 0; i < 6; ++i)
    {
        //벡터나 배열을 만들어서 비교해야 할듯? 
        int a;
        do
        {
            a = rand() % 25 + 1;
        }
        //에러할 필요 없음
        while (uniqueNumbers.find(a) != uniqueNumbers.end());
        computerArr[i] = a;
        uniqueNumbers.insert(a);
    }

    //확인을 위한 코드 
    cout << "컴퓨터가 선택한 숫자는: ";
    for (int i = 0; i < 6; ++i)
    {
        cout << computerArr[i] << " ";
    }
    cout << endl;


    cout << "컴퓨터의 턴이 끝났습니다." << endl;

    cout << "당신의 차례입니다." << endl;

    int userArr[6];
    set<int> uniqueUserNumbers; // 중복 제거를 위함 


    for (int i = 0; i < 6; i++)
    {
        int userNumber;
        while (true)
        {
            cout << i + 1 << "번째 숫자를 입력하세요. : ";
            cin >> userNumber;

            // 예외처리 1 - 범위 오류
            if (userNumber < 1 || userNumber > 25)
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

    // 배열끼리의 비교!
    // 이중 for문 돌면서? 

    int correctCount = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (computerArr[i] == userArr[j])
            {
                correctCount++;

            }
        }
    }


    switch (correctCount)
    {
    case 0:
        cout << "7등입니다....";
        break;
    case 1:
        cout << "6등입니다...";
        break;
    case 2:
        cout << "5등입니다..";
        break;
    case 3:
        cout << "4등입니다!";
        break;
    case 4:
        cout << "3등입니다!";
        break;
    case 5:
        cout << "2등입니다!";
        break;
    case 6:
        cout << "1등입니다!";
        break;
    }



}







