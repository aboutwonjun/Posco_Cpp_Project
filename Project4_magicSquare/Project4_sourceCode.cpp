/*
* 
* Project 4 : 마방진 Magic Square
* 작성자 : 이원준
* 
* 홀수 마방진 푸는 법 
* 
1) 1은 첫 행의 가운데에 위치한다.
2) 우상단으로 갈 수록 숫자가 1씩 늘어난다.
3) 우상단으로 이동하는 도중 이미 칸이 채워져 있으면 바로 아래 칸에 다음 숫
자가 채워진다.
4) 첫번째 행에서 우상단으로 이동할 때는 마지막 행
의 다음 열로 이동한다.
5) 마지막 열에서 우상단으로 이동할 때는 첫번째 열
의 이전 행으로 이동한다.
6) 첫번째 행의 마지막 열에서는 우상단으로 이동하
는 것이 아니라 바로 아래칸으로 이동

*/

//예시
// || 17 || 24 || 1  || 8  || 15 ||
// 
// || 23 || 5  || 7  || 14 || 16 ||  
// 
// || 4  || 6  || 13 || 20 || 22 ||  
// 
// || 10 || 12 || 19 || 21 || 3  ||
// 
// || 11 || 18 || 25 || 2  || 9  ||


// 출처: https://velog.io/@namwlee99/%ED%8F%AC%EC%8A%A4%EC%BD%94x%EC%BD%94%EB%94%A9%EC%98%A8-%EC%8A%A4%EB%A7%88%ED%8A%B8%ED%8C%A9%ED%86%A0%EB%A6%AC-2%EC%A3%BC%EC%B0%A8-%ED%9A%8C%EA%B3%A0-C-%EB%9E%9C%EB%8D%A4-%EC%88%AB%EC%9E%90-%EB%A7%9E%EC%B6%94%EA%B8%B0-%ED%99%80%EC%88%98%EB%A7%88%EB%B0%A9%EC%A7%84-%EB%A7%8C%EB%93%A4%EA%B8%B0
// 마방진이 도저히 이해가 안되어서.. 코드 하나하나 따라치면서 공부했습니다.
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cout << "홀수 n*n 행렬의 마방진을 구현하는 프로그램입니다. 자연수(홀수)를 입력해주세요." << endl;
	cin >> n;


	//예외 처리 
	while (n % 2 == 0)
	{
		cout << "잘못된 입력입니다. 홀수를 입력해주세요 : ";
		cin >> n;  // 새로운 입력을 받음
	}

	//2차원 벡터 선언
// https://leeeegun.tistory.com/3
// ex) vector < vector <int> > v(10,vector <int>(10,0))
	vector<vector<int>> magicSquare(n, vector<int>(n, 0));

	int row = 0;
	int col = n / 2;

	for (int num = 1; num <= n * n; num++)
	{
		magicSquare[row][col] = num;

		//1) 다음 위치 계산 -> 우상단 이동
		int nextRow = row - 1;
		int nextCol = col + 1;

		// 첫 번째 행에서 우상단으로 이동할 때는 마지막 행의 다음 열로 이동
		if (nextRow < 0 && nextCol == n) 
		{
			nextRow = 1;  // 바로 아래 칸으로 이동
			nextCol = n - 1;
		}
		// 첫 번째 행의 마지막 열에서는 바로 아래 칸으로 이동
		else if (nextRow < 0)
		{
			nextRow = n - 1;
		}
		// 마지막 열에서 우상단으로 이동할 때는 첫 번째 열로 이동
		else if (nextCol == n) 
		{
			nextCol = 0;
		}
		//2) 이미 채워져있을 경우, 아래로 이동
		if (magicSquare[nextRow][nextCol] != 0)
		{
			row = (row + 1);
		}
		else
		{
			row = nextRow;
			col = nextCol;
		}
	}


	cout << "****************************" << endl;
	cout << "마방진을 출력합니다!" << endl;
	cout << "****************************" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << magicSquare[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}