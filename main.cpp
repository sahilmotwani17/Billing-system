#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

    // Default constructor for reading from file
    Product() : id(0), name(""), price(0.0), quantity(0) {}

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

    // Function to save the product data to a file
    void saveToFile(ofstream& outFile) const {
        outFile << id << "\n" << name << "\n" << price << "\n" << quantity << "\n";
    }

    // Function to load product data from a file
    void loadFromFile(ifstream& inFile) {
        inFile >> id;
        inFile.ignore();  // Ignore the newline character after integer input
        getline(inFile, name);
        inFile >> price >> quantity;
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

// Function to save products to a file
void saveProductsToFile(const vector<Product>& products, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& product : products) {
            product.saveToFile(outFile);
        }
        outFile.close();
        cout << "Products saved to file.\n";
    } else {
        cout << "Error opening file for saving.\n";
    }
}

// Function to load products from a file
void loadProductsFromFile(vector<Product>& products, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        Product temp;
        while (inFile) {
            temp.loadFromFile(inFile);
            if (inFile) {  // Check if it's not the end of the file
                products.push_back(temp);
            }
        }
        inFile.close();
        cout << "Products loaded from file.\n";
    } else {
        cout << "Error opening file for loading.\n";
    }
}

int main() {
    vector<Product> products;
    string filename = "products.txt";  // File to store product data
    loadProductsFromFile(products, filename);  // Load existing products from file

    int choice;

    do {
        cout << "\nBilling System Menu:\n";
        cout << "1. Display Products\n";
        cout << "2. Add New Product\n";
        cout << "3. Generate Bill\n";
        cout << "4. Save Products to File\n";
        cout << "5. Exit\n";
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
                saveProductsToFile(products, filename);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
