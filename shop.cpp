#include <iostream>
#include <cstring>

class Product
{
public:
    char name[20];
    double price;
    // 7.
    Product() : price(0.0)
    {
        this->name[0] = '\0';
    }
    Product(const char* name, double price) : price{ price }
    {
        strncpy_s(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }
};
class Orders
{
private:
    // 1.
    char customer[20];
    char address[100];
    int orderNum;
public:
    // 1.
    static const int MaxProds = 20;
    Product products[MaxProds];
    int count;
    // 7.
    Orders(const char* cust, const char* adds, int order) : orderNum{ order }, count(0)
    {
        strncpy_s(customer, cust, sizeof(customer) - 1);
        customer[sizeof(customer) - 1] = '\0';
        strncpy_s(address, adds, sizeof(address) - 1);
        address[sizeof(address) - 1] = '\0';
    }
    // 2.
    void addProduct(const Product& newProd)
    {
        if (count < MaxProds)
        {
            products[count++] = newProd;
            std::cout << "Product successfuly added to order.";
        }
        else
        {
            std::cout << "Too many items in the order (Max: 20).";
        }
        std::cout << std::endl;
    }
    // 3.
    void deleteProduct(const char* prodName)
    {
        for (size_t i = 0; i < count; i++)
        {
            if (strcmp(products[i].name, prodName) == 0)
            {
                for (size_t j = i; j < count - 1; j++)
                {
                    products[j] = products[j + 1];
                }
                count--;
                std::cout << "Product " << prodName << " deleted from order.";
                std::cout << std::endl;
                return;
            }
        }
        std::cout << "Product " << prodName << " wasn't found.";
        std::cout << std::endl;
    }
    // 4.
    double orderPrice() const
    {
        double sum = 0.0;
        for (size_t i = 0; i < count; i++)
        {
            sum += products[i].price;
        }
        return sum;
    }
    // 5.
    void productsInfo() const
    {
        std::cout << "Products in the order:" << std::endl;
        for (size_t i = 0; i < count; i++)
        {
            std::cout << i + 1 << ") " << products[i].name << std::endl;
            std::cout << products[i].price << "$" << std::endl;
        }
        std::cout << "Total items: " << count << std::endl;
    }
    // 6.
    void orderInfo() const
    {
        std::cout << "Order info:" << std::endl;
        std::cout << "Customer name: " << customer << std::endl;
        std::cout << "Delivery address: " << address << std::endl;
        std::cout << "Order number: " << orderNum << std::endl;
        productsInfo();
        std::cout << "Total: " << orderPrice() << "$" << std::endl;
    }
};
// 8.
int main()
{
    Product prod1("Hoodie", 35.00);
    Product prod2("Headphones", 60.00);
    Product prod3("Book", 6.50);
    Product prod4("Lamp", 14.75);
    Orders order1("Yurii", "Odesa", 1);
    Orders order2("Stas", "Ivano-Frankisvk", 2);

    order1.addProduct(prod1);
    order1.addProduct(prod3);
    order2.addProduct(prod2);
    order2.addProduct(prod4);
    std::cout << "-----------------------\n";
    order1.productsInfo();
    std::cout << std::endl;
    order2.productsInfo();
    std::cout << "-----------------------\n";
    order2.deleteProduct("Powerbank");
    order2.deleteProduct("Lamp");
    std::cout << "-----------------------\n";
    order1.orderInfo();
    std::cout << std::endl;
    order2.orderInfo();
}



