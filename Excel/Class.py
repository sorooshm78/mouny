import pandas

# Class Block

class Block:
	def __init__(self, name):
		self.name = name
		self.allocation = 0
		self.expend = 0 

	def print(self):
		print("Name:" + self.name +
		"\t allo:" +  str(self.allocation) +
		"\t expend:" + str(self.expend) +
		"\t remaining:" + str(self.get_remaining()))

	def add_expend(self, val):
		self.expend += val 

	def add_allocation(self, val):
		self.allocation += val 

	def get_remaining(self):
		return self.allocation - self.expend


# Initialize variable from Excel

Block_Data = pandas.read_excel('System_Money.xlsx', sheet_name = 'blocks')
Expend_Data = pandas.read_excel('System_Money.xlsx', sheet_name = 'expend')

# Initialize list obj blocks from Excel

List_Block = []

for index_row, row in Block_Data.iterrows():
	List_Block.append(Block(row['Name']))

"""
# print obj
for obj in List_Block:
	obj.print()
"""

"""
for index_row, row in Expend_Data.iterrows():
	for index_list in range(len(List_Block)):
		if row['Block']	== List_Block[index_list].name:
			print("block " + row['Block'] + "is exist")
"""

def find_object(list_block, name):
	for index_list in range(len(List_Block)):
		if name	== List_Block[index_list].name:
			return List_Block[index_list]


for index_row, row in Expend_Data.iterrows():




































