#!/usr/bin/python3

class Category:
	category_id = 0
	
	def __init__(self, category_name, category_desc = ''):
		self.category_name = category_name
		self.category_desc = category_desc
		self.category_id  = Category.category_id
		Category.category_id += 1

	def __str__(self):
		return f' Category name is : {self.category_name} \n  Category desc is: {self.category_desc} \n Category id is: {Category.category_id}'

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
product2 = Product("Clothes","Hudi",5,100,50,"15.06")
product3 = Product("Clothes","Shoes",2,150,150,"10.02")
product_arr = [product1,product2,product3]
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
		return f'Supplier name is: {self.name}\n Supplier surname is: {self.surname}\nSupplier address is: {self.address}\nSupplier city is: {self.city}\nSupplier phone is: {self.phone}\nSupplier id is: {Supplier.supplier_id}'	


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
		return "Smt"

	@staticmethod
	def add_category():
		new_category = Category(input("Category name: "),input("Category description: "))
		category_arr.append(new_category)
		return "Smt"
	
	@staticmethod
	def sell_product():

		while(True):
			sold_product = input("Input name of product to sell: ")
			sold_quantity = int(input("Enter quantity of product: "))
			for i in product_arr:
				if i.product_name==sold_product:
					if i.product_unit >=sold_quantity:
						i.product_unit-=sold_quantity
						Product_management.cash+= i.pruduct_price*sold_quantity
						return "smt"
					else:
						return "st"
				elif i==product_arr[-1]:
					print("There is no enough product")
					return "Smt"
			again= ("Please enter 1 if you want to sell one more thing")
			if (again==0):
				return "Smt"	
	@staticmethod
	def check_cash():
		return Product_management.cash
	
	@staticmethod
	def show_array(choice):
		array = []
		if choice==1:
			array=product_arr
		elif choice==2:
			array=category_arr
		elif choice==3:
			array=supplier_arr
		elif choice==4:
			array=courier_arr
		else:
			print("Your choice is not correct")
		
		for i in array:
			print(i)
			print("------------")
			
	@staticmethod 
	def del_product(name):
		for i in product_arr:
			if name in i:
				product_arr.remove(i)

	@staticmethod
	def add_remove_courier(choice):
		
		if choice==1:
			new_courier = Courier(input("Name: "),input("Surname: "), input("Address:"), input("City:"), input("Phone:"))
			courier_arr.appand(new_courier)
		elif choice==2:
			name_cour = (input("Name: "))
			for i in courier_arr:
				if i.name==name_cour:
					courier_arr.remove(i)
	
	@staticmethod
	def add_remove_supplier(choice):
		if choice==1:
			new_supplier = Supplier(input("Name: "),input("Surname: "), input("Address:"), input("City:"), input("Phone:"),input("Company"))
			supplier_arr.append(new_supplier)
		elif choice==2:
			name_suppl = (input("Name: "))	
			for i in supplier_arr:
				if i.name==name_suppl:
					supplier_arr.remove(i)
	
				
			
#Product_management.add_product()
#Product_management.add_category()
for i in product_arr:
	print(i)
	print("--------------------------")

#for i in category_arr:
#	print(i)
#	print("--------------------------")
#Product_management.sell_product()

class Payment:
	payment_id = 0
	
	def __init__ (self):
		self.payment_type = 'Cash'
		self.payment_id = Payment.payment_id;
		Payment.payment_id+=1

	def __str__(self):
		return f'payement type is {self.payment_type}\n Payment_if is: {Payment.payment_id}'


class CardPayment:

	def __init__ (self, card_type, card_number, cardholder_name,card_mm_yy,card_cvv):
		self.payment_type = 'Card'
		self.card_type = card_type
		self.card_number = card_number;
		self.cardholder_name =  cardholder_name;
		self.card_mm_yy = card_mm_yy;
		self.card_cvv = card_cvv;
		self.payment_id = Payment.payment_id;
		Payment.payment_id+=1

	def __str__(self):
		return f'Payment type is {self.payment_type}\nCard_type is {self.card_type}\nCard_number is {self.card_number}\nCard holder is {self.cardholder_name}\nCard date is { self.card_mm_yy}\nCard CVV is { self.card_cvv}\nPayment_id is: {Payment.payment_id}'

card1 = CardPayment("Master","4875478411112545","SUREN GHARIBYAN","04/25","888")

card_arr = [card1]
print(card1)


class OrderConstuctor:
	shopping_bag = {}
	chosen_product = {}
	total_amount = {}

	def __init__(self,product,count):
		self.product=product
		self.count = count

	def add_product_to_order(self):
		for prod in product_arr:
			if (prod.product_name==self.product) and (prod.product_unit>=self.count):
				OrderConstuctor.shopping_bag[self.product] = self.count
				OrderConstuctor.chosen_product[self.product] = self.count
				OrderConstuctor.total_amount[self.product] = [prod.product_price,  self.count]
				return OrderConstuctor.shopping_bag
			elif prod == product_arr[-1]:
				print("There is no such product (") 
				return

	@staticmethod
	def remove_product_from_order():
		product_remove = input("What product do you want to remove ? ")
		if product_remove in  OrderConstuctor.shopping_bag.keys():
			del OrderConstuctor.shopping_bag[product_remove]
			del OrderConstuctor.total_amount[product_remove]
			print(OrderConstuctor.shopping_bag)
			return OrderConstuctor.shopping_bag
		else:
			print("There is no such product in your shopping bag")

	@staticmethod
	def reduce_quantity():
		product_red = input("What product do you want to reduce ? ")
		product_count = int(input("Reduce until: "))
		if product_red in  OrderConstuctor.shopping_bag.keys():
			if product_count<  OrderConstuctor.shopping_bag[product_red]:
				print(OrderConstuctor.total_amount)
				OrderConstuctor.shopping_bag[product_red]-= product_count
				OrderConstuctor.total_amount[product_red][1] = OrderConstuctor.shopping_bag[product_red]
				print(OrderConstuctor.shopping_bag)
				print(OrderConstuctor.total_amount)
				return OrderConstuctor.shopping_bag
			elif  product_count == OrderConstuctor.shopping_bag[product_red]:
				del OrderConstuctor.shopping_bag[product_remove]
				del OrderConstuctor.total_amount[product_remove]
				print(OrderConstuctor.shopping_bag)
				return OrderConstuctor.shopping_bag	
			else:
				print("There is no so many items!")
		else:	
			print("There is no such product in your shopping bag")
	
	@staticmethod
	def add_quantity():
		product_add = input("What product do you want to add ? ")
		product_count = int(input("Add until: "))		
		
		if product_add in  OrderConstuctor.shopping_bag.keys():
			for i in product_arr:
				if i.product_name == product_add:
					if (product_count+OrderConstuctor.shopping_bag[product_add])<= i.product_unit:
						OrderConstuctor.shopping_bag[product_add]+= product_count
						OrderConstuctor.total_amount[product_add][1] = OrderConstuctor.shopping_bag[product_add]
						print(OrderConstuctor.shopping_bag)
						print(OrderConstuctor.total_amount)
						return OrderConstuctor.shopping_bag
					else:
						print("There is no so many items!")
		else:
			print("There is no such product in your shopping bag")


order1 = OrderConstuctor("Hudi",4)
print(order1.add_product_to_order())
#OrderConstuctor.reduce_quantity()
OrderConstuctor.add_quantity()
#OrderConstuctor.remove_product_from_order()

class OrderDetail:

	order_detail_id = 0
	
	def __init__ (self, shopping_bag, total_payment,delivery_address, delivery_city, recipinet_phone):
		self.shopping_bag = shopping_bag
		self.total_payment = total_payment
		self.delivery_address = delivery_address
		self.delivery_city = delivery_city
		self.recipinet_phone = recipinet_phone
		OrderDetail.order_detail_id+=1

	def __str__(self):
		return f'Shopping bag is : {self.shopping_bag}\nTotal_payment is : {self.total_payment}\nDelivery_address is : {self.delivery_address}\nDelivery city is : {self.delivery_city}\nRecipient phone is : {self.recipinet_phone}\nOrder detial id is : {OrderDetail.order_detail_id}'

	
class RegisteredUser(Person):
	register_user_id = 0
	
	login_passwd_dict = {}
	
	def __init__(self, reg_date, email, password):
		self.reg_date= reg_date
		self.email = email
		self.password = password
		login_passwd_dict[login]=password
		RegisteredUser.register_user_id+=1

	
	

