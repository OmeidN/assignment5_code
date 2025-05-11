#ifndef PRODUCT_H
	#define PRODUCT_H

	#include <string>
	#include <iostream>

	class Product {
		private:
			std::string name;
			std::string description;
			double rating;
			int soldCount;

		public:
			Product();
			Product(const std::string& name, const std::string& description, double rating, int soldCount);
			~Product();

			// Getters for member data fields
			std::string getName() const;
			std::string getDescription() const;
			double getRating() const;
			int getSoldCount() const;

			// Setters for member data fields
			void setName(const std::string& newName);
			void setDescription(const std::string& newDescription);
			void setRating(double newRating);
			void setSoldCount(int newSoldCount);

			// Sell a product
			void sell(int quantity);

			// == operator overload
			bool operator==(const Product& otherProduct) const;

			// Friend function to overload << operator
			friend std::ostream& operator<<(std::ostream& os, const Product& product);
	};

#endif 
