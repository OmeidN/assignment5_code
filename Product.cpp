#include "Product.h"

// Constructor
Product::Product(){}

Product::Product(const std::string& name, const std::string& description, double rating, int soldCount)
    : name(name), description(description), rating(rating), soldCount(soldCount) {}

Product::~Product(){}

// Getters for member data fields
std::string Product::getName() const {
    return name;
}

std::string Product::getDescription() const {
    return description;
}

double Product::getRating() const {
    return rating;
}

int Product::getSoldCount() const {
    return soldCount;
}

// Setters for member data fields
void Product::setName(const std::string& newName) {
    name = newName;
}

void Product::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Product::setRating(double newRating) {
    rating = newRating;
}

void Product::setSoldCount(int newSoldCount) {
    soldCount = newSoldCount;
}

// Member function
void Product::sell(int quantity) {
    soldCount += quantity;
}

// == operator overload
bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << "Product Name: " << product.name << "\n"
       << "Description: " << product.description << "\n"
       << "Rating: " << product.rating << "\n"
       << "Number of Sold Items: " << product.soldCount << "\n";
    return os;
}
