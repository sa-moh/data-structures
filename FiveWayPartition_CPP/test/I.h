#pragma once

class I
{
private:
	double value;

public:
	I(const I &i);
	I(double val);
	I();
	~I();

	bool operator>(const I &right) const;
	bool operator<(const I &right) const;
	bool operator>=(const I &right) const;
	bool operator<=(const I &right) const;
	bool operator==(const I &right) const;
	bool operator!=(const I &right) const;
	I &operator=(const I &right);

	friend std::ostream &operator<<(std::ostream &os, const I &obj);

	double getValue() const;
};
