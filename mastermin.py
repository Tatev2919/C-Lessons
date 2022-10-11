#!/usr/bin/python3

class Category:
	category_id = 0
	
	def __init__(self, category_name, category_desc = ''):
		self.category_name = category_name
		self.category_desc = category_desc
		self.category_id  = Category.category_id
		Category.category_id += 1

	def __str__(self):
		return f' Category name is : {self.category_name} \n  Category desc is: {self.category_desc} \n Category id is: Categoty.category_id'

category1 = Category("Clothes")

category_arr = [category1] 
print(category1)

class Product:
	product_id = 0

	def __init__(self, product_category, product_name, product_unit, product_price,product_cost,product_date,product_desc=''):
		self.product_category = product_category
		self.product_name = product_name
		self.product_unit = product_unit
		self.product_price = product_price
		self.product_cost = product_cost
		self.product_date = product_date
		self.product_desc = product_desc
		Product.product_id+=1
	
	def __str__(self):
		return f' Product category is : {self.product_category} \n Product name is : {self.product_name} \n Product unit is : {self.product_unit} \n  Product price is : {self.product_price} \n Product cost is : {self.product_cost} \n Product date is : {self.product_date} \n Product desc is: {self.product_desc} \n Product id is : {Product.product_id} '

product1 = Product("Clothes","T_shirt",2,200,150,"15.05")
product_arr = [product1]
print("------------------------")
print(product1)

class Person:
	
	def __init__(self, name, surname, address, city, phone ):
		self.name = name
		self.surname = surname
		self.address = address
		self.city = city
		self.phone = phone

class Courier(Person):
	courier_id = 0

	def __init__(self, name,  surname, address, city, phone):
		super().__init__( name , surname, address, city, phone)
		Courier.courier_id+=1
	def __str__(self):
		return f'Courier name is: {self.name}\n Courier surname is: {self.surname}\nCourier address is: {self.address}\nCourier city is: {self.city}\nCourier phone is: {self.phone}\nCourier id is: {Courier.courier_id}'	

courier1 = Courier("Arman","Mkoyan","15st 14h","Yerevan","094444444")
courier_arr = [courier1]
print("Couriers--------------")
print(courier1)

class Supplier(Person):
	supplier_id = 0

	def __init__(self, name,  surname, address, city, phone,company):
		super().__init__(name ,  surname, address, city, phone)
		self.company=company
		Supplier.supplier_id+=1
	
	def __str__(self):
		return f'Supplier name is: {self.name}\n Supplier surname is: {self.surname}\nSupplier address is: {self.address}\nSupplier city is: {self.city}\nSupplier phone is: {self.phone}\nSupplier id is: {Supplier.supplier_id}\nSuppli'	


supplier1 = Supplier("Armen","Harutyunyan","14st 14h","Gyumri","095555555","4u")

print("Suppliers--------------")
supplier_arr = [supplier1]
print(supplier1)
	
class Function():
	@staticmethod

	def for_print(x):
		print()
		print("Please choose an action")
		print()
		choice = input("Action Id is:")
		return choice		

class Product_management:
	cash =100000
	password = "hello"
	login = "manager"

	@staticmethod
	def add_product():	
		new_product = Product(input("Category: "),input("Name of product: "), int(input("Unit:")), int(input("Price:")), int(input("Cost:")),input("Date: "),input("Description: "))
		product_arr.append(new_product)
		Product_management.cash-=new_product.product_price*new_product.product_unit

	@staticmethod
	def add_category():
		new_category = Category(input("Category name: "),input("Category description: "))
		category_arr.append(new_category)
			
Product_management.add_product()
Product_management.add_category()
for i in product_arr:
	print(i)
	print("--------------------------")

for i in category_arr:
	print(i)
	print("--------------------------")
