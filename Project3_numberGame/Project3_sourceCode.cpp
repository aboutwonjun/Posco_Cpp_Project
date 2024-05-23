/*
Project 3 : ���� ���� ���߱�
�ۼ��� : �̿���
1) ��ǻ�Ͱ� 1~25������ �� �� �������� 6���� �� ���� (�ߺ� x)
2) ����ڵ� 1~25������ �� �� ���ϴ� ���� 6�� �Է� (�ߺ� x)
3) �� �迭�� ���ؼ� �� ������ ����ϱ�!
3-1) �� ���� ������ ���ϸ� 7��, 1���� ���߸� 6��, 2�� ���߸� 5��...
3-2) 6���� ��� ���߸� 1��!
*/

#include <iostream>
#include <random>
#include <set>

using namespace std;

int main()
{

    srand(time(NULL));

    cout << "���� ���� ���߱� ������ �����մϴ�." << endl;
    cout << "��ǻ�Ͱ� 1~25 �������� �������� 6�� ���ڸ� �����մϴ�." << endl;
    int computerArr[6];
    set<int> uniqueNumbers; // �ߺ� ���Ÿ� ���� 

    for (int i = 0; i < 6; ++i)
    {
        //���ͳ� �迭�� ���� ���ؾ� �ҵ�? 
        int a;
        do
        {
            a = rand() % 25 + 1;
        }
        //������ �ʿ� ����
        while (uniqueNumbers.find(a) != uniqueNumbers.end());
        computerArr[i] = a;
        uniqueNumbers.insert(a);
    }

    //Ȯ���� ���� �ڵ� 
    cout << "��ǻ�Ͱ� ������ ���ڴ�: ";
    for (int i = 0; i < 6; ++i)
    {
        cout << computerArr[i] << " ";
    }
    cout << endl;


    cout << "��ǻ���� ���� �������ϴ�." << endl;

    cout << "����� �����Դϴ�." << endl;

    int userArr[6];
    set<int> uniqueUserNumbers; // �ߺ� ���Ÿ� ���� 


    for (int i = 0; i < 6; i++)
    {
        int userNumber;
        while (true)
        {
            cout << i + 1 << "��° ���ڸ� �Է��ϼ���. : ";
            cin >> userNumber;

            // ����ó�� 1 - ���� ����
            if (userNumber < 1 || userNumber > 25)
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

    // �迭������ ��!
    // ���� for�� ���鼭? 

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
        cout << "7���Դϴ�....";
        break;
    case 1:
        cout << "6���Դϴ�...";
        break;
    case 2:
        cout << "5���Դϴ�..";
        break;
    case 3:
        cout << "4���Դϴ�!";
        break;
    case 4:
        cout << "3���Դϴ�!";
        break;
    case 5:
        cout << "2���Դϴ�!";
        break;
    case 6:
        cout << "1���Դϴ�!";
        break;
    }



}







