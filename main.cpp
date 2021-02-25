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

private:
	vector<block> list_blocks;
};



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

private:
	int val;
	vector<record> list_records;
};

repository::repository()
:val(0)
{
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

int main()
{
    return 0;
}
