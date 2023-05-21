#include "DOT.h"
#include <cmath>
#include <iostream>

using namespace std;

DOT::DOT()
{
    x_start = y_start = x_end = y_end = 0;
}
void DOT::set_data(float x_value_start, float y_value_start, float x_value_end, float y_value_end)
{
    x_start = x_value_start;
    y_start = y_value_start;
    x_end = x_value_end;
    y_end = y_value_end;
}
//базовые 


float DOT::Get_x_start() const
{
    return x_start;
}
float DOT::Get_y_start() const
{
    return y_start;
}
float DOT::Get_x_end() const
{
    return x_end;
}
float DOT::Get_y_end() const
{
    return y_end;
}

float DOT::Modul_vector()
{
    float l_x = 0.0;
    float l_y = 0.0;
    if (x_start>x_end)
    {
        l_x = x_start - x_end;
    }
    else
    {
        l_x = x_end - x_start;
    }
    if (y_start > y_end)
    {
        l_y = y_start - y_end;
    }
    else
    {
        l_y = y_end - y_start;
    }
    return sqrt(l_x*l_x+l_y*l_y) ;
}

float& DOT::operator*(const DOT A)
{
    float vec_dot;
    vec_dot = (x_end - x_start) * (A.x_end-A.x_start)+(y_start-y_end)*(A.y_end-A.y_start);
    return(vec_dot);
}

DOT& DOT::operator+(const DOT A)
{
    DOT vec_dot;
    float x_last, y_last;
    x_last = x_end + (A.x_end-A.x_start);
    y_last = y_end + (A.y_end - A.y_start);
    vec_dot.set_data(x_start,y_start,x_last,y_last);
    return(vec_dot);
}

DOT& DOT::operator-(const DOT A)
{
    DOT vec_dot;
    float x_last, y_last;
    x_last = x_end + (A.x_end - A.x_start)*-1;
    y_last = y_end + (A.y_end - A.y_start)*-1;
    vec_dot.set_data(x_start, y_start, x_last, y_last);
    return(vec_dot);
}

void DOT::coleniarn(DOT A, DOT B)
{
    float x_s, x_e, y_s, y_e;
    x_s = A.x_start / B.x_start;
    x_e = A.x_end / B.x_end;
    y_s = A.y_start / B.y_start;
    y_e = A.y_end / B.y_end;
    if (x_s == x_e == y_s == y_e) {
        cout << "Вектора коллинеарны" << endl;
    }
    else
    {
        cout << "Вектора не коллинеарны" << endl;
    }
}

bool DOT::zero_vector(DOT A, DOT B)
{
    float check_not_zero_one, check_not_zero_two;
    check_not_zero_one = A.x_start - A.x_end - A.y_start - A.y_end;
    check_not_zero_two = B.x_start - B.x_end - B.y_start - B.y_end;
    bool main_bool;
    {
        cout << "Первый вектор нулевой он не может быть коллинеарный " << endl;
        main_bool = 0;
    }
    if (check_not_zero_two == 0)
    {
        cout << "Второй вектор нулевой он не может быть коллинеарный " << endl;
        main_bool = 0;
    }
    return(main_bool);
}




