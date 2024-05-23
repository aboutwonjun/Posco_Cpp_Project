/*
Project : �轺Ų��� 31 ����
���� : �����, ��ǻ�Ͱ� 1~3 ���ӵ� ���ڸ� ���ϰ� 31�� ���ϸ� ���� ����

1) ����ڴ� ������ �Է��� ���ڸ�ŭ
2) ��ǻ�ʹ� ���� ���ڸ�ŭ.
3) �� �����, ��ǻ�� ��� 1-3���� ������ ����!
*/

#include <iostream>
#include <random>

using namespace std;

// �õ尪�� ��� ���� random_device ����
random_device rd;
// random_device�� ���� ���� ���� ���� �ʱ�ȭ��
mt19937 gen(rd());
// 1~3 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����
uniform_int_distribution<int> dis(1, 3);

int main() {
    int currentNumber = 0;  // ���� ����
    int userNumber, computerNumber; // ��� �Է¹��� ���� �����ϴ� ���� 

    while (true) {
        // ����� ��
        cout << "���ϴ� ������ ������ �Է��ϼ���! (1~3)" << endl;
        cin >> userNumber;

        if (userNumber < 1 || userNumber > 3) {
            cout << "�߸��� �Է��Դϴ�. 1���� 3 ������ ���ڸ� �Է��ϼ���." << endl;
            continue;  // �߸��� �Է��̸� �ٽ� ����� ������ ���ư�
        }

        for (int i = 0; i < userNumber; ++i) {
            currentNumber++;
            cout << currentNumber << " ";
            if (currentNumber == 31) {
                cout << "\n����ڰ� 31�� ���߽��ϴ�. ����ڰ� �����ϴ�!" << endl;
                return 0;
            }
        }
        cout << endl;

        // ��ǻ�� ��
        computerNumber = dis(gen);
        cout << "��ǻ���� ���Դϴ�! (" << computerNumber << " ���� ����)" << endl;

        for (int i = 0; i < computerNumber; ++i) {
            currentNumber++;
            cout << currentNumber << " ";
            if (currentNumber == 31) {
                cout << "\n��ǻ�Ͱ� 31�� ���߽��ϴ�. ��ǻ�Ͱ� �����ϴ�!" << endl;
                return 0;
            }
        }
        cout << endl;
    }

    return 0;
}

