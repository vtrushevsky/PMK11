#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Product {

public:
    Product(string country, double price) : country_(country), price_(price) {}
    virtual ~Product() {}

    string country() const { return country_; }
    double price() const { return price_; }

private:
    string country_;
    double price_;

};

class Toy : public Product {

public:
    Toy(string country, double price, string name, int min_age, int max_age)
        : Product(country, price), name_(name), min_age_(min_age), max_age_(max_age) {}

    string name() const { return name_; }
    int min_age() const { return min_age_; }
    int max_age() const { return max_age_; }

private:
    string name_;
    int min_age_;
    int max_age_;

};

int main() {

    vector<Toy> recommended_toys;
    recommended_toys.push_back(Toy("US", 20.99, "Lego Set", 5, 12));
    recommended_toys.push_back(Toy("JP", 29.99, "Transformers", 7, 14));
    recommended_toys.push_back(Toy("CN", 14.99, "Rubik's Cube", 8, 99));
    recommended_toys.push_back(Toy("CN", 5.99, "Slinky", 3, 8));
    recommended_toys.push_back(Toy("US", 10.99, "Card Games", 10, 99));

    int min_age, max_age;
    double min_price, max_price;
    string input;
    cout << "Enter minimum age: ";
    getline(cin, input);
    min_age = stoi(input);
    cout << "Enter maximum age: ";
    getline(cin, input);
    max_age = stoi(input);
    cout << "Enter minimum price: ";
    getline(cin, input);
    min_price = stod(input);
    cout << "Enter maximum price: ";
    getline(cin, input);
    max_price = stod(input);

    cout << "Recommended toys:" << endl;

    for (auto& toy : recommended_toys) {

        if (toy.min_age() <= max_age && toy.max_age() >= min_age
            && toy.price() >= min_price && toy.price() <= max_price) {
            cout << toy.name() << " (age " << toy.min_age() << "-" << toy.max_age()
                << ", price " << toy.price() << ", country " << toy.country() << ")" << endl;
        }

    }




    return 0;
}