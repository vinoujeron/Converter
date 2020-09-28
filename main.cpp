#include <iostream>
#include <sstream>
#include <string>
#include <istream>
#include "Converter.h"

enum Operation {
	USD_TO_UAH,
	EUR_TO_UAH,
	UAH_TO_USD,
	UAH_TO_EUR,
	ERROR
};

struct Query {
	Operation operarion;
	double amount;
};

std::istream& operator>> (std::istream& is, Query& q) {
	std::string op;
	is >> op;
	if (op == "EUR_TO_UAH") {
		q.operarion = Operation::EUR_TO_UAH;
		is >> q.amount;
	}
	else if (op == "USD_TO_UAH") {
		q.operarion = Operation::USD_TO_UAH;
		is >> q.amount;
	}
	else if (op == "UAH_TO_USD") {
		q.operarion = Operation::UAH_TO_USD;
		is >> q.amount;
	}
	else if (op == "UAH_TO_EUR") {
		q.operarion = Operation::UAH_TO_EUR;
		is >> q.amount;
	}
	else
		q.operarion = Operation::ERROR;

	return is;
}

int main()
{
	std::cout << "*********HELLO*********" << std::endl;
	std::cout << "This is money converter" << std::endl;

	std::cout << "Enter convertion rate USD to UAH, EUR to UAH (0.25 0.55) for example: ";
	double a, b;
	std::cin >> a >> b;
	Converter converter(a, b);

	std::cout << "To start enter: \"CONVERTION_TYPE AMOUNT\" to ." << std::endl;
	std::cout << "Available types: USD_TO_UAH, EUR_TO_UAH, UAH_TO_USD, UAH_TO_EUR" << std::endl;
	std::cout << "Example: USD_TO_UAH 100" << std::endl;
	std::cout << "Enter: ";
	Query q;
	while (std::cin >> q) {
		if (q.operarion == Operation::EUR_TO_UAH) {
			std::cout << converter.Eur2Uah(q.amount) << std::endl;
		}
		else if (q.operarion == Operation::USD_TO_UAH) {
			std::cout << converter.Usd2Uah(q.amount) << std::endl;
		}
		else if (q.operarion == Operation::UAH_TO_USD) {
			std::cout << converter.Uah2Usd(q.amount) << std::endl;
		}
		else if (q.operarion == Operation::UAH_TO_EUR) {
			std::cout << converter.Uah2Eur(q.amount) << std::endl;
		}
		else
			std::cout << "Wrong input!" << std::endl;

		std::cout << "To start enter: \"CONVERTION_TYPE AMOUNT\" to ." << std::endl;
		std::cout << "Example: USD_TO_UAH 100" << std::endl;
		std::cout << "Enter: ";
	}

	std::cout << converter.Uah2Usd(100) << std::endl;
	std::cout << converter.Uah2Eur(100) << std::endl;
}