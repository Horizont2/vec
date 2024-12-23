#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Product {
public:
    string name;
    string category;
    double price;
    int stock;

    Product(string n, string c, double p, int s) : name(n), category(c), price(p), stock(s) {}
};

int main() {
    vector<Product> products = {
        Product("Laptop", "Electronics", 1200.0, 15),
        Product("Smartphone", "Electronics", 800.0, 8),
        Product("Headphones", "Electronics", 150.0, 20),
        Product("Table", "Furniture", 100.0, 5),
        Product("Chair", "Furniture", 50.0, 30)
    };

    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.price < b.price;
    });

    cout << "Продукти відсортовані за ціною:" << endl;
    for (const Product& prod : products) {
        cout << prod.name << " - $" << prod.price << endl;
    }

    cout << "\nПродукти з низьким запасом:" << endl;
    for_each(products.begin(), products.end(), [](const Product& prod) {
        if (prod.stock < 10) {
            cout << prod.name << " - Запас: " << prod.stock << endl;
        }
    });

    string category = "Electronics";
    double totalPrice = 0;
    int count = 0;
    for_each(products.begin(), products.end(), [&totalPrice, &count, category](const Product& prod) {
        if (prod.category == category) {
            totalPrice += prod.price;
            count++;
        }
    });

    if (count > 0) {
        double averagePrice = totalPrice / count;
        cout << "\nСередня ціна продуктів у категорії '" << category << "': $" << averagePrice << endl;
    } else {
        cout << "\nПродукти у категорії '" << category << "' не знайдені." << endl;
    }

    double totalValue = accumulate(products.begin(), products.end(), 0.0, [](double sum, const Product& prod) {
        return sum + (prod.price * prod.stock);
    });

    cout << "\nЗагальна вартість всіх продуктів на складі: $" << totalValue << endl;

    return 0;
}
