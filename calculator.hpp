#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include <cmath>
#include <vector>
#include <string>

bool IsANumber(char c);
bool IsAClassicOperator(char c);
bool IsASpecialOperator(char c);
bool split_nb(std::vector<double>* Vnb,std::string chaine);
bool split_op(std::vector<char>* op,std::string chaine);
bool to_double(double* db,std::string str);
double fact(double nb);
void manage_pow(std::vector<double>* nb,std::vector<char> *op,int index);
double manage_fact(double nb,std::vector<char> *op,int index);
double manage_sqrt(double nb,std::vector<char> *op,int index);
bool check_accepted_char(std::string str, std::string accepted_char);
std::string handle_overflow(std::string exp);
std::string ressearch_parenthese(std::string chaine);
bool calculator(std::string exp,double *tmp);

#endif