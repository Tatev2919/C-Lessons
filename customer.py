#!/usr/bin/python3

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
