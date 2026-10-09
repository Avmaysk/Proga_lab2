// Ввести класс E/P/B, массу багажа, признак онлайн-регистрации и признак негабаритного багажа. Через switch задать норму 20/25/32 и стоимость кг перевеса 5/4/3. Онлайн-регистрация уменьшает только плату за перевес на 20%. Негабарит добавляет 15, но для Business этот сбор не взимается. При массе свыше 50 кг багаж не принимается и сборы не считаются. Вывести каждую составляющую и итог.
//

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char travelClass;
    double mass;
    int online;
    int oversized;
    double norm;
    double price;

    double overweight;
    double discount;
    double surcharge;
    double total;


    cout << "Введите класс (E/P/B): ";
    cin >> travelClass;

    cout << "Введите массу багажа: ";
    cin >> mass;

    cout << "Онлайн-регистрация? (1 - да, 0 - нет): ";
    cin >> online;

    cout << "Негабаритный багаж? (1 - да, 0 - нет): ";
    cin >> oversized;


    switch (travelClass) {
    case 'E':
    case 'e':
        norm = 20;
        price = 5;
        break;
    case 'P':
    case 'p':
        norm = 25;
        price = 4;
        break;
    case 'B':
    case 'b':
        norm = 32;
        price = 3;
        break;
    default:
        cout << "Ошибка: неизвестный класс." << endl;
        return 0;
    }


    cout << "\n=== Решение ===" << endl;
    cout << "Класс: " << travelClass << endl;
    cout << "Бесплатная норма: " << norm << " кг" << endl;
    cout << "Стоимость кг перевеса: " << price << " руб." << endl;


    if (mass > 50) {
        cout << "\nБагаж не принимается (вес больше 50 кг)." << endl;
        cout << "Сборы не рассчитываются." << endl;
        return 0;
    }


    if (mass > norm) {
        overweight = (mass - norm) * price;
    }
    else {
        overweight = 0;
    }
    cout << "\nПлата за перевес (до скидки): " << overweight << " руб." << endl;


    if (online == 1) {
        discount = overweight * 0.2;
    }
    else {
        discount = 0;
    }
    cout << "Скидка за онлайн-регистрацию (20%): -" << discount << " руб." << endl;


    if (oversized == 1) {
        if (travelClass == 'B' || travelClass == 'b') {
            surcharge = 0;
            cout << "Надбавка за негабарит: 0 руб. (для Business не взимается)" << endl;
        }
        else {
            surcharge = 15;
            cout << "Надбавка за негабарит: " << surcharge << " руб." << endl;
        }
    }
    else {
        surcharge = 0;
        cout << "Надбавка за негабарит: 0 руб. (багаж стандартный)" << endl;
    }


    total = overweight - discount + surcharge;
    cout << "\nИтоговая сумма к оплате: " << total << " руб." << endl;

    return 0;
}

