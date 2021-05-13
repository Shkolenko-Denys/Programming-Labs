/*-------------------------------------------------------------------<Header>-
 Name: ex_21.cpp
 Title: —
 Description: На основе класса, созданного для преобразования футов в
 сантиметры, напишите пользовательскую функцию ввода, формирующую
 строку-приглашение для записи числа футов. Кроме этого, напишите
 пользовательскую функцию вывода для отображения на экране как числа футов, так
 и числа сантиметров. Включите указанные функции в программу и продемонстрируйте
 их работоспособность.
 class ft_to_cms {
     double feet;
     double cms;
 public:
     void set(double f) {
         feet = f;
         cms = f * 30.48;
     }
 };
 Примечание: Фут (обозначается как «ft») — единица измерения длины.
 Фут равен 0,3048 м и используется в английской системе мер и США.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstdlib>

using namespace std;

class ft_to_cms {
    double feet;
    double cms;
public:
    void set(double f = 0) {
        feet = f;
        cms = f * 30.48;
    }
    friend ostream& operator<< (ostream &out, const ft_to_cms &obj);
    friend istream& operator>> (istream &in, ft_to_cms &obj);
};

ostream& operator<< (ostream &out, const ft_to_cms &obj) {
    out << "ft: " << obj.feet << " ; cms: " << obj.cms << "\n\n";
    return out;
}

istream& operator>> (istream &in, ft_to_cms &obj) {
    cout << " Enter ft: ";
    in >> obj.feet;
    obj.cms = obj.feet * 30.48;
    return in;
}

int main() {
    ft_to_cms obj;
    cin >> obj;
    cout << obj;

     
    return 0;
}