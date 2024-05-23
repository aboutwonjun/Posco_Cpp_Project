/*
Project 2 : 타임어택 끝말잇기(concentration) 게임
작성자 : 이원준 
1) 제한시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
2) 제한시간이 종료되면 게임을 종료, 입력한 단어의 개수를 출력
3) 한번 입력된 단어는 입력하지 못함 
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main() 
{
    vector<string> words; // 입력된 단어 저장
    string prevWord, currWord; // 이전 단어, 현재 단어
    time_t startTime, currentTime;
    int remainingTime = 30; // 제한 시간 (초)

    cout << "타임어택 끝말잇기 게임 시작!" << endl;
    cout << "제한 시간: " << remainingTime << "초" << endl;
    cout << "시작 단어를 입력하세요: ";
    cin >> prevWord;
    words.push_back(prevWord); 

    startTime = time(NULL); 

    while (true) 
    {
        currentTime = time(NULL);
        remainingTime = 30 - (currentTime - startTime);

        //시간 초과
        if (remainingTime <= 0) 
        {
            cout << "\n시간 초과!" << endl;
            break;
        }

        cout << "남은 시간: " << remainingTime << "초" << endl;
        cout << "다음 단어를 입력하세요: ";
        cin >> currWord;

        // 이미 입력된 단어 확인
        // True False로 구분. ㅁ
        bool isDuplicate = false;
        for (string word : words) {
            if (word == currWord) {
                isDuplicate = true;
                break;
            }
        }

        //이미 입력이 되어있을 경우 에러
        if (isDuplicate) {
            cout << "이미 입력된 단어입니다. 다시 입력하세요." << endl;
            continue; 
        }

        // 끝말잇기 규칙 확인
        if (prevWord[prevWord.length() - 1] != currWord[0]) {
            cout << "끝말잇기 규칙에 맞지 않습니다. 다시 입력하세요." << endl;
            continue; 
        }

        // 유효한 단어 입력 시
        words.push_back(currWord);
        prevWord = currWord; 
    }

    cout << "게임 종료! 입력한 단어 개수: " << words.size() << endl;

    return 0;
}