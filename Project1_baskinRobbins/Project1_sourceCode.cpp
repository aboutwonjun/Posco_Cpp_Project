/*
Project : 배스킨라빈스 31 게임
내용 : 사용자, 컴퓨터가 1~3 연속된 숫자를 말하고 31을 말하면 지는 게임

1) 사용자는 본인이 입력한 숫자만큼
2) 컴퓨터는 랜덤 숫자만큼.
3) 단 사용자, 컴퓨터 모드 1-3개의 개수만 가능!
*/

#include <iostream>
#include <random>

using namespace std;

// 시드값을 얻기 위한 random_device 생성
random_device rd;
// random_device를 통해 난수 생성 엔진 초기화함
mt19937 gen(rd());
// 1~3 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의
uniform_int_distribution<int> dis(1, 3);

int main() {
    int currentNumber = 0;  // 현재 숫자
    int userNumber, computerNumber; // 몇개를 입력받을 건지 결정하는 변수 

    while (true) {
        // 사용자 턴
        cout << "원하는 숫자의 개수를 입력하세요! (1~3)" << endl;
        cin >> userNumber;

        if (userNumber < 1 || userNumber > 3) {
            cout << "잘못된 입력입니다. 1에서 3 사이의 숫자를 입력하세요." << endl;
            continue;  // 잘못된 입력이면 다시 사용자 턴으로 돌아감
        }

        for (int i = 0; i < userNumber; ++i) {
            currentNumber++;
            cout << currentNumber << " ";
            if (currentNumber == 31) {
                cout << "\n사용자가 31을 말했습니다. 사용자가 졌습니다!" << endl;
                return 0;
            }
        }
        cout << endl;

        // 컴퓨터 턴
        computerNumber = dis(gen);
        cout << "컴퓨터의 턴입니다! (" << computerNumber << " 개의 숫자)" << endl;

        for (int i = 0; i < computerNumber; ++i) {
            currentNumber++;
            cout << currentNumber << " ";
            if (currentNumber == 31) {
                cout << "\n컴퓨터가 31을 말했습니다. 컴퓨터가 졌습니다!" << endl;
                return 0;
            }
        }
        cout << endl;
    }

    return 0;
}

