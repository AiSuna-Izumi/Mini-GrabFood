#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
void foodInput();
void sort();
void displayFood();
void takeFood();
void newFood();
void displayList();
void deleteFood();
void start();
void refresh();
void foodModify();
void admin();
void user();
struct grabFood{
	string number;
    string foodName;
    string price;
    string typeFood;
    struct grabFood *next;
};
grabFood *head;

int main(){
	start();
	int type;
	system("cls");
	system("color 14");
	cout<<"Enter Your Type : \n1. Customer\n2. Admin\n ::";
	cin>>type;
	if (type==1){
		user();
	}
	else if(type==2){
		admin();
	}
	
	cout<<"THANK YOU FOR USING IT \n";
	//end program
	return 0;
}
void user(){
	int choice;
	while(choice!=3){
	system("cls");
	system("color 10");
		cout<<"=========================================== \n";
		cout<<"1. Food List "<<endl;
		cout<<"2. Take Food "<<endl;
		cout<<"3. Exit \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n";
		cin>>choice;
		if(choice==1){
			displayList();
		}
		else if(choice==2){
			takeFood();
		}
		else if(choice==3){
			system("Exit");
		}
		else{
			cout<<"Wrong Input!! \nPlease Input Another Choice : ";
			user();
		}
	}
}
void admin(){
	system("cls");
	system("color 15");
	grabFood *newptr, *crptr, *prptr;
	newptr = new grabFood; 

	system("cls");
	system("color 10");
	int choice;
	while(choice !=5)
	{
	 
		system("color 10");
		system("cls");
		cout<<"=========================================== \n";
		cout<<"1. Food List "<<endl;
		cout<<"2. Input New Food "<<endl;
		cout<<"3. Delete Food "<<endl;
		cout<<"4. Food Modify"<<endl;
		cout<<"5. Exit \n";
		cout<<"=========================================== \n";
		cout<<"Enter your required \n";
		cin>>choice;
		if(choice==1){
			displayList();
		}
		else if(choice==2){
			foodInput();
		}
		else if(choice==3){
			deleteFood();
		}
		else if(choice==4){
			foodModify();
		}
		else{
		}
	
}
}
void displayList(){
	system("cls");
	system("color 50");
	grabFood *crptr;
	crptr = head;
	int choice;
	cout<<endl<<endl;
	if(crptr == NULL){
        cout<<"\nSorry the data is not found\n";
    }
    else{
	while(crptr!= NULL){
			cout<<"\t\t~~~~~~FOOD DETAIL~~~~~~\n";
			cout<<"Food Number: "<<crptr->number<<endl;
			cout<<"Food Name : "<<crptr->foodName<<endl;
			cout<<"Food Type : "<<crptr->typeFood<<endl;
			cout<<"Price : "<<crptr->price<<endl;
    	 	crptr= crptr->next;
    	 	}
    }    
	cout << "Enter 1 To Exit\n";
	cin>>choice;
}

void refresh(){
	grabFood *newptr, *crptr, *prptr;
	crptr = head;
	newptr= new grabFood;
	ifstream showFood; //declare in file 
	showFood.open("food.txt", ios::app);//open customer.txt file
	int choice;

		if (showFood.is_open()){
			while(!showFood.eof())
			{

			newptr= new grabFood;
			getline(showFood,newptr->number);
			getline(showFood,newptr->foodName);
			getline(showFood,newptr->typeFood);
			getline(showFood,newptr->price);
				if(head==NULL) 
		head = newptr;  
	
	else
	{
		crptr = head;
		
 		while(crptr != NULL){ 
            prptr = crptr;
            crptr = crptr->next;
        }

        prptr->next = newptr; 
    	 		
	}
			
}
	}
	sort();
	cout << "Press Enter to Continue\n";
	cin.ignore();
	}

void foodInput()
{
	
	system("color 20");
	system("cls");
	grabFood *newptr, *crptr, *prptr;
	newptr = new grabFood; 
	int x,choice;
	string food,price;
	ofstream addFood; //declare file 
	addFood.open("food.txt",ios::app); //file name customerReserve.txt
	if (addFood.is_open())
	{

		system("cls");
		cout<<"\t\t\t\t_____*****ENTER FOOD NAME AND PRICE*****_____ \n\n";
		cin.ignore();
			cout<<"Food Number : ";
			getline(cin, newptr->number);
			cout<<"Food Name: ";
			getline(cin, newptr->foodName);
			cout<<"\nFood Type \n1. Ala Carte\n2. Buffet\n3. Add On \n Your Choice: ";
			cin>>x;
			if(x==1){
				newptr->price="Rm 8";
				newptr->typeFood="Ala Carte";
			}
			else if(x==2){
				newptr->price="Rm 20";
				newptr->typeFood="Buffet";
			}
			else if(x==3){
				newptr->price="Rm 5";
				newptr->typeFood="Add On";
			}
			else{
				cout<<"Wrong Input !!!\n Press Enter To Continue";
				cin.ignore();
				foodInput();
			}
			
	
	{
		cout<<"__________________________________________\n";
			cout<<"\nDISPLAY \n";
		cout<<"__________________________________________\n";
			cout<<"Food Number "<<newptr->number<<endl;
			cout<<"Food Name: "<<newptr->foodName<<endl;
			cout<<"Food Type :"<<newptr->typeFood<<endl;
			cout<<"Price: "<<newptr->price<<endl;
	
	}
		{
			addFood<<newptr->number<<endl;
			addFood<<newptr->foodName<<endl;
			addFood<<newptr->typeFood<<endl;
			addFood<<newptr->price<<endl;

		}
	
}addFood.close();//close fil
sort();

		cout<<"PRESS 1  TO EXIT \n";
		cin>>choice;
}

void start()
{
		system("cls");
	    system("color 12");
	    grabFood *newptr, *crptr, *prptr;
	newptr = new grabFood; 

    int a;
    int choice;
    char again;
    char x[20];
    cout<<endl;
    cout<<"=================================================================="<<endl;   
    cout<<"|                                                                |"<<endl;
    cout<<"|            Welcome to the Grab Food System Management          |"<<endl;
    cout<<"|                                                                |"<<endl;
    cout<<"=================================================================="<<endl;
    cout<<endl;                                                   
    
    
    Beep(2020,1100);                                                             // causes the computer to beep
    char l=219;                                                                  //for loading bar
    cout<<"Please wait while system is analyzing the data\n";
    for ( int i=0; i<10 ; i++)
    {
        Beep(2000,500);
        cout<<l; 
         }
         refresh();
}
void sort()
{
	
	grabFood *cur,*index;
	string number,price,foodName,typeFood;
        if(head == NULL){
            cout<<"list is empty";  
        }
        else{  
            cur = head;  
            while(cur->next != NULL){
                index = cur->next;  
                while(index != NULL){
                    if(cur->number > index->number){
                        number = cur->number;
						foodName = cur->foodName;
						price = cur->price;
						typeFood=cur->typeFood;
						
						
                        cur->number = index->number; 
						cur->foodName = index->foodName;
						cur->price=index->price;
						cur->typeFood=index->typeFood;
					
						
						
                        index->number = number;
						index->foodName=foodName;
						index->price=price;
						index->typeFood=typeFood;
					
    	       		}
                    index = index->next  ;
            }
                cur = cur->next  ;
    		}
		}}
void checkFood(){
	system("cls");
	system("color 50");
	grabFood *crptr;
	crptr = head;
	int choice;
	cout<<endl<<endl;
	if(crptr == NULL){
        cout<<"\nSorry the data is not found\n";
    }
    else{
	while(crptr!= NULL){
			cout<<"\t\t~~~~~~Food Detail~~~~~~\n";
			cout<<"Food Number: "<<crptr->number<<endl;
			cout<<"Food Name : "<<crptr->foodName<<endl;
			cout<<"Type Food " <<crptr->typeFood<<endl;
			cout<<"Price "<<crptr->price<<endl;
    	 	crptr= crptr->next;
    	 	}
    }
    
	cout << "Enter 1 To Exit\n";
	cin>>choice;
}
void foodModify()
{
	string iData;
	int choice;
    grabFood *crptr, *prptr;
	
	system("cls");
	system("color 50");
    if(head == NULL){  //we cannot remove if the list is empty
        cout<<"\nSorry, the list is empty"<<endl;
    }
	else{
        cout<<"\nPlease Food Number To Modify: ";
        cin>>iData;
        prptr = NULL;
        crptr = head;
        /*move prptr and crptr pointers along the list */
        while(crptr != NULL && iData != crptr->number){
            prptr = crptr;
            crptr = crptr->next;
        }
        if(crptr == NULL)
        cout<<"\nSorry the data is not found\n";
    	else{
        cout<<"\nYes, the data is found!\n\n";
        cout<<"Food Number: "<<crptr->number<<endl;
        cout<<"Food Name : "<<crptr->foodName<<endl;
		cout<<"Type Food: "<<crptr->typeFood<<endl;
		cout<<"Price: "<<crptr->price<<endl;
		
        if(prptr == NULL){
            head = head->next;
            delete crptr;
        }
        else {
            /*if crptr has reached the end of the list, that means the data that
             *we want to remove is not in the list.
             *Otherwise, remove the data by linking the pointers
             */
            if(crptr == NULL){
                cout<<"\nSorry we cannot remove the data as it is not in the list"<<endl;
            }
            else{
                prptr->next = crptr->next;
                delete crptr;
            }
        }
    }
	cout<<"____________________________________________________________\n \n";
	cout<<"************************************************\n\n";
	cout << "Enter 1 to Continue\n";
	cin>>choice;
            newFood();
    cout << "Enter 1 to Continue\n";
	cin>>choice;
}
}
void displayFood()
{
	grabFood *crptr;
	crptr = head;
		if(crptr == NULL){
        cout<<"\nSorry the data is not found\n";
    }
    else{
	while(crptr!= NULL){
		cout<<"\t"<<crptr->number<<"\t\t"<<crptr->foodName<<"\t\t"<<crptr->typeFood<<"\t\t"<<crptr->price<<endl;
    	crptr= crptr->next;
    	 	}
    }
}
void deleteFood()
{
	string iData;
	int choice;
    grabFood *crptr, *prptr;
	
	system("cls");
	system("color 30");
    if(head == NULL){  //we cannot remove if the list is empty
        cout<<"\nSorry, the list is empty"<<endl;
    }
	else{
        cout<<"\nPlease Food Number : ";
        cin>>iData;
        prptr = NULL;
        crptr = head;
        /*move prptr and crptr pointers along the list */
        while(crptr != NULL && iData != crptr->number){
            prptr = crptr;
            crptr = crptr->next;
        }
        if(crptr == NULL)
        cout<<"\nSorry the data is not found\n";
    	else{
        cout<<"\nYes, the data is found!\n\n";
        cout<<"Food Number: "<<crptr->number<<endl;
        cout<<"Food Name : "<<crptr->foodName<<endl;
		cout<<"Type Food: "<<crptr->typeFood<<endl;
		cout<<"Price: "<<crptr->price<<endl;
		
        if(prptr == NULL){
            head = head->next;
            delete crptr;
        }
        else {
            /*if crptr has reached the end of the list, that means the data that
             *we want to remove is not in the list.
             *Otherwise, remove the data by linking the pointers
             */
            if(crptr == NULL){
                cout<<"\nSorry we cannot remove the data as it is not in the list"<<endl;
            }
            else{
                prptr->next = crptr->next;
                delete crptr;
            }
        }
    }
  }
	cout << "Enter 1 To Continue\n";
	cin>>choice;
}
void takeFood(){
		string iData;
	int choice;
	double x=0;
	double y=0;
	double z=0;
    grabFood *crptr, *prptr;
	
	system("cls");
	system("color 30");
    if(head == NULL){  //we cannot remove if the list is empty
        cout<<"\nSorry, the list is empty"<<endl;
    }
	else{
        cout<<"\nPlease Food Number : ";
        cin>>iData;
        prptr = NULL;
        crptr = head;
        /*move prptr and crptr pointers along the list */
        while(crptr != NULL && iData != crptr->number){
            prptr = crptr;
            crptr = crptr->next;
        }
        if(crptr == NULL)
        cout<<"\nSorry the data is not found\n";
    	else{
        cout<<"\nYes, the data is found!\n\n";
        cout<<"Food Number: "<<crptr->number<<endl;
        cout<<"Food Name : "<<crptr->foodName<<endl;
		cout<<"Price: "<<crptr->price<<endl;
		cout<<"Type Food: "<<crptr->typeFood<<endl;
		
        //if the data is in front of the list, remove it.
        cout<<"Customer Pay :RM ";
        cin>>y;
        if(crptr->typeFood=="Ala Carte")
		x=8;
        else if(crptr->typeFood=="Buffet")
        x=20;
        else if(crptr->typeFood=="Add On")
        x=5;
        
        z=y-x;
        cout<<"BALANCE RM: "<<z<<endl;
        if(prptr == NULL){
            head = head->next;
            delete crptr;
        }
        else {
            /*if crptr has reached the end of the list, that means the data that
             *we want to remove is not in the list.
             *Otherwise, remove the data by linking the pointers
             */
            if(crptr == NULL){
                cout<<"\nSorry we cannot remove the data as it is not in the list"<<endl;
            }
            else{
                prptr->next = crptr->next;
                
            }
        }
    }
  }
	cout << "Enter 1 To Continue\n";
	cin>>choice;
}
void newFood(){

	
	system("color 20");
	system("cls");
	grabFood *newptr, *crptr, *prptr;
	newptr = new grabFood; 
	int x,choice;
	string food,price;

		system("cls");
		cout<<"\t\t\t\t_____*****ENTER FOOD NAME AND PRICE*****_____ \n\n";
		cin.ignore();
			cout<<"Food Number : ";
			getline(cin, newptr->number);
			cout<<"Food Name: ";
			getline(cin, newptr->foodName);
			cout<<"\nFood Type \n1. Ala Carte\n2. Buffet\n3. Add On \n Your Choice: ";
			cin>>x;
			if(x==1){
				newptr->price="Rm 8";
				newptr->typeFood="Ala Carte";
			}
			else if(x==2){
				newptr->price="Rm 20";
				newptr->typeFood="Buffet";
			}
			else if(x==3){
				newptr->price="Rm 5";
				newptr->typeFood="Add On";
			}
			else{
				cout<<"Wrong Input !!!\n Press Enter To Continue";
				cin.ignore();
				foodInput();
			}
			
	
	{
		cout<<"__________________________________________\n";
			cout<<"\nDISPLAY \n";
		cout<<"__________________________________________\n";
			cout<<"Food Number "<<newptr->number<<endl;
			cout<<"Food Name: "<<newptr->foodName<<endl;
			cout<<"Food Type :"<<newptr->typeFood<<endl;
			cout<<"Price: "<<newptr->price<<endl;
	
	}

sort();

		cout<<"PRESS 1  TO EXIT \n";
		cin>>choice;
}
