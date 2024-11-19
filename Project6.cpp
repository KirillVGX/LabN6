#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addProduct(vector<string>& names, vector<int>& quantities, vector<double>& prices) {
    string name;
    int quantity;
    double price;

    cout << "Введіть назву товару: ";
    cin >> name;
    cout << "Введіть кількість: ";
    cin >> quantity;
    cout << "Введіть ціну: ";
    cin >> price;

    names.push_back(name);
    quantities.push_back(quantity);
    prices.push_back(price);

    cout << "Товар додано!\n";
}

void removeProduct(vector<string>& names, vector<int>& quantities, vector<double>& prices) {
    string name;
    cout << "Введіть назву товару для видалення: ";
    cin >> name;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            names.erase(names.begin() + i);
            quantities.erase(quantities.begin() + i);
            prices.erase(prices.begin() + i);
            cout << "Товар видалено!\n";
            return;
        }
    }

    cout << "Товар не знайдено.\n";
}

void updateQuantity(vector<string>& names, vector<int>& quantities) {
    string name;
    int newQuantity;

    cout << "Введіть назву товару для оновлення: ";
    cin >> name;
    cout << "Введіть нову кількість: ";
    cin >> newQuantity;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            quantities[i] = newQuantity;
            cout << "Кількість оновлено!\n";
            return;
        }
    }

    cout << "Товар не знайдено.\n";
}

void showProducts(const vector<string>& names, const vector<int>& quantities, const vector<double>& prices) {
    if (names.empty()) {
        cout << "Склад порожній.\n";
        return;
    }

    cout << "Товари на складі:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "Назва: " << names[i]
             << ", Кількість: " << quantities[i]
             << ", Ціна: " << prices[i] << "\n";
    }
}

void calculateTotalValue(const vector<int>& quantities, const vector<double>& prices) {
    double totalValue = 0;

    for (size_t i = 0; i < quantities.size(); ++i) {
        totalValue += quantities[i] * prices[i];
    }

    cout << "Загальна вартість товарів на складі: " << totalValue << "\n";
}

int main() {
    vector<string> productNames;
    vector<int> productQuantities;
    vector<double> productPrices;

    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати товар\n";
        cout << "2. Видалити товар\n";
        cout << "3. Оновити кількість товару\n";
        cout << "4. Показати всі товари\n";
        cout << "5. Розрахувати загальну вартість\n";
        cout << "6. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            addProduct(productNames, productQuantities, productPrices);
        } else if (choice == 2) {
            removeProduct(productNames, productQuantities, productPrices);
        } else if (choice == 3) {
            updateQuantity(productNames, productQuantities);
        } else if (choice == 4) {
            showProducts(productNames, productQuantities, productPrices);
        } else if (choice == 5) {
            calculateTotalValue(productQuantities, productPrices);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Некоректний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
