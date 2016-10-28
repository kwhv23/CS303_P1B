#include "Term.h"

Term::Term() {
    exponent = 0;
    coefficient = 0;
}

Term::Term(const Term& orig) {
    exponent = orig.exponent;
    coefficient = orig.coefficient;
}

Term::~Term() {
}

std::string Term::print() const {
    std::stringstream ss;
    if (coefficient == 0) return ss.str(); //nothing to print
    if (coefficient > 0) ss << "+";
    if (exponent == 0) { //constant term
        ss << coefficient;
        return ss.str();
    }
    if (coefficient == -1) ss << "-"; //otherwise ss << coefficient; takes care of this
    else if (coefficient != 1 ) ss << coefficient;
    ss << "x";
    if (exponent == 1) return ss.str(); //no exponent needed
    ss << "^" << exponent;
    return ss.str(); //full term
}

//getters&&setters
void Term::set_exponent(const int expo){
    exponent = expo;
}

void Term::set_coefficient(const int coeff){
    coefficient = coeff;
}

int Term::get_exponent() const {
    return exponent;
}

int Term::get_coefficient() const {
    return coefficient;
}

const Term& Term::operator=(const Term& rhs)
{
	exponent = rhs.exponent;
	coefficient = rhs.coefficient;

	return *this;
}

//Boolean operators
bool Term::operator== (const Term& rhs) const //needed to be const
{
	return exponent == rhs.exponent; //simplified
}

bool Term::operator!= (const Term& rhs) const //ditto
{
	return exponent != rhs.exponent;
}

bool Term::operator> (const Term& rhs) const //etc
{
	return exponent > rhs.exponent;
}

bool Term::operator>= (const Term& rhs) const
{
    return exponent >= rhs.exponent;
}

bool Term::operator< (const Term& rhs) const
{
    return exponent < rhs.exponent;
}

bool Term::operator<= (const Term& rhs) const
{
	return exponent <= rhs.exponent;
}
