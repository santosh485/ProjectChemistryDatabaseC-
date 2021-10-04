
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<fstream>

using namespace std;
class Chemistry
{
	private:
		int register_id;
		string compound_name;
		string compound_molecular_weight;
		string compound_type;
		string compound_uses;
		string compound_formula;
		string reference;
		string structur;
	public:
		void registration();
		void view();
		void write();
		void search();
		void edit();
		void read();	
};
void Chemistry::registration()
{
	cout<<"Enter Registeration Id: ";
	cin>>register_id;
	cout<<"Enter Compound Name: ";
	cin>>compound_name;
	cout<<"Enter compound molecular weight: ";
	cin>>compound_molecular_weight;
	cout<<"Enter compound uses: ";
	cin>>compound_uses;
	cout<<"Enter compound formula: ";
	cin>>compound_formula;
	cout<<"Enter reference: ";
	cin>>reference;
	cout<<"...................."<<endl;
	
}
void Chemistry::view()
{
	cout<<"Enter Registeration Id: "<<register_id<<endl;
	cout<<"Enter Compound Name: "<<compound_name<<endl;
	cout<<"Enter compound molecular weight"<<compound_molecular_weight<<endl;
	cout<<"Enter compound uses: "<<compound_uses<<endl;
	cout<<"Enter compound formula"<<compound_formula<<endl;
	cout<<"................................"<<endl;
}
void Chemistry::write()
{
	ofstream write;
	write.open("Chemistry.xlx", ios::out|ios::binary|ios::app);
	registration();
    write.write(reinterpret_cast<char *>(this), sizeof(*this));
    write.close();
}
void Chemistry::read()
{
	ifstream read;
	read.open("Chemistry.xlx", ios::binary|ios::app);
	if(!read)
	{
		cout<<"File Not Exists";
		return ;
	}
	else
	{
		cout<<"............Chemistry Data..................."<<endl;
		while(!read.eof())
		{
			if(read.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        	{
            	view();
        	}
		}
	}
	read.close();
}
void Chemistry::search()
{
	int n;
	ifstream search;
	search.open("Chemistry.xlx", ios::binary);
	if(!search)
	{
		cout<<"File doesnot exit"<<endl;
		return ;
	}
	else
	{
		search.seekg(0,ios::end);
    int count = search.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    search.seekg((n-1)*sizeof(*this));
    search.read(reinterpret_cast<char*>(this), sizeof(*this));
    view();
	}
	
	search.close();
}
void Chemistry::edit()
{
	int n;
	fstream edit;
	edit.open("Chemistry.xlx", ios::binary|ios::app);
	if(!edit)
	{
		cout<<"File doesnot exit "<<endl;
		return;
	}
	else
	{
		edit.seekg(0, ios::end);
		int count = edit.tellg()/sizeof(*this);
		cout<<"\n There are "<<count<<" record in the file";
    	cout<<"\n Enter Record Number to edit: ";
    	cin>>n;
    	edit.seekg((n-1)*sizeof(*this));
    	edit.read(reinterpret_cast<char*>(this), sizeof(*this));
    	cout<<"Record "<<n<<" has following data"<<endl;
    	view();
    	edit.close();
    	edit.open("Chemistry.xlx", ios::out|ios::in|ios::binary);
    	edit.seekp((n-1)*sizeof(*this));
    	cout<<"\nEnter data to Modify "<<endl;
    	registration();
    	edit.write(reinterpret_cast<char*>(this), sizeof(*this));
	}
}
int main()
{
	Chemistry che;
	int choice;
	cout<<"Chemistry Information System"<<endl;
	while(true)
	{
		cout<<"Select One Option"<<endl;
		cout<<"Enter 1 for Registration"<<endl;
		cout<<"Enter 2 for view"<<endl;
		cout<<"Enter 3 for write"<<endl;
		cout<<"Enter 4 for search"<<endl;
		cout<<"Enter 5 for edit"<<endl;
		cout<<"Enter 6 for read"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				che.registration();
				break;
			case 2:
				che.view();
				break;
			case 3:
				che.write();
				break;
			case 4:
				che.search();
				break;
			case 5:
				che.edit();
			case 6:
				che.read();
				break;
			default:
				cout<<"Enter correct option"<<endl;
				exit(0);
					
		}
	}
	return 0;
}
