#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class definition for Product
class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    // Constructor to initialize product
    Product(int id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    // Getter functions for product details
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Function to display the product
    void displayProduct() const {
        cout << "ID: " << id << "\tName: " << name << "\tPrice: " << price << "\tQuantity: " << quantity << endl;
    }

    // Function to update the quantity of the product
    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    // Function to calculate the total price for a product (price * quantity)
    double calculateTotal() const {
        return price * quantity;
    }
};

// Function to display all products
void displayProducts(const vector<Product>& products) {
    cout << "\nDisplaying all available products:\n";
    cout << "-------------------------------------------------------------\n";
    for (const auto& product : products) {
        product.displayProduct();
    }
}

// Function to add a new product
void addProduct(vector<Product>& products) {
    int id, quantity;
    string name;
    double price;

    cout << "Enter product ID: ";
    cin >> id;
    cin.ignore();  // To clear the newline character left in the buffer

    cout << "Enter product name: ";
    getline(cin, name);

    cout << "Enter product price: ";
    cin >> price;

    cout << "Enter product quantity: ";
    cin >> quantity;

    products.push_back(Product(id, name, price, quantity));
    cout << "Product added successfully!\n";
}

// Function to generate bill (calculate total for all products)
void generateBill(const vector<Product>& products) {
    double grandTotal = 0;
    cout << "\nGenerating Bill:\n";
    cout << "-------------------------------------------------------------\n";
    for (const auto& product : products) {
        double total = product.calculateTotal();
        cout << "Product: " << product.getName() << "\tQuantity: " << product.getQuantity() << "\tTotal: " << total << endl;
        grandTotal += total;
    }
    cout << "-------------------------------------------------------------\n";
    cout << "Grand Total: " << grandTotal << endl;
}

int main() {
    vector<Product> products;
    int choice;

    do {
        cout << "\nBilling System Menu:\n";
        cout << "1. Display Products\n";
        cout << "2. Add New Product\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(products);
                break;
            case 2:
                addProduct(products);
                break;
            case 3:
                generateBill(products);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
