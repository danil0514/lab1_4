#include <iostream>
#include "DOT.h"
#include <vector>

using namespace std;

//логические функции программы
void displayArr(std::vector<DOT>&arr_value, int n) {
    DOT point_DOT;
    cout << "Номер   X старт   Y старт   X конец   Y конец" << endl;
    for (int i = 0; i < n; i++) {
        point_DOT = arr_value[i];
        cout <<"  " << i << "       " << point_DOT.Get_x_start() << "         " << point_DOT.Get_y_start() << "         " << point_DOT.Get_x_end() << "         " << point_DOT.Get_y_end() << endl;
    }
}


void add_arr_fun(std::vector<DOT>& arr_value, int n,int number_dot) {
    DOT point_ADD;
    number_dot = number_dot + n;
    system("cls");
    cout << "1) Вручную" << endl;
    cout << "2) Рандомно" << endl;
    int check_box_add;
    cin >> check_box_add;
    float x_s, y_s, x_e, y_e;
    switch (check_box_add)
    {case 1:
        for (int i = n; i < number_dot; i++)
        {
            cout << "Введите x начальной точки" << endl;
            cin >> x_s;
            system("cls");
            cout << "Введите y начальной точки" << endl;
            cin >> y_s;
            system("cls");
            cout << "Введите x конечной точки " << endl;
            cin >> x_e;
            system("cls");
            cout << "Введите y конечной точки" << endl;
            cin >> y_e;
            system("cls");
            point_ADD.set_data(x_s,y_s,x_e,y_e);
            arr_value.push_back(point_ADD);
        }
    case 2:
        for (int i = n; i < number_dot; i++)
        {
            x_s = static_cast <float>(rand()) / static_cast<float> (RAND_MAX / 10);
            y_s = static_cast <float>(rand()) / static_cast<float> (RAND_MAX / 10);
            x_e = static_cast <float>(rand()) / static_cast<float> (RAND_MAX / 10);
            y_e = static_cast <float>(rand()) / static_cast<float> (RAND_MAX / 10);
            system("cls");
            point_ADD.set_data(x_s, y_s, x_e, y_e);
            arr_value.push_back(point_ADD);
        }
    default:
        
        break;
    }
    
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int menu_token = 1;//токен для обработки действий в меню
    int amount_value_arr = 0;
    std::vector<DOT>arr_value;
    while (menu_token != 0) {
        cout << "1) Просмотр всех заданных векторов" << endl;
        cout << "2) Добавление векторов" << endl;
        cout << "3) Модуль вектора" << endl;
        cout << "4) Скалярное произведение" << endl;
        cout << "5) Сложение векторов" << endl;
        cout << "6) Вычитание векторов" << endl;
        cout << "7) Проверка на коллениарность векторов" << endl;
        cout << "8) Проверка на ортогональность векторов" << endl;
        cout << "0) Выход" << endl;
        cin >> menu_token;
        switch (menu_token)
        {
        case 1:
            system("cls");
            displayArr(arr_value, amount_value_arr);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "Сколько векторов вы хотите добавить ? " << endl;
            int number_dot;
            cin >> number_dot;
            add_arr_fun(arr_value, amount_value_arr,number_dot);
            amount_value_arr = amount_value_arr + number_dot;
            displayArr(arr_value, amount_value_arr);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            if (amount_value_arr == 0)
            {
                cout << "В данный момент нет векторов, для начала добавте их" << endl;
            }
            else
            {
                displayArr(arr_value, amount_value_arr);
                int number_vector_mod; // номер вектора 
                cout << "Введите номер вектора у которого хотите вычислить модуль" << endl;
                cin >> number_vector_mod;
                DOT time_p;
                time_p = arr_value[number_vector_mod];
                cout << "Модуль вектора равен: " << time_p.Modul_vector() << endl;
            }
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            if (amount_value_arr == 0)
            {
                cout << "В данный момент нет векторов, для начала добавте их" << endl;
            }
            else
            {
                displayArr(arr_value, amount_value_arr);
                int number_vector_one = amount_value_arr; // номер вектора 
                int number_vector_two = amount_value_arr;
                while (number_vector_one >= amount_value_arr) {
                    cout << "Введите номер вектора первого слогаемого для вычисления скалярное произведения" << endl;
                    cin >> number_vector_one;
                    if (number_vector_one >= amount_value_arr) {
                        cout << "Укажите номер в приделах от 0 до " << amount_value_arr << endl;
                    }
                }
                while (number_vector_two >= amount_value_arr) {
                    cout << "Введите номер вектора второго слогаемого для вычисления скалярное произведения" << endl;
                    cin >> number_vector_two;
                    if (number_vector_two >= amount_value_arr) {
                        cout << "Укажите номер в приделах от 0 до " << amount_value_arr << endl;
                    }
                }
                cout << "Скаляр вектора равен: " << arr_value[number_vector_one]* arr_value[number_vector_two] << endl;
            }
            system("pause");
            system("cls");
        case 6:
            // вычитание векторов
            system("cls");
            if (amount_value_arr == 0)
            {
                cout << "В данный момент нет векторов, для начала добавте их" << endl;
            }
            else
            {
                displayArr(arr_value, amount_value_arr);
                int number_vector_one = amount_value_arr; // номер вектора 
                int number_vector_two = amount_value_arr;
                while (number_vector_one >= amount_value_arr) {
                    cout << "Введите номер уменьшаемого " << endl;
                    cin >> number_vector_one;
                    if (number_vector_one >= amount_value_arr) {
                        cout << "Укажите номер в приделах от 0 до " << amount_value_arr << endl;
                    }
                }
                while (number_vector_two >= amount_value_arr) {
                    cout << "Введите номер вычитаемого " << endl;
                    cin >> number_vector_two;
                    if (number_vector_two >= amount_value_arr) {
                        cout << "Укажите номер в приделах от 0 до " << amount_value_arr << endl;
                    }
                }
                DOT sum_value;
                sum_value = arr_value[number_vector_one] + arr_value[number_vector_two];
                cout << "Разность векторов равена: x = " << sum_value.Get_x_end() << endl;
                cout << "                       y = " << sum_value.Get_y_end() << endl;
            }
            system("pause");
            system("cls");
        case 7:
            //коллинеарность 
            if (amount_value_arr == 0)
            {
                cout << "В данный момент нет векторов, для начала добавте их" << endl;
            }
            else
            {
                displayArr(arr_value, amount_value_arr);
                int number_vector_one = amount_value_arr; // номер вектора 
                int number_vector_two = amount_value_arr;
                while (number_vector_one >= amount_value_arr) {
                    cout << "Введите номер уменьшаемого " << endl;
                    cin >> number_vector_one;
                    if (number_vector_one >= amount_value_arr) {
                        cout << "Укажите номер в приделах от 0 до " << amount_value_arr << endl;
                    }
                }
                while (number_vector_two >= amount_value_arr) {
                    cout << "Введите номер вычитаемого " << endl;
                    cin >> number_vector_two;
                    if (number_vector_two >= amount_value_arr) {
                        cout << "Укажите номер в приделах от 0 до " << amount_value_arr << endl;
                    }
                }
                DOT sum_value;
                sum_value = arr_value[number_vector_one] + arr_value[number_vector_two];
                cout << "Разность векторов равена: x = " << sum_value.Get_x_end() << endl;
                cout << "                       y = " << sum_value.Get_y_end() << endl;
            }
            system("pause");
            system("cls");

        }
    }
}

