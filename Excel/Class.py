import pandas


class Block:
	def __init__(self, name):
		self.name = name
		self.allocation = 0
		self.expend = 0 

	def print(self):
		print("Name:" + self.name + "\t"
		+ "allo:" +  str(self.allocation) + "\t" 
		+ "expend:" + str(self.expend) + "\t"
		+ "remaining:" + str(self.get_remaining()))

	def add_expend(self, val):
		self.expend += val 

	def add_allocation(self, val):
		self.allocation += val 

	def get_remaining(self):
		return self.allocation - self.expend



List_Block = []

Block_Data = pandas.read_excel('System_Money.xlsx', sheet_name = "blocks")

for index, row in Block_Data.iterrows():
	List_Block.append(Block(row['Name']))


for obj in List_Block:
	obj.print()
