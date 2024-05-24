/*
* Project 6 : Ŭ���� ����  (���� �����)
* �ۼ��� : �̿���

* Ŭ���� ���, ���� ���, �� ĳ����, ���� �Լ��� ����Ͽ� ������ ����
* ������ ��Ģ������ �����ϴ� ���� �����
* Y : ����� ����� �̿��� �ļ� ���
* AC : ���� ��� �ʱ�ȭ
* EXIT : ����
*/

#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
	//�������� ����!
	// �ڽ� Ŭ�������� �����ؾ� ��.
	static double result;

	//������ ����
	Calculator(double n1, double n2) : num1(n1), num2(n2) {}

	//�����Լ� ����
	//�������̵� ��
	virtual void calculate() = 0;


protected:
	double num1;
	double num2;
};


// ���� ���� �ʱ�ȭ
double Calculator::result = 0.0;


class Plus : public Calculator
{
public:
	Plus(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 + num2;
		cout << "������? " << result << "�Դϴ�." << endl;
	}
};


class Minus : public Calculator
{
public:
	Minus(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 - num2;
		cout << "������? " << result << "�Դϴ�." << endl;
	}
};


class Multiply : public Calculator
{
public:
	Multiply(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 * num2;
		cout << "������? " << result << "�Դϴ�." << endl;
	}
};

class Divide : public Calculator
{
public:
	Divide(double n1, double n2) : Calculator(n1, n2) {}

	void calculate() override
	{
		result = num1 / num2;
		cout << "������? " << result << "�Դϴ�." << endl;
	}
};



int main()
{
	//https://rehtorb-algorithm.tistory.com/8
	//�θ�Ŭ���� ����Ű�� ������
	//calculator Ŭ������ ������ ���� cal�� �����ϰ� �ʱⰪ�� nullptr�� �����մϴ�. 
	// �� ������ ���߿� � ������ ���� ��ü�� ����ų�� �����ϱ� ���� ���˴ϴ�.
	Calculator* cal = nullptr;


	cout << "���� ���α׷�" << endl;
	cout << "�� ���� ���ڸ� �Է��ϼ���!" << endl;

	int n1, n2;
	cout << "ù��° ���� : ";
	cin >> n1;
	cout << "ù��° ���� : ";
	cin >> n2;

	while (1)
	{
		string option;
		cout << "���Ͻô� ��Ģ������ ��ȣ�� �Է����ּ��� ( + - % /)" << endl;
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
			cout << "�ùٸ� �����ڸ� �Է����ּ��� : ";
			continue;
		}

		cal->calculate();
		//��� ����

		cout << "������ ��� �����Ͻðڽ��ϱ�? (Y : ���, AC : �ʱ�ȭ, EXIT : ����) : " << endl;
		string userChoice;
		cin >> userChoice;

		if (userChoice == "Y")
		{
			continue;
		}
		else if (userChoice == ��}

