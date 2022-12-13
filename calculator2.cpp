/*
compile command :
g++ .\fct_error.cpp .\calculator2.cpp -o ..\bin\calc.exe
*/

/**
 * TASK LIST :
 * + make_correctly_expression
 * + make function for  ^ ! #
 * + add verification of entry in every function
 * 
 * fonction test :
test IsANumber SUCCEEDED
test IsAClassicOperator SUCCEEDED
test IsASpecialOperator SUCCEEDED
test split_nb SUCCEEDED
test split_op SUCCEEDED
test to_double SUCCEEDED
test fact SUCCEEDED
test manage_pow FAILED : 9
test make_correctly_expression FAILED : =>
test ressearch_parenthese SUCCEEDED
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 6) >= this->size() (which is 3)
 * 
 * op : + - * /  ! ^ # 
 * english notation : 128.51 . => decimal not ,
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
bool to_double(string chaine,double* nb);
double fact(double nb);
void manage_pow(vector<double> *nb,vector<char> *op,int index);

string make_correctly_expression(string exp);
string ressearch_parenthese(string chaine);
bool calculator(string exp,double* buff);

int main(int argc, char const *argv[])
{
    double tmp_db;
    string tmp_str;

    //TEST IsANumber
    string test("10^5+(!(2.5-!!3)+#4)*5^2/(#6.2*!7)+!8+9");
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
    split_nb(&nb,test);
    if (nb.size()==11)
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
    double tmp(10);
    to_double(to_string(tmp),&tmp_db);
    tmp_db-=2;
    if (tmp_db==tmp-2)
    {
        cout<<"test to_double SUCCEEDED" <<endl;
    }else{
        cout<<"test to_double FAILED : "<<tmp<<"-2="<<tmp_db<<endl;
    }

    //TEST fact
    tmp_db=fact(5);
    if (tmp_db==120)
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
    vnb.push_back(2);
    vector<char> vchar;
    vchar.push_back('^');
    vchar.push_back('^');
    vchar.push_back('^');
    manage_pow(&vnb,&vchar,0);
    if (vnb.at(0)==43046721)
    {
        cout<<"test manage_pow SUCCEEDED" <<endl;
    }else{
        cout<<"test manage_pow FAILED : "<<vnb.at(0)<<endl;
    }

    //TEST make_correctly_expression
    string exp("");
    tmp_str=make_correctly_expression(exp);
    if (tmp_str==test)
    {
        cout<<"test make_correctly_expression SUCCEEDED" <<endl;
    }else{
        cout<<"test make_correctly_expression FAILED : "<<exp<<"=>"<<tmp_str<<endl;
    }
    

    //TEST ressearch_parenthese
    tmp_str=ressearch_parenthese(test);
    if (tmp_str=="(!(2.5-!!3)+#4)")
    {
        cout<<"test ressearch_parenthese SUCCEEDED"<<endl;
    }else{
        cout<<"test ressearch_parenthese FAILED : "<<tmp_str<<endl;
    }

    //TEST calculator
    calculator(test,&tmp_db);
    if (tmp_db==5)
    {
        cout<<"test calculator SUCCEEDED" <<endl;
    }else{
        cout<<"test calculator FAILED : "<<test<<"="<<tmp_db<<endl;
    }

    return 0;
}


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
                if(to_double(buff,&nb)){
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
        if(to_double(buff,&nb)){
            Vnb->push_back(nb);
            buff.clear();
        }
    }
    return !Vnb->empty(); 
}

//pas de parenthese dans @chaine
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

bool to_double(string chaine,double* nb){
    double length(0),tmp(0);
    if (chaine.empty())
    {
        return false;
    }
    //delete useless 0 at the begin and the end of the chaine
    int ind(0);
    while (chaine.at(ind)=='0')
    {
        chaine.erase(chaine.begin());
        ++ind;
    }
    ind=chaine.size()-1;
    while(chaine.at(ind)=='0')
    {
        chaine.erase(chaine.begin()+ind);
        --ind;
    }
    if(chaine.at(ind)=='.'){
        chaine.erase(chaine.begin()+ind);
    }

    for (size_t i = 0; i < chaine.size(); i++)
    {
        //check elt is accepted char
        if (!(IsANumber(chaine.at(i)) or chaine.at(i)=='.'))
        {
            return false;
        }
        //get integer part length
        if (chaine.at(i)=='.')
        {
            length=i;
        }
    }
    //convert the string
    for (size_t i = 0; i < chaine.size(); i++)
    {
        switch (chaine.at(i))
        {
        case '0':
            //nothing to do
            break;
        case '1':
            tmp+=1*pow(10,chaine.size()-1-i-length);
            break;
        case '2':
            tmp+=2*pow(10,chaine.size()-1-i-length);
            break;
        case '3':
            tmp+=3*pow(10,chaine.size()-1-i-length);
            break;
        case '4':
            tmp+=4*pow(10,chaine.size()-1-i-length);
            break;
        case '5':
            tmp+=5*pow(10,chaine.size()-1-i-length);
            break;
        case '6':
            tmp+=6*pow(10,chaine.size()-1-i-length);
            break;
        case '7':
            tmp+=7*pow(10,chaine.size()-1-i-length);
            break;
        case '8':
            tmp+=8*pow(10,chaine.size()-1-i-length);
            break;
        case '9':
            tmp+=9*pow(10,chaine.size()-1-i-length);
            break;
        }
    }
    *nb=tmp;
    //retour de convertion reussi
    return true;
}

string make_correctly_expression(string exp){
    return exp;
}

string ressearch_parenthese(string chaine){
    int  nb_parenthesis(0);
    bool start(false);
    string buff;
    for (size_t i = 0; i < chaine.size(); i++)
    {
        if (chaine.at(i)=='(')
        {
            ++nb_parenthesis;
            start=true;
        }
        if (nb_parenthesis>0)
        {
            buff.push_back(chaine.at(i));
        }
        if (chaine.at(i)==')')
        {
            --nb_parenthesis;
        }
        if (start and nb_parenthesis==0)
        {
            return buff;
        }
    }
    return buff;
}

bool calculator(string exp,double *buff){
    exp=make_correctly_expression(exp);
    string exp_new;
    exp_new=ressearch_parenthese(exp);
    if (exp!=exp_new)
    {
        exp.replace(exp.find(exp_new)-1, exp_new.size()+2, to_string(calculator(exp_new,buff)));
    }
    vector<double> nb;
    vector<char> op;
    split_nb(&nb,exp);
    split_op(&op,exp);

    for (size_t i = 0; i < op.size(); i++)
    {
        if (op.at(i)=='^')
        {
            nb.at(i)=pow(nb.at(i),nb.at(i+1));
            nb.erase(nb.begin()+i+1);
            op.erase(op.begin()+i);
            i-=1;
        }else if (op.at(i)=='!')
        {
            nb.at(i)=fact(nb.at(i));
            op.erase(op.begin()+i);
            i-=1;
        }else if (op.at(i)=='#')
        {
            nb.at(i)=sqrt(nb.at(i));
            op.erase(op.begin()+i);
            i-=1;
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
    if (nb.size()!=1)
    {
        return false;
    }
    if(to_double(to_string(nb.at(0)),buff)){
        return true;
    }
    return false;
}

double fact(double nb){
    double buff=1;
    for (size_t i = 2; i <= nb; i++)
    {
        buff*=i;
    }
    return buff;
}

void manage_pow(vector<double> *nb,vector<char> *op,int index){
    print(0);
    if (index<op->size()-1)
    {
        if (op->at(index+1)=='^')
        {
            manage_pow(nb,op,index+1);
        }
    }
    for (size_t i = 0; i < nb->size(); i++)
    {
        cout<<"=>"<<nb->at(i)<<endl;;
    }
    
    print(1);
    nb->at(index)=pow(nb->at(index),nb->at(index+1));
    nb->erase(nb->begin()+index+1);
    op->erase(op->begin()+index);
}

/*
if (!(IsANumber(chaine.at(i)) or IsAClassicOperator(chaine.at(i)) or IsASpecialOperator(chaine.at(i)) or chaine.at(i)=='.'))
        {
            return false;
        }
*/