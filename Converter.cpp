#include "Converter.h"

Converter::Converter() : _usd(1), _eur(1) {};
Converter::Converter(const double& usd, const double& eur) : _usd(usd), _eur(eur) {};
double Converter::Uah2Eur(const double& amount) const { return amount * _eur;}
double Converter::Uah2Usd(const double& amount) const { return amount * _usd;}
double Converter::Eur2Uah(const double& amount) const { return amount / _eur;}
double Converter::Usd2Uah(const double& amount) const { return amount / _usd;}