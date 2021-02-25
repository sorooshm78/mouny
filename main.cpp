#include <iostream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////

class record
{
public:
	record(int val, string comment);
	int val;
	string comment;
};

record::record(int val, string comment)
:comment(comment),
val(val)
{}

////////////////////////////////////////////////

class block
{
public:
    block(string name);
	string get_name(){ return name;}
	int get_val(){ return val;}
	void add_record(int val, string comment);
	void show_records();
	void del_record();
	void show_detail(int id);
	void add_val(int val){ this->val += val;}

private:
    string name;
    int val;
	vector <record> list_records;
};

block::block(string name)
:name(name)
,val(0)
{
}

void block::del_record()
{
	int input;
	show_records();

	while(true)
	{
		cout << "input id record for deleted: " << endl;
		cin >> input;
		if(input >= 1 and input <= list_records.size())
		{
			val += list_records[input - 1].val;
			list_records.erase(list_records.begin() + (input - 1));
			cout << "record " << input << " is deleted" << endl;
			break;
		}
		else
			cout << "input number is not correct" << endl;
	}
}

void block::add_record(int val, string comment)
{
	this->val -= val;
	list_records.push_back(record(val, comment));
}

void block::show_records()
{
	cout << "list record block " << name << endl;

	for(int i = 0; i < list_records.size(); i++)
	{
		cout << "id : " << i + 1;
		cout << "	";
		cout << "val : " << list_records[i].val;
		cout << "	";
		cout << "comment : " <<  list_records[i].comment << endl;
	} 
}

void block::show_detail(int id)
{
	cout << "id: " << id;
	cout << "	";
	cout << "name: " << name;
	cout << "	";
	cout << "val: " << val;
	cout << endl;
}

////////////////////////////////////////////////

class blocks
{
public:
	void show_blocks();
	void del_block();
	void add_block(string name);
	block& get_block(string name);
	
//private:
	vector<block> list_blocks;
};

block& blocks::get_block(string name)
{
	for(int i = 0; i < list_blocks.size(); i++)
		if(list_blocks[i].get_name() == name)
			return list_blocks[i];
}

void blocks::show_blocks()
{
	cout << "list blocks:" << endl;

	for(int i = 0; i < list_blocks.size(); i++)
	{

		list_blocks[i].show_detail(i + 1);
	}
}

void blocks::del_block()
{
	int input;
	show_blocks();

	while(true)
	{
		cout << "input id block for deleted: " << endl;
		cin >> input;
		if(input >= 1 and input <= list_blocks.size())
		{
			cout << "block " << list_blocks[input - 1].get_name() << " is deleted" << endl;
			list_blocks.erase(list_blocks.begin() + (input - 1));
			break;
		}
		else
			cout << "input number is not correct" << endl;
	}	
}

void blocks::add_block(string name)
{
	list_blocks.push_back(block(name));
}

////////////////////////////////////////////////

class repository
{
public:
	repository();
	void add_record(int val, string comment);
	void show_records();
	void del_record();
	void show_detail();
	void allocation_mouny(int val, block &b);	

private:
	int val;
	vector<record> list_records;
};

repository::repository()
:val(0)
{
}

void repository::allocation_mouny(int val, block &b)
{
	if(this->val == 0)
	{
		cout << "not enough mouny" << endl;
	}
	else if(val <= this->val)
	{	
		this->val -= val;
		b.add_val(val);
	}
}
	
void repository::del_record()
{
	int input;
	show_records();

	while(true)
	{
		cout << "input id record for deleted: " << endl;
		cin >> input;
		if(input >= 1 and input <= list_records.size())
		{
			val -= list_records[input - 1].val;
			list_records.erase(list_records.begin() + (input - 1));
			cout << "record " << input << " is deleted" << endl;
			break;
		}
		else
			cout << "input number is not correct" << endl;
	}
}

void repository::add_record(int val, string comment)
{
	this->val += val;
	list_records.push_back(record(val, comment));
}

void repository::show_records()
{
	cout << "list record repository " << endl;

	for(int i = 0; i < list_records.size(); i++)
	{
		cout << "id : " << i + 1;
		cout << "	";
		cout << "val : " << list_records[i].val;
		cout << "	";
		cout << "comment : " <<  list_records[i].comment << endl;
	} 
}

void repository::show_detail()
{
	cout << "repository: " << endl;
	cout << "val: " << val;
	cout << endl;
}

////////////////////////////////////////////////

vector<string> read_command()
{
	vector<string> list_command;
	string command;
	string word;

	getline(cin ,command);
	
	for(int i = 0; i < command.size(); i++)
	{
		if(command[i] == '"')
		{
			i++;
			while(command[i] != '"')
			{
				word.push_back(command[i]);
				i++;
			}

			list_command.push_back(word);
			word.clear();
	
			continue;
		}

		if(command[i] == ' ' or i == command.size() -1)
		{
			if(i == command.size() - 1)
				word.push_back(command[i]);

			if(word.size() != 0)
			{
				list_command.push_back(word);
				word.clear();
			}
		}		
		else
		{
			word.push_back(command[i]);
		}
	}
	return list_command;
}

int main()
{
	repository r;
	blocks b;
		
	vector<string> ls_command;

	
	do{	
		ls_command = read_command();

		if(ls_command[0] == "new")
		{
			if(ls_command[1] == "block" or ls_command[1] == "-b")
			{
				if(ls_command[2] == "name" or ls_command[2] == "-n")
				{	
					b.add_block(ls_command[3]);			
				}
			}
		}
	}
	while(ls_command[0] != "exit");

	b.show_blocks();

/*
	r.add_record(10000, "help");	

	b.add_block("food");
	b.show_blocks();

	r.allocation_mouny(2000, b.get_block("food"));
	b.show_blocks();

	b.list_blocks[0].add_record(100, "sandwich");
	b.show_blocks();
*/	
    return 0;
}















