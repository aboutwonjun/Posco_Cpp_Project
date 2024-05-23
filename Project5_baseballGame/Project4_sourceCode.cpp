/*
* Project 5 : �߱�����
* �ۼ��� : �̿���
* 
* 1) ����ڴ� 1~9���� 3���� ���ڸ� �̾� ��ǻ�Ͱ� �������� ���� ���ڿ� �� (�ߺ� X)
* 2) ���ڿ� �ڸ��� ��� ������ Strike
* 3) �ڸ��� �ٸ����� �Ѱ��� ���ԵǾ� ������ Ball
* 4) 3 Strike or 4 Bal OUT!

*/

#include <iostream>
#include <random>
#include <set>

using namespace std;


// �Լ� ����
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

        cout << "������ �����մϴ�!" << endl;
        refree(userArr, computerArr);

    }
    return 0;
}



void usersChoice(int userArr[], set<int> &uniqueUserNumbers)
{

    cout << "�߱� ������ �����մϴ�. 1���� 9������ ���� �ٸ� 3���� ���ڸ� �Է��ϼ���." << endl;
    for (int i = 0; i < 3; i++)
    {
        int userNumber;
        while (true)
        {
            cout << i + 1 << "��° ���ڸ� �Է��ϼ���. : ";
            cin >> userNumber;
            

            // ����ó�� 1 - ���� ����
            if (userNumber < 1 || userNumber > 9)
            {
                cout << "���� ������ �߸��Ǿ����ϴ�. �ٽ� �Է��ϼ���." << endl;
            }
            // ����ó�� 2 - �ߺ�
            else if ((uniqueUserNumbers.find(userNumber) != uniqueUserNumbers.end()))
            {
                cout << "�ߺ��Ǿ����ϴ�. �ٽ� �Է��ϼ���. " << endl;
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

    cout << "��ǻ�Ͱ� ���ڸ� �����߽��ϴ�." << endl;
    for (int i = 0; i < 3; ++i)
    {
        int a;
        do
        {
            a = rand() % 9 + 1;
        }
        //������ �ʿ� ����
        while (uniqueComputersNumbers.find(a) != uniqueComputersNumbers.end());
        computerArr[i] = a;
        uniqueComputersNumbers.insert(a);
    }
}


// ����: ��Ʈ����ũ�� �� ���
void refree(int userArr[], int computerArr[])
{
    int strike = 0;
    int ball = 0;

    // ��Ʈ����ũ �� �� ���
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
                    break; // �̹� ���� ���ڰ� �ִ� ��� �� �̻� Ž���� �ʿ� ����
                }
            }
        }
    }

    // ��� ���
    cout << "��Ʈ����ũ: " << strike << ", ��: " << ball << endl;

    // ���� ���� ���� Ȯ��
    if (strike == 3)
    {
        cout << "3 ��Ʈ����ũ! ���� ����!" << endl;
    }


}