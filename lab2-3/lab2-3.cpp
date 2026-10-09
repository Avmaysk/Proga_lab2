// Задание 3. Ввести класс E — Economy, P — Premium, B — Business и массу багажа. Через switch задать бесплатную норму 20, 25 и 32 кг. Каждый кг перевеса стоит 5. Багаж свыше 50 кг не принимается. Для неизвестного класса вывести ошибку. Вывести норму и доплату.

//

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char klass;         
    double mass;
    double norm;     
    double extra;   

  
    cout << "Введите класс (E - Economy, P - Premium, B - Business): ";
    cin >> klass;

    cout << "Введите массу багажа: ";
    cin >> mass;

    
    switch (klass) {
    case 'E':
    case 'e':
        norm = 20;
        break;
    case 'P':
    case 'p':
        norm = 25;
        break;
    case 'B':
    case 'b':
        norm = 32;
        break;
    default:
        cout << "Ошибка: неизвестный класс." << endl;
        return 0;
    }

   
    cout << "\n=== Решение ===" << endl;
    cout << "Бесплатная норма: " << norm << " кг" << endl;

   

    if (mass > 50) {
        cout << "Багаж не принимается (вес больше 50 кг)." << endl;
        cout << "Доплата не рассчитывается." << endl;
    }
    else {

        if (mass <= norm) {
            extra = 0;
        }
        else {
            extra = (mass - norm) * 5;
        }
        cout << "Доплата: " << extra << " руб." << endl;
    }

    return 0;
}