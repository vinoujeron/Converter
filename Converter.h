#pragma once
class Converter {
public:
	Converter();
	Converter(const double& usd, const double& eur);
	double Uah2Usd(const double& amount) const;
	double Uah2Eur(const double& amount) const;
	double Eur2Uah(const double& amount) const;
	double Usd2Uah(const double& amount) const;
private:
	const double _usd;
	const double _eur;
};
