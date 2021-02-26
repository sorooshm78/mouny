#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define RESET       "\033[0m"
#define BLACK       "\033[30m"      
#define RED         "\033[31m"     
#define GREEN       "\033[32m"     
#define YELLOW      "\033[33m"     
#define BLUE        "\033[34m"     
#define MAGENTA     "\033[35m"     
#define CYAN        "\033[36m"     
#define WHITE       "\033[37m"     
#define BOLDBLACK   "\033[1m\033[30m"     
#define BOLDRED     "\033[1m\033[31m"     
#define BOLDGREEN   "\033[1m\033[32m"     
#define BOLDYELLOW  "\033[1m\033[33m"    
#define BOLDBLUE    "\033[1m\033[34m"     
#define BOLDMAGENTA "\033[1m\033[35m"    
#define BOLDCYAN    "\033[1m\033[36m"     
#define BOLDWHITE   "\033[1m\033[37m"    

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
	void show_detail();

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
	cout << BLUE << "list record block " << name << RESET << endl;

	for(int i = 0; i < list_records.size(); i++)
	{
		cout << BLUE <<"id : " << i + 1;
		cout << "	";
		cout << "val : " << list_records[i].val;
		cout << "	";
		cout << "comment : " <<  list_records[i].comment << RESET << endl;
	} 
}

void block::show_detail(int id)
{
	cout << BLUE << "id: " << id;
	cout << "	";
	cout << "name: " << name;
	cout << "	";
	cout << "val: " << val;
	cout << RESET << endl;
}

void block::show_detail()
{
	cout << BLUE << "name: " << name;
	cout << "	";
	cout << "val: " << val;
	cout << RESET << endl;
	show_records();
}

////////////////////////////////////////////////

class blocks
{
public:
	void show_blocks();
	void del_block();
	void add_block(string name);
	block& get_block(string name);
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
	cout << BLUE << "list blocks:" << RESET <<endl;

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
	cout << BLUE << "list record repository " << endl;

	for(int i = 0; i < list_records.size(); i++)
	{
		cout << "id : " << i + 1;
		cout << "	";
		cout << "val : " << list_records[i].val;
		cout << "	";
		cout << "comment : " <<  list_records[i].comment << RESET << endl;
	} 
}

void repository::show_detail()
{
	cout <<  BLUE << "repository: " << endl;
	cout << "val: " << val;
	cout << RESET << endl;
	show_records();
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
	
	b.add_block("food");
	b.add_block("fun");
	
	vector<string> ls_command;
	
	do{	
		ls_command = read_command();

		// NEW
		if(ls_command[0] == "new")
		{
			if(ls_command[1] == "block" or ls_command[1] == "-b")
			{
				b.add_block(ls_command[2]);			
				b.show_blocks();
			}
			
			if(ls_command[1] == "input" or ls_command[1] == "-i")
			{
				int val;
				string comment = "nothing";
	
				if(ls_command[2] == "val" or ls_command[2] == "-v")
				{
					val = stoi(ls_command[3]);
				}

				if(ls_command[4] == "comment" or ls_command[4] == "-c")
				{
					comment = ls_command[5];
				}
				r.add_record(val, comment);				
				r.show_detail();
			}
		}
	
		// SHOW
		if(ls_command[0] == "show")
		{
			if(ls_command[1] == "blocks" or ls_command[1] == "-b")
			{
				if(ls_command.size() == 2)
					b.show_blocks();
				else
					b.get_block(ls_command[2]).show_detail();
			}
			
			if(ls_command[1] == "inputs" or ls_command[1] == "-i")
			{
				r.show_detail();
			}
		}
		
		// SPEND
		if(ls_command[0] == "spend")
		{
			int val = 0;
			string name;
			string comment = "nothing";

			if(ls_command[1] == "block" or ls_command[1] == "-b")
			{
				name = ls_command[2];
				if(ls_command[3] == "val" or ls_command[3] == "-v")
					val = stoi(ls_command[4]);
				if(ls_command[5] == "comment" or ls_command[5] == "-c")
					comment = ls_command[6];
			}
			b.get_block(name).add_record(val, comment);
		}
		
		//DELETE
		if(ls_command[0] == "del")
		{
			if(ls_command[1] == "block" or ls_command[1] == "-b")
				b.del_block();
		}
	
		// ALLOCATION
		if(ls_command[0] == "alloc")
		{
			string name;
			int val;

			if(ls_command[1] == "block" or ls_command[1] == "-b")
				name = ls_command[2];
			if(ls_command[3] == "val" or ls_command[3] == "-v")
				val = stoi(ls_command[4]);	

			cout << "val:" << val << endl;
			cout << "block:" << name << endl;

			r.allocation_mouny(val, b.get_block(name));
		}
		
	}
	while(ls_command[0] != "exit");

    return 0;
}
