/*
location : .\calculator\src\
compile command : 
g++ ..\fct_4_error\fct_error.cpp .\calculator2.cpp -o ..\bin\calc.exe
*/

/**
 * TASK LIST :
 * + handle_overflow
 * + make function for #
 * 
 * op : + - * /  ! ^ # 
 * /!\english notation : 128.51 
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cmath>
#include "../fct_4_error/fct_error.hpp"

using namespace std;

bool IsANumber(char c);
bool IsAClassicOperator(char c);
bool IsASpecialOperator(char c);
bool split_nb(vector<double>* Vnb,string chaine);
bool split_op(vector<char>* op,string chaine);
bool to_double(double* db,string str);
double fact(double nb);
void manage_pow(vector<double>* nb,vector<char> *op,int index);
double manage_fact(double nb,vector<char> *op,int index);
double manage_sqrt(double nb,vector<char> *op,int index);
bool check_accepted_char(string str, string accepted_char);

string handle_overflow(string exp);
string ressearch_parenthese(string chaine);
bool calculator(string exp,double *tmp);

int main(int argc, char const *argv[])
{
    double tmp_db;
    string tmp_str;
    
    //TEST IsANumber
    string test("10^3+(!(2.5-!!3)+#4)*5^2/(#6.2*!7)+!8+9");
    int score(0);
    for (int i = 0; i < test.size(); i++)
    {
        if (IsANumber(test.at(i)))
        {
            ++score;
        }
    }
    if (score==14)
    {
        cout<<"test IsANumber SUCCEEDED" <<endl;
    }else{
        cout<<"test IsANumber FAILED : score="<<score<<endl;
    }
    score=0;
    
    //TEST IsAClassicOperator
    for (int i = 0; i < test.size(); i++)
    {
        if (IsAClassicOperator(test.at(i)))
        {
            ++score;
        }
    }
    if (score==8)
    {
        cout<<"test IsAClassicOperator SUCCEEDED" <<endl;
    }else{
        cout<<"test IsAClassicOperator FAILED : score="<<score<<endl;
    }
    score=0;
    
    //TEST IsASpecialOperator
    for (int i = 0; i < test.size(); i++)
    {
        if (IsASpecialOperator(test.at(i)))
        {
            ++score;
        }
    }
    if (score==9)
    {
        cout<<"test IsASpecialOperator SUCCEEDED" <<endl;
    }else{
        cout<<"test IsASpecialOperator FAILED: score="<<score<<endl;
    }
    score=0;

    //TEST split_nb
    vector<double> nb;
    split_nb(&nb,"2.5-!!3");
    if (nb.size()==2)
    {
        cout<<"test split_nb SUCCEEDED" <<endl;
    }else{
        cout<<"test split_nb FAILED : nb size="<<nb.size()<<endl;
        for (size_t i = 0; i < nb.size(); i++)
        {
            cout<<"=>"<<nb.at(i)<<endl;
        }
    }

    //TEST split_op
    vector<char> op;
    split_op(&op,test);
    if (op.size()==17)
    {
        cout<<"test split_op SUCCEEDED" <<endl;
    }else{
        cout<<"test split_op FAILED : op size="<<op.size()<<endl;
        for (size_t i = 0; i < op.size(); i++)
        {
            cout<<"=>"<<op.at(i)<<endl;
        }
    }
    
    //TEST to_double
    for (double i = 95; i <= 105; i+=0.5)
    {
        double tmp(i);
        to_double(&tmp_db,"0000"+to_string(tmp)+"000");
        tmp_db-=2;
        if (tmp_db==tmp-2)
        {
            ++score;
        }
    }
    if (score==(105-95)/0.5+1)
    {
        cout<<"test to_double SUCCEEDED" <<endl;
    }else{
        cout<<"test to_double FAILED : score="<<score<<endl;
    }
    

    //TEST fact
    tmp_db=fact(6);
    if (tmp_db==720)
    {
        cout<<"test fact SUCCEEDED" <<endl;
    }else{
        cout<<"test fact FAILED : !5="<<tmp_db<<endl;
    }

    //TEST manage_pow
    vector<double> vnb;
    vnb.push_back(3);
    vnb.push_back(2);
    vnb.push_back(4);
    vector<char> vchar;
    vchar.push_back('^');
    vchar.push_back('^');
    manage_pow(&vnb,&vchar,0);
    if (vnb.at(0)==pow(3,pow(2,4)))
    {
        cout<<"test manage_pow SUCCEEDED" <<endl;
    }else{
        cout<<"test manage_pow FAILED : "<<vnb.at(0)<<endl;
    }
    vnb.clear();
    vchar.clear();

    //TEST manage_fact
    tmp_db=3;
    vchar.push_back('!');
    vchar.push_back('!');

    if (manage_fact(tmp_db,&vchar,0)==fact(fact(3)))
    {
        cout<<"test manage_fact SUCCEEDED" <<endl;
    }else{
        cout<<"test manage_fact FAILED : "<<manage_fact(tmp_db,&vchar,0)<<endl;
    }
    vchar.clear();

    //TEST manage_sqrt
    tmp_db=81;
    
    vchar.push_back('#');
    vchar.push_back('#');

    if (manage_sqrt(tmp_db,&vchar,0)==sqrt(sqrt(81)))
    {
        cout<<"test manage_sqrt SUCCEEDED" <<endl;
    }else{
        cout<<"test manage_sqrt FAILED : "<<manage_sqrt(tmp_db,&vchar,0)<<"="<<sqrt(sqrt(81))<<endl;
    }
    
    //TEST handle_overflow
    string exp("");
    tmp_str=handle_overflow(exp);
    if (tmp_str==test)
    {
        cout<<"test handle_overflow SUCCEEDED" <<endl;
    }else{
        cout<<"test handle_overflow FAILED : "<<exp<<"=>"<<tmp_str<<endl;
    }
    

    //TEST ressearch_parenthese
    tmp_str=ressearch_parenthese(test);
    if (tmp_str=="!(2.5-!!3)+#4")
    {
        cout<<"test ressearch_parenthese SUCCEEDED"<<endl;
    }else{
        cout<<"test ressearch_parenthese FAILED : "<<tmp_str<<endl;
    }

    //TEST check_accepted_char

    if (check_accepted_char("12.","0123456789."))
    {
        cout<<"test check_accepted_char SUCCEEDED"<<endl;
    }else{
        cout<<"test check_accepted_char FAILED "<<endl;
    }
    

    
    //TEST calculator
    test="8^2+(9-4)*#9-!2";
    if (calculator(test,&tmp_db) and tmp_db==pow(8,2)+(9-4)*sqrt(9)-fact(2))
    {
        cout<<"test calculator SUCCEEDED" <<endl;
    }else{
        cout<<"test calculator FAILED : "<<test<<"="<<tmp_db<<endl;
    }
    
    return 0;
}

/**
 * @brief return if a char c is a number or not
 * 
 * @param c <char> a char to analyze.
 * @return true if the it's a number,
 * @return false  if it's not
 */
bool IsANumber(char c){
    switch (c)
    {
    case '0':
        return true;
        break;
    case '1':
        return true;
        break;
    case '2':
        return true;
        break;
    case '3':
        return true;
        break;
    case '4':
        return true;
        break;
    case '5':
        return true;
        break;
    case '6':
        return true;
        break;
    case '7':
        return true;
        break;
    case '8':
        return true;
        break;
    case '9':
        return true;
        break;
    
    default:
    return false;
        break;
    }
}

/**
 * @brief return if a char c is a operator like '+', '-', '*' or '/'.
 * 
 * @param c <char> a char to analyze. 
 * @return true if it's a classic operator,
 * @return false if it's not.
 */
bool IsAClassicOperator(char c){
    switch (c)
    {
    case '+':
        return true;
        break;
    case '-':
        return true;
        break;
    case '*':
        return true;
        break;
    case '/':
        return true;
        break;

    default:
        return false;
        break;
    }
}

/**
 * @brief return if a char c is a operator like '^', '!' or '#'.
 * 
 * @param c <char> a char to analyze. 
 * @return true if it's a special operator,
 * @return false if it's not.
 */
bool IsASpecialOperator(char c){
    switch (c)
    {
    case '!':
        return true;
        break;
    case '^':
        return true;
        break;
    case '#':
        return true;
        break;

    default:
        return false;
        break;
    }
}

/**
 * @brief add to a vector type <double> every number find in a <string>.
 * 
 * @param Vnb <double> the vector where store every number.
 * @param chaine <string> the string to split.
 * @return true if the function find any number,
 * @return false if not.
 */
bool split_nb(vector<double>* Vnb,string chaine){
    string buff;
    bool check(false);
    double nb;
    for (size_t i = 0; i < chaine.size(); i++)
    {
        if (IsANumber(chaine.at(i)) or chaine.at(i)=='.')
        {
            buff.push_back(chaine.at(i));
            check=true;
        }else{
            if (check)
            {
                if(to_double(&nb,buff)){
                    Vnb->push_back(nb); 
                    buff.clear();
                    check=false;
                }else{
                    return false;
                }
            }
        }
    }
    if (!buff.empty())
    {
        if(to_double(&nb,buff)){
            Vnb->push_back(nb);
            buff.clear();
        }
    }
    return !Vnb->empty(); 
}

/**
 * @brief add to a vector type <char> every operator find a <string>. operator list : +, -, *, /, !, #, ^
 * 
 * @param op <char> the vector where store every operator finded .
 * @param chaine <string> the string to split.
 * @return true if the function find any operator,
 * @return false if not.
 */
bool split_op(vector<char>* op,string chaine){
    for (size_t i = 0; i < chaine.size(); i++)
    {
        if (IsAClassicOperator(chaine.at(i)) or IsASpecialOperator(chaine.at(i)))
        {
            op->push_back(chaine.at(i));
        }
    }
    return !op->empty();
}

/**
 * @brief Convert a <string> to <double>. Accept only number char and '.' for decimals. 
 * 
 * @param db <double> a variable where store the converted number.
 * @param str <string> the string to convert.
 * @return true if the function succeeded in converting,
 * @return false if not.
 */
bool to_double(double* db,string str){
    double size_int(0),tmp(0);
    if (str.empty())
    {
        return false;
    }
    //check every char is accepted
    
    if (!check_accepted_char(str,"0123456789."))
    {
        return false;
    }

    //delete useless 0 at the begin and the end of the chaine
    int ind(0);
    while (str.at(ind)=='0')
    {
        str.erase(str.begin());
    }
    ind=str.size()-1;
    while(str.at(ind)=='0')
    {
        str.erase(str.begin()+ind);
        --ind;
    }
    if(str.at(ind)=='.'){
        str.erase(str.begin()+ind);
    }
    //get integer part size
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i)=='.')
        {
            size_int=i;
            str.erase(str.begin()+i);
        }
    }
    //convert the string
    for (size_t i = 0; i < str.size(); i++)
    {
        switch (str.at(i))
        {
        case '0':
            //nothing to do
            break;
        case '1':
            tmp+=1*pow(10,str.size()-i-1);
            break;
        case '2':
            tmp+=2*pow(10,str.size()-i-1);
            break;
        case '3':
            tmp+=3*pow(10,str.size()-i-1);
            break;
        case '4':
            tmp+=4*pow(10,str.size()-i-1);
            break;
        case '5':
            tmp+=5*pow(10,str.size()-i-1);
            break;
        case '6':
            tmp+=6*pow(10,str.size()-i-1);
            break;
        case '7':
            tmp+=7*pow(10,str.size()-i-1);
            break;
        case '8':
            tmp+=8*pow(10,str.size()-i-1);
            break;
        case '9':
            tmp+=9*pow(10,str.size()-i-1);
            break;
        }
    }
    if (size_int>0)
    {
        *db=tmp/pow(10,str.size()-size_int);
    }else{
        *db=tmp;
    }

    return true;
}


string handle_overflow(string exp){
    //delete non accepted_char
    string accept_char="0123456789.()+-*/!#^";
    bool check(false);
    for (size_t i = 0; i < exp.size(); i++)
    {
        for (size_t j = 0; j < accept_char.size(); j++)
        {
            if (exp.at(i)==accept_char.at(j))
            {
                check=true;
            }
        }
        if (!check)
        {
            exp.erase(exp.begin()+i);
        }
        check=false;
    }

    //delete sequence of classic operator, not possible "2++4"
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (IsAClassicOperator(exp.at(i)) and IsAClassicOperator(exp.at(i+1)))
        {
            exp.erase(exp.begin()+i+1);
            --i;
        }
        if ((IsAClassicOperator(exp.at(i)) or IsASpecialOperator(exp.at(i))) and exp.at(i+1)=='.')
        {
            exp.insert(exp.begin()+i,'0');
        }
    }
    //delete double decimal "2.24.12"
    check=false;
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (exp.at(i)=='.' and check)
        {
            exp.erase(exp.begin()+i);
        }
        if (exp.at(i)=='.' and !check)
        {
            check=true;
        }
        if (IsAClassicOperator(exp.at(i)) or IsASpecialOperator(exp.at(i)) or exp.at(i)=='(' or exp.at(i)==')')
        {
            check=false;
        }
    }
    
    //parenthesis not open or not close
    int nb_parenth(0);
    vector<int> pos_parenth_open;
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (exp.at(i)=='(')
        {
            if (nb_parenth==0 or IsAClassicOperator(exp.at(i+1)))
            {
                //delete not opened parenthesis
                exp.erase(exp.begin()+i);
            }else{
                --nb_parenth;
                pos_parenth_open.pop_back();
            }
        }
        if (exp.at(i)==')')
        {
            ++nb_parenth;
        }
    }
    //delete closed parenthesis
    if (!pos_parenth_open.empty())
    {
        for (size_t i = 0; i < pos_parenth_open.size(); i++)
        {
            exp.erase(exp.begin()+i);
        }
        pos_parenth_open.clear();
    }
    
    return exp;
}

/**
 * @brief return a expression between parenthesis find in a <string>. from the first opened and finded parenthesis to its closed parenthesis.
 * 
 * @param str <string> the string to analyse
 * @return if parenthesis finded in the <string>, return the expression between this parenthesis, if no parenthesis finded, return the original <string>
 */
string ressearch_parenthese(string str){
    //check every char is accepted
    if (!check_accepted_char(str,"0123465789.+-*/!^#()"))
    {
        str=handle_overflow(str);
    }
    int  nb_parenthesis(0);
    bool start(false);
    string buff;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str.at(i)==')')
        {
            --nb_parenthesis;
        }
        if (nb_parenthesis>0)
        {
            buff.push_back(str.at(i));
        }
        if (str.at(i)=='(')
        {
            ++nb_parenthesis;
            start=true;
        }
        if (start and nb_parenthesis==0)
        {
            return buff;
        }
    }
    return str;
}

/**
 * @brief calculate the factorial of a number.
 * 
 * @param nb <double> the number for facotiral 
 * @return return the result of factorial(nb).
 */
double fact(double nb){
    if (nb<0)
    {
        return -1.0;
    }
    
    double buff=1;
    for (size_t i = 2; i <= nb; i++)
    {
        buff*=i;
    }
    return buff;
}

/**
 * @brief manage sequence of power like "2^2^2=2^4=16", calcul and arrange the vectors
 * 
 * @param nb a vector type <double> with every member of the calcul
 * @param op a vector type <char> with every operator of the calcul
 * @param index index of the first '^' finded.
 */
void manage_pow(vector<double> *nb,vector<char> *op,int index){
    if (index<op->size()-1)
    {
        if (op->at(index+1)=='^')
        {
            manage_pow(nb,op,index+1);
        }
    }
    nb->at(index)=pow(nb->at(index),nb->at(index+1));
    nb->erase(nb->begin()+index+1);
    op->erase(op->begin()+index);
}

double manage_fact(double nb,vector<char> *op,int index){
    if (index<op->size()-1 and op->at(index+1)=='!')
    {
        return fact(manage_fact(nb,op,index+1));
    }
    op->erase(op->begin()+index);
    return fact(nb);
}

double manage_sqrt(double nb,vector<char> *op,int index){
    if (index<op->size()-1 and op->at(index+1)=='#')
    {
        return sqrt(manage_sqrt(nb,op,index+1));
    }
    op->erase(op->begin()+index);
    return sqrt(nb);
}

bool check_accepted_char(string str, string accepted_char){
    bool check(false);
    for (size_t i = 0; i < str.size(); i++)
    {
        for (size_t j = 0; j < accepted_char.size(); j++)
        {
            if (str.at(i)==accepted_char.at(j))
            { 
                check=true;
            }
        }
        if (!check)
        {
            return false;
        }
        check=false;
    }
    return true;
}

/**
 * @brief main fonction,take a expression and make the calcul write in it.
 * 
 * @param exp <string> the expression with the calcul in.
 * @param tmp <double> a variable where store the result of the calcul.
 * @return true if the function succeed in calculating,
 * @return false if not.
 */
bool calculator(string exp,double *tmp){
    //check every char is accepted
    if (!check_accepted_char(exp,"0123465789.+-*/!^#()"))
    {
        exp=handle_overflow(exp);
    }
    string exp_new;
    exp_new=ressearch_parenthese(exp);
    if(exp!=exp_new)
    {    
        if(calculator(exp_new,tmp)){
            exp.replace(exp.find(exp_new)-1, exp_new.size()+2, to_string(*tmp));
        }else{
            return false;
        }
    }
    vector<double> nb;
    vector<char> op;
    split_nb(&nb,exp);
    split_op(&op,exp);
    for (size_t i = 0; i < op.size(); i++)
    {
        if (op.at(i)=='^')
        {
            manage_pow(&nb,&op,i);
            i-=0;
        }else if (op.at(i)=='!')
        {
            nb.at(i)=manage_fact(nb.at(i),&op,i);
            i-0;
        }else if (op.at(i)=='#')
        {
            manage_sqrt(nb.at(i),&op,i);
            i-=0;
        }
    }
    for (size_t i = 0; i < op.size(); i++)
    {
        if (op.at(i)=='*')
        {
            nb.at(i)=nb.at(i)*nb.at(i+1);
            nb.erase(nb.begin()+i+1);
            op.erase(op.begin()+i);
            i-=1;
        }else if (op.at(i)=='/')
        {
            nb.at(i)=nb.at(i)/nb.at(i+1);
            nb.erase(nb.begin()+i+1);
            op.erase(op.begin()+i);
            i-=1;
        }
    }
    for (size_t i = 0; i < op.size(); i++)
    {
        if (op.at(i)=='+')
        {
            nb.at(i)=nb.at(i)+nb.at(i+1);
            nb.erase(nb.begin()+i+1);
            op.erase(op.begin()+i);
            i-=1;
        }else if (op.at(i)=='-')
        {
            nb.at(i)=nb.at(i)-nb.at(i+1);
            nb.erase(nb.begin()+i+1);
            op.erase(op.begin()+i);
            i-=1;
        }
    }
    if(to_double(tmp,to_string(nb.at(0)))){
        return true;
    }
    return false;
}