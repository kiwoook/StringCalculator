#include <iostream>
#include <string>;
using namespace std;


int main() {
	string expression = "10+20*5/10";
	
	expression.insert(0, " ");
	expression.insert(expression.size(), " ");

	int symbol = 0;
	
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-') {
			symbol += 1;
		}
	}
	
	
	int sw = 0;
	while (true) {
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == '*' || expression[i] == '/') {
				sw = 1;
				break;
			}
			else {
				sw = 0;
			}
		}
		for (int i = 0; i < expression.size(); i++) {
			if ((expression[i] == '*' || expression[i] == '/') && sw == 1) {
				int value1, value2;
				int value;
				string stringValue;
				//우선 인접한 숫자 뜯어내기
				int j; // j는 앞의 숫자를 어디까지 뜯어낼지 찾는 인덱스다.
				for (j = i - 1; j >= 0; j--)
				{
					if (expression[j] >= '0' && expression[j] <= '9') {

					}
					else {
						//연산자를 만나게 된다면 멈춘다.
						break;
					}
				}
				value1 = stoi(expression.substr(j + 1, i - 1));

				//뒤의 인접한 숫자 뜯어내기
				int k; // k는 뒤의 숫자를 어디까지 뜯어낼지 찾는 인덱스다.
				for (k = i + 1; k < expression.size(); k++) {
					if (expression[k] >= '0' && expression[k] <= '9') {

					}
					else {
						//연산자를 만나게 된다면 멈춘다.
						break;
					}
				}
				value2 = stoi(expression.substr(i + 1, k - 1));
				if (expression[i] == '*') {
					value = value1 * value2;

				}
				if (expression[i] == '/') {
					value = value1 / value2;

				}
				stringValue = to_string(value);
				expression.erase(j + 1, k - j - 1 );
				expression.insert(j + 1, stringValue);
				symbol -= 1;
			}
			if((expression[i] == '+' || expression[i] == '-') && sw == 0){
				int value1, value2;
				int value;
				string stringValue;
				//우선 인접한 숫자 뜯어내기
				int j; // j는 앞의 숫자를 어디까지 뜯어낼지 찾는 인덱스다.
				for (j = i - 1; j >= 0; j--)
				{
					if (expression[j] >= '0' && expression[j] <= '9') {

					}
					else {
						//연산자를 만나게 된다면 멈춘다.
						break;
					}
				}
				value1 = stoi(expression.substr(j + 1, i - 1));

				//뒤의 인접한 숫자 뜯어내기
				int k; // k는 뒤의 숫자를 어디까지 뜯어낼지 찾는 인덱스다.
				for (k = i + 1; k < expression.size(); k++) {
					if (expression[k] >= '0' && expression[k] <= '9') {

					}
					else {
						//연산자를 만나게 된다면 멈춘다.
						break;
					}
				}
				value2 = stoi(expression.substr(i + 1, k - 1));
				if (expression[i] == '+') {
					value = value1 + value2;

				}
				if (expression[i] == '-') {
					value = value1 - value2;

				}
				stringValue = to_string(value);
				expression.erase(j + 1, k - j - 1);
				expression.insert(j + 1, stringValue);
				symbol -= 1;
			}
			
		}
		if (symbol == 0) {
			break;
		}
	}

	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] >= '0' && expression[i] <= '9')
		{

		}
		else
		{
			expression.erase(i, 1);
		}
	}

	cout << expression;
	return 0;
}