#include "Polynomial.h"

Polynomial::Polynomial() {
}

Polynomial::Polynomial(const Polynomial& orig) {
    *this = orig;
}

Polynomial::Polynomial(std::list<Term>& lst)
{
	term_list = lst;
}

Polynomial::~Polynomial() {
    term_list.clear();
}

bool Polynomial::parse(std::string input){
    
    term_list.clear(); //start fresh

    std::stringstream s; //putting input into a stream to manipulate more easily
    s << input;

    Term next_term;
    char last_operand = '+';
    char next_char;
    int num;
    bool neg_expo = false;

    while (s >> next_char) {
        
        //if the very first thing we read is a digit, then this has to be either the coefficient of a variable or a constant
        if (isdigit(next_char)){
            s.putback(next_char);
            s >> num;
            //make the coefficient negative if the last operand we encountered was a -
            if (last_operand == '-') { num *= -1; }
            next_term.set_coefficient(num);

            s >> next_char;
            if (next_char == 'x' || next_char == 'X'){
                //if an x is next, then we read again to see if we have an exponent to get
                s >> next_char;

                if (next_char == '^'){
                    //when we read the character after the ^, if it's not an int or a -, throw an exception
                    s >> next_char;
                    if (next_char == '-'){
                        neg_expo = true;
                        s >> next_char;
                    }
                    if (isdigit(next_char)){
                        s.putback(next_char);
                        s >> num;
                        if (neg_expo){ //negative exponent?
                            num *= -1;
                            neg_expo = false; //reset neg_expo for the next go through
                        }
                        next_term.set_exponent(num);
                        //we now have read a full term and can begin again.
                        term_list.push_back(next_term);
                        continue;
                    }
                    else{
                        //throw exception
                        throw std::runtime_error("Read unexpected character.");
                        return false;
                    }
                }
                //otherwise, we have an exponent of 1 and we can start the loop again
                else{
                    //putback whatever we read instead of a ^
                    s.putback(next_char);
                    next_term.set_exponent(1);
                    term_list.push_back(next_term);
                    continue;
                }
            }
            //otherwise, this term is a constant, we're done and we can start the loop again
            //to define a constant, I'm just using an exponent of 0. If there is an exponent of 0 and we treat it like a constant, it'd be like 5x^0 which would just be 5 (a constant) anyways, right?
            else{
                next_term.set_exponent(0);
                term_list.push_back(next_term);
                continue;
            }
        }
        
        //if it's not a number, then it might be a variable
        else if (next_char == 'x' || next_char == 'X'){
            //we're going to have a coefficient of 1, but, if the previous operand was -, it's a -1
            next_term.set_coefficient(1);
            if (last_operand == '-'){ next_term.set_coefficient(-1); }
            //if an x is next, then we read again to see if we have an exponent to get
            s >> next_char;
            if (next_char == '^'){
                //when we read the character after the ^, if it's not an int or a -, throw an exception
                s >> next_char;
                if (next_char == '-'){
                    neg_expo = true;
                    s >> next_char;
                }
                if (isdigit(next_char)){
                    s.putback(next_char);
                    s >> num;
                    if (neg_expo){ //negative exponent?
                        num *= -1;
                        neg_expo = false; //reset neg_expo for the next go through
                    }
                    next_term.set_exponent(num);
                    //we now have read a full term and can begin again.
                    term_list.push_back(next_term);
                    continue;
                }
                else{
                    //throw exception
                    throw std::runtime_error("Read unexpected character.");
                    return false;
                }
            }
            //otherwise, we have no exponent
            else{
                //put back whatever we read instead of a ^
                s.putback(next_char);
                next_term.set_exponent(1);
                term_list.push_back(next_term);
                continue;
            }
        }

        //if it's not a number or a variable, then it's either an operand or the input is invalid
        //we technically don't need to know if the last operand is a +, but we DEFINITELY need to know if it is a - or not, so we have to change it anyways.
        else if (next_char == '+'){
            last_operand = '+';
        }
        else if (next_char == '-'){
            last_operand = '-';
        }
        else{
            //throw exception
            throw std::runtime_error("Read unexpected character.");
            return false;
        }
    }
    return true;
}

Polynomial& Polynomial::operator+(const Polynomial& rhs)
{
	//makes temps that can be worked with
	std::list<Term> tmp1 = term_list;
	std::list<Term> tmp2 = rhs.term_list;
	std::list<Term>::iterator itt;
	
	for (itt = tmp2.begin(); itt != tmp2.end(); itt++)
	{
		tmp1.push_back(*itt);
	}

	//puts list back into a wrapper object
	Polynomial* temp = new Polynomial(); //switched to pointer to fix segfault
	(*temp).term_list = tmp1;

	//reduces the new list
	(*temp).reduce();

	return *temp;
}

const Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    term_list.clear();
    if (rhs.term_list.empty()) return *this; //empty polynomial
    
    //clone term_list using a const_iterator to the rhs.term_list
    for (std::list<Term>::const_iterator iter=rhs.term_list.begin(); iter!=rhs.term_list.end(); ++iter) {
        term_list.push_back(*iter);
    }
    return *this; //cloned polynomial
}

std::string Polynomial::toString() {
    std::string str;
    
    //reduce and sort here, too
    reduce();
    
    for (std::list<Term>::const_iterator iter=term_list.begin(); iter!=term_list.end(); ++iter) {
        str += (*iter).print();
    }
    
    if (str.at(0) == '+') str = str.substr(1); //remove extraneous plus if necessary
    
    return str;
}

void Polynomial::reduce()
{
	this->term_list.sort(std::greater<Term>()); //switch to ascending order

	std::list<Term>::iterator itt1 = this->term_list.begin();
	std::list<Term>::iterator itt2 = this->term_list.begin();
	std::list<Term> ret;
	Term term;
	bool used;
	while (itt1 != term_list.end())
	{
		used = false;
		itt2 = itt1;
		itt2++;
		term.set_coefficient(itt1->get_coefficient());
		term.set_exponent(itt1->get_exponent());
		for (itt2; itt2 != term_list.end(); itt2++)
		{
			if (*itt1 == *itt2)
			{
				term.set_coefficient(term.get_coefficient() + itt2->get_coefficient());
			}
			else
			{
				itt1 = itt2;
				break;
			}
		}
		ret.push_back(term);
		if (itt2 == term_list.end())
			break;
	}
	
	this->term_list = ret;
}
