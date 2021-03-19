import pandas
import pandas as pd

# Class Record
class Record:
	def __init__(self, comment, val, data):
		self.comment = comment
		self.val = val
		self.data = data
	
# Class Block
class Block:
	def __init__(self, name):
		self.name = name
		self.allocation = 0
		self.expend = 0 
		self.list_record = []

	def print(self):
		print("Name:" + self.name +
		"\t allo:" +  str(self.allocation) +
		"\t expend:" + str(self.expend) +
		"\t remaining:" + str(self.get_remaining()))

		print("list records:")
		for record in self.list_record:	
			print("comment:" + record.comment +
			"\t val:" +  str(record.val) +
			"\t data:" + record.data)

	def add_expend(self, val):
		self.expend += val 

	def add_allocation(self, val):
		self.allocation += val 

	def get_remaining(self):
		return self.allocation - self.expend
	
	def add_record(self, comment, val, data):
		self.list_record.append(Record(comment, val, data))

# Initialize variable from Excel
Block_Data = pandas.read_excel('System_Money.xlsx', sheet_name = 'blocks')
Expend_Data = pandas.read_excel('System_Money.xlsx', sheet_name = 'expend')
Allocation_Data = pandas.read_excel('System_Money.xlsx', sheet_name = 'allocation')

# Initialize list obj blocks from Excel
List_Block = []

for index_row, row in Block_Data.iterrows():
	List_Block.append(Block(row['Name']))

# function
def find_obj(name):
	for block in List_Block:
		if name	== block.name:
			return block

# Extraction expend data from Excel
for index_row, row in Expend_Data.iterrows():
	find_obj(row['Block']).add_expend(row['Val'])
	find_obj(row['Block']).add_record(row['Comment'], row['Val'], row['Data'])

# Extraction allocation data from Excel
for index_row, row in Allocation_Data.iterrows():
	find_obj(row['Block']).add_allocation(row['Val'])

# print obj
for obj in List_Block:
	print("-------------------------")
	obj.print()
