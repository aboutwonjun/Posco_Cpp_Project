/*
* Project 6 : 클래스 복습  (계산기 만들기)
* 작성자 : 이원준

* 클래스 상속, 정적 멤버, 업 캐스팅, 가상 함수를 사용하여 다음과 같이
* 간단한 사칙연산을 수행하는 계산기 만들기
* Y : 도출된 결과를 이용한 후속 계산
* AC : 이전 기록 초기화
* EXIT : 종료
*/

#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
	//정적변수 선언!
	// 자식 클래스에서 공유해야 함.
	static double result;

	//생성자 선언
	Calculator(double n1, double n2) : num1(n1), num2(n2) {}

	//가상함수 선언
	//오버라이딩 용
	virtual void calculate() = 0;


protected:
	double num1;
	double num2;
};


// 정적 변수 초기화
double Calculator::result = 0.0;


class Plus : public Calculator
{
public:
	Plus(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 + num2;
		cout << "정답은? " << result << "입니다." << endl;
	}
};


class Minus : public Calculator
{
public:
	Minus(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 - num2;
		cout << "정답은? " << result << "입니다." << endl;
	}
};


class Multiply : public Calculator
{
public:
	Multiply(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 * num2;
		cout << "정답은? " << result << "입니다." << endl;
	}
};

class Divide : public Calculator
{
public:
	Divide(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 / num2;
		cout << "정답은? " << result << "입니다." << endl;
	}
};



int main()
{
	//https://rehtorb-algorithm.tistory.com/8
	//부모클래스 가르키는 포인터
	//calculator 클래스의 포인터 변수 cal을 선언하고 초기값을 nullptr로 설정합니다. 
	// 이 변수는 나중에 어떤 종류의 계산기 객체를 가리킬지 결정하기 위해 사용됩니다.
	Calculator* cal = nullptr;


	cout << "계산기 프로그램" << endl;
	cout << "두 개의 숫자를 입력하세요!" << endl;

	int n1, n2;
	cout << "첫번째 숫자 : ";
	cin >> n1;
	cout << "첫번째 숫자 : ";
	cin >> n2;

	while (1)
	{
		string option;
		cout << "원하시는 사칙연산의 기호를 입력해주세요 ( + - % /)" << endl;
		cin >> option;

		switch (option[0])
		{
		case '+':
			cal = new Plus(n1, n2);
			break;
		case '-':
			cal = new Minus(n1, n2);
			break;
		case '*':
			cal = new Multiply(n1, n2);
			break;
		case '/':
			cal = new Divide(n1, n2);
			break;

		default:
			cout << "올바른 연산자를 입력해주세요 : ";
			continue;
		}

		cal->calculate();
		//계산 수행

		cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) : " << endl;
		string userChoice;
		cin >> userChoice;

		if (userChoice == "Y")
		{
			continue;
		}
		else if (userChoice == ㅛ}

