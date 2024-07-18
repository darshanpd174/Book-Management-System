#include <bits/stdc++.h>

using namespace std;

struct Node
{
	string name;
	int Book_price;
	bool status;
	Node *next;
	Node *prev;
};
class Bookstore
{
public:
	Node *head;
	Node *mid; // used in binary search
	string Book_name;
	int price;

	Bookstore()
	{
		head = NULL;
	}
	void CreateNode() // used for inserting a book
	{
		Node *new_node = new Node;
		cout<<endl;
			cout << "  Name of BOOK: ";
			cin.ignore();  // to ignore the previously stored /n from cin
			getline(cin, Book_name); //use for taking full name of book
			new_node->name = Book_name;
			new_node->status = false;

			while(true){
				cout << "  BOOK PRICE: ";
				cin >> price;
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid Price." << endl;
				}
				else{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
			new_node->Book_price = price;

			new_node->next = NULL;
			new_node->prev = NULL;

		

		if (head == NULL)
		{
			
			head = new_node;

			
		}
		else
		{

			

			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
			
		}

		cout << endl << "  Book Added" << endl << endl;
	}
	void Display()
	{
		Node *temp = head;
		int count = 0;

		if (temp == NULL)
		{
			cout << "  No Books... Please Add Some Books" << endl;
			
		}
		else
		{
			BubbleSort();

			cout << left << setw(20) << "Book Name" 
				<< left << setw(15) << "Book Price" 
				<< left << setw(15) << "Status" 
				<< endl;

			cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;

			while (temp != NULL)
			{
				count++;
				cout << left << setw(20) << temp->name
						<< left << setw(15) << temp->Book_price
						<< left << setw(15) << (temp->status ? "On Rent" : "Available")
						<< endl;
					temp = temp->next;
			}
			cout << "\n  Total Books: " << count << endl << endl;
		}
	}

	bool Bsearch()
	{	
		if(head==NULL){
			cout << " There are no book in store" << endl << endl;
			return false;
		}

		cout << "\nEnter Book Name : " ;
		cin.ignore();
		getline(cin, Book_name);
		cout << endl;

		// find a mid node
		Node *temp = head;
		
		while(temp){
			if(temp->name == Book_name){
				cout << "Book is Found" << endl;
				cout << "Book Name : " << temp->name << endl;
				cout << "Book price : " << temp->Book_price << endl;
				cout << "Book Status : " << (temp->status ? "On Rent" : "Available") << endl;
				
				return true;
			}

			temp=temp->next;
		}
		
		cout << "\nBook Not Found" << endl << endl;
		return false;
	}
	

	void DeleteAll_Books()
	{
		Node *temp = head;
		Node *temp2;
		cout<<endl;
		if (head == NULL)
		{
			cout << "  Book Store is Empty" << endl;
			cout << endl;
		}
		else
		{
			while (temp != NULL)
			{
				temp2 = temp;
				temp = temp->next;
				delete temp2;
			}
			head = NULL;
			cout << "  Successfully Deleted All Books" << endl;
			cout << endl;
		}
	}
	// delete specific books
	bool DeleteBooks()
	{	
		Node *temp = head;
		if(temp==NULL){
			cout << "  Book Store is Empty" << endl;
			
			return 1;
		}
		cout << "\nEnter the Book name to delete: ";
		cin.ignore();
		getline(cin, Book_name);

		
		cout<<endl;

		while(temp!=NULL){
			if(temp->name == Book_name){
				if(temp->prev != NULL){
					temp->prev->next=temp->next;
				}
				else{
					head=temp->next;
				}
				if(temp->next != NULL){
					temp->next->prev = temp->prev;
				}
				delete temp;

				cout << "Book deleted Successfully" << endl << endl;
				return true;
			}

			temp=temp->next;
		}

		cout << "Book not found" << endl << endl;
		return false;
	}

	// bubble sort applying
	void BubbleSort()
	{
		Node *temp = head;
		Node *i, *j;
		string n;
		int swap2;
		bool swap3;
		if (temp == NULL)
		{
			cout << "  Books store is Empty" << endl << endl;
		}
		else
		{
			for (i = temp; i->next != NULL && i != NULL; i = i->next)
			{
				for (j = i->next; j != NULL; j = j->next)
				{

					// swap

					if (i->name > j->name)
					{
						n = i->name;
						i->name = j->name;
						j->name = n;

						swap2 = i->Book_price;
						i->Book_price = j->Book_price;
						j->Book_price = swap2;

						swap3 = i->status;
						i->status = j->status;
						j->status = swap3;
					}
				}
			}
		}
	}

	int EditContacts()
	{
		Node *temp = head;
		if(temp==NULL){
			cout << "  No Books... Please Add Some Books" << endl;
			
			return 1;
		}
		cout << "\nEnter Book Name to Edit: ";
        cin.ignore();
        getline(cin, Book_name);

        
		cout<<endl;

        while (temp != NULL) {
            if (temp->name == Book_name) {
                cout << "  Enter New Book Name: ";
                getline(cin, Book_name);
				while(true){
					cout << "  Enter New Book Price: ";
					cin >> price;
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid Price." << endl;
				}
				else{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
				}
                

                temp->name = Book_name;
                temp->Book_price = price;
				temp->status = false;

                cout << "  Book Edited Successfully" << endl;
                return 0;
            }
            temp = temp->next;
        }
        cout << "  Book Not Found" << endl << endl;
        return 1;
	}

	void buymax()
	{

		Node* temp = head;
		if(temp==NULL){
			cout << "  No Books... Please Add Some Books" << endl;
			
		}
		else{
			while(true){
				cout << "\n Enter maximum price you can pay: ";
				cin >> price;
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid Price." << endl;
				}
				else{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}

			
			int count = 0;
			cout<<endl;
			while(temp!=NULL){
				if(temp->Book_price <= price && !temp->status){
					count++;
					cout << "  " << temp->name << "  :";
					cout << "  " << temp->Book_price << endl;
					
				}

				temp = temp->next;
			}
			if(count==0){
				cout << "\n SORRY ! There are no books below this prize" << endl << endl;
			}
			else{
				cout << "\n  Total Books: " << count << endl << endl;
			}
		}	
	}

	void rent(){
		Node* temp = head;
		if(temp==NULL){
			cout << "  Book Store is Empty" << endl;
			return;
		}

		cout << "\nEnter Book Name to rent/return: ";
        cin.ignore();
        getline(cin, Book_name);
		cout<<endl;

		cout << "Do You Want to Rent(1) or Return(0) :";
		bool check;
		while(true){
		cin >> check;
		if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid Price." << endl;
				}
				else{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
		}
	

		while(temp!=NULL){
			if(temp->name == Book_name){
				if(temp->status){
					if(check){
						cout << "\nSorry ! Book is Already on Rent" << endl <<endl;
						
						return;
					}
					else{
						temp->status = false;
						cout << "\nBook is returned" << endl << endl;
						return;
					}
				}
				else{
					cout << "Book Found" << endl;
					cout << "Book Name : " << temp->name << endl;
					cout << "Book Price : " << temp->Book_price << endl;
					temp->status = true;
					cout << " ThankYou for purchase "<< endl << endl;
					return;
				}
				
			}
			temp=temp->next;
		}

		cout << "Sorry ! Book is Not Available"<< endl;
	}
	
};

void managebook(Bookstore& bs){
	
	int inp;
	
	do{
		cout<< "\n  ** MANAGE BOOKS **" << endl << endl;
		cout << "  1. Add Books" << endl;
		cout << "  2. Edit the Book" << endl;
		cout << "  3. Delete Book" << endl;
		cout << "  4. Delete All Books" << endl;
		cout << "  0. Return to Home page" << endl << endl;

		cout << " Enter the input : ";
		cin >> inp;

		switch(inp){
			case 1:
				bs.CreateNode();
				break;

			case 2:
				bs.EditContacts();				
				break;

			case 3:
				bs.DeleteBooks();
				break;

			case 4:
				bs.DeleteAll_Books();
				break;

			case 0:
				break;

			default:
				cout << "\nERROR: invalid Option" << endl << endl;
				break;
			}
	}
	while(inp!=0);
}

int main()
{
	Bookstore bs;
	
	int user;
	
	
	
	do
	{
		
		cout << "\n WELCOME TO Rental BOOK STORE MANAGEMENT SYSTEM  " << endl << endl;
		cout << "  1. Manage Books" << endl;		
		cout << "  2. Search Book" << endl;
		cout << "  3. Display All Books" << endl;		
		cout << "  4. Books Below Your Budget" << endl;
		cout << "  5. Rent a Book" << endl;
		cout << "  0. Close the program" << endl << endl;
		
		cout << " Enter the Input  ";
		cin >> user;

		switch (user)
		{
		case 1:
			managebook(bs);
			break;
			
		case 2:
			bs.Bsearch();

			break;
		case 3:
			bs.Display();			
			break;

		case 4:
			bs.buymax();
			break;

		case 5:
			bs.rent();
			break;

		case 0:
			cout << "\nThankyou for visit" << endl << endl;;
			break;

		default:
			cout << "\nERROR: invalid Option" << endl << endl;
		}

	} while (user != 0);

	return 0;
}