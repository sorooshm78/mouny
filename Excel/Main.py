import pandas
import pandas as pd

Data = pandas.read_excel('System_Money.xlsx', sheet_name = "expend")

Name = 'تفریح'

for index, row in Data.iterrows():
	if row['Block'] == Name:
		print("block "+ row['Block']+ " Val "+ str(row['Val']) + " Data "+ row['Data'])
