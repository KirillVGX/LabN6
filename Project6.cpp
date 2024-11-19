#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addProduct(vector<string>& names, vector<int>& quantities, vector<double>& prices) {
    string name;
    int quantity;
    double price;

    cout << "������ ����� ������: ";
    cin >> name;
    cout << "������ �������: ";
    cin >> quantity;
    cout << "������ ����: ";
    cin >> price;

    names.push_back(name);
    quantities.push_back(quantity);
    prices.push_back(price);

    cout << "����� ������!\n";
}

void removeProduct(vector<string>& names, vector<int>& quantities, vector<double>& prices) {
    string name;
    cout << "������ ����� ������ ��� ���������: ";
    cin >> name;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            names.erase(names.begin() + i);
            quantities.erase(quantities.begin() + i);
            prices.erase(prices.begin() + i);
            cout << "����� ��������!\n";
            return;
        }
    }

    cout << "����� �� ��������.\n";
}

void updateQuantity(vector<string>& names, vector<int>& quantities) {
    string name;
    int newQuantity;

    cout << "������ ����� ������ ��� ���������: ";
    cin >> name;
    cout << "������ ���� �������: ";
    cin >> newQuantity;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            quantities[i] = newQuantity;
            cout << "ʳ������ ��������!\n";
            return;
        }
    }

    cout << "����� �� ��������.\n";
}

void showProducts(const vector<string>& names, const vector<int>& quantities, const vector<double>& prices) {
    if (names.empty()) {
        cout << "����� �������.\n";
        return;
    }

    cout << "������ �� �����:\n";
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "�����: " << names[i]
            << ", ʳ������: " << quantities[i]
            << ", ֳ��: " << prices[i] << "\n";
    }
}

void calculateTotalValue(const vector<int>& quantities, const vector<double>& prices) {
    double totalValue = 0;

    for (size_t i = 0; i < quantities.size(); ++i) {
        totalValue += quantities[i] * prices[i];
    }

    cout << "�������� ������� ������ �� �����: " << totalValue << "\n";
}

int main() {
    vector<string> productNames;
    vector<int> productQuantities;
    vector<double> productPrices;

    int choice;

    while (true) {
        cout << "\n����:\n";
        cout << "1. ������ �����\n";
        cout << "2. �������� �����\n";
        cout << "3. ������� ������� ������\n";
        cout << "4. �������� �� ������\n";
        cout << "5. ����������� �������� �������\n";
        cout << "6. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        if (choice == 1) {
            addProduct(productNames, productQuantities, productPrices);
        }
        else if (choice == 2) {
            removeProduct(productNames, productQuantities, productPrices);
        }
        else if (choice == 3) {
            updateQuantity(productNames, productQuantities);
        }
        else if (choice == 4) {
            showProducts(productNames, productQuantities, productPrices);
        }
        else if (choice == 5) {
            calculateTotalValue(productQuantities, productPrices);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "����������� ����. ��������� �� ���.\n";
        }
    }

    return 0;
}