#include<iostream>
#include<string>
using namespace std;

//parent class
class Operator{
//Attributes:
private:
string name;
int customerID;
double callRatePerMinute;
double messageRate;
double internetRatePerMB;

//methods
public:
//– constructor
Operator(string n,int c,double cr,double m, double i){ 
name=n;
customerID=c;
callRatePerMinute=cr;
messageRate=m;
internetRatePerMB=i;
}
//getter func
string getName(){
	return name;
}
//getter func
double getCallRate(){
	return callRatePerMinute;
}
//getter func
double getMessageRate(){
	return messageRate;
}
double getInternetRate(){
	return internetRatePerMB;
}
void displayOperatorDetails(){
	cout<<"=====Displaying Operator class attributes====="<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"CustomerID: "<<customerID<<endl;
	cout<<"CallRatePerMinut: "<<callRatePerMinute<<endl;
	cout<<"MessageRate: "<<messageRate<<endl;
	cout << "InternetRatePerMB: " << internetRatePerMB << endl;
	
	
}
};
//parent class
class Customer{
private:
string name;
int customerID;
double balance;
double billLimit;
Operator* currentOperator;
public:
//constructor
Customer(string n,int c,double b,double bl,Operator* op){ //– constructor
name=n;
customerID=c;
balance=b;
billLimit=bl;
currentOperator=op;
}
//getter func
string getName(){
	return name;
}
//function for call
void talkTo(Customer& other){
	double rate,duration;
	cout<<"How much call duration you want? : \n";
	cin>>duration;
	rate=currentOperator->getCallRate();
	double totalcost=duration*rate;
	
	cout<<"Calling: "<<other.getName()<<" for "<<duration<<"minutes"<<endl;
	cout<<"Calling Cost: "<<totalcost<<endl;
	
	if(balance>=totalcost){
	balance-=totalcost;
	cout<<"Call successfull! New balance = "<<balance<<endl;
	}
	else{
		cout<<"Unsufficent Balance"<<endl;
	}
}
//function for message
void sendMessage(Customer& other, string msg){
	double rate;
	rate=currentOperator->getMessageRate();
	double totalcost=rate;
	
	cout<<"Sending Message to: "<<other.getName()<<endl;
	cout<<"Message: "<<msg;
	cout<<"Message Cost: Rs "<<totalcost<<endl;
	
	if(balance>=totalcost){
	balance-=totalcost;
	cout<<"Message sent successfully! New balance = Rs "<<balance<<endl;
	}
	else{
		cout<<"Unsufficent Balance! Message not sent"<<endl;
	}
}
//funtion for internet
void connectToInternet(){
	double rate,mbUsed;
	cout<<"How much Mb you want: "<<endl;
	cin>>mbUsed;
	rate=currentOperator->getInternetRate();
	double totalcost=mbUsed*rate;
	cout<<"Using: "<<mbUsed<<"MB  per Mb cost is"<<rate<<endl;
	cout<<"Total cost for "<<mbUsed<<"MB is: "<<totalcost<<endl;
	if(balance>=totalcost){
	balance-=totalcost;
	   cout << "Connected to internet successfully. New balance: Rs. " << balance << endl;
    } else {
        cout << "Insufficient balance. Internet connection failed." << endl;
    }
}

//function for changeOperator
void changeOperator(Operator* newOperator){
	if(currentOperator==newOperator){
		 cout << "Already using operator: " << currentOperator->getName() << endl;
	}
	else{
		currentOperator = newOperator;
		 cout << "Operator has been changed: " << currentOperator->getName() << endl;
	}
} 
//function for paybill
void paybill(){
	double amount;
	cout<<"Enter amount you want to Pay: \n";
	cin>>amount;
	cout << "Payment of Rs. " << amount << " successful!" << endl;
	if(amount>=0){
		balance+=amount;
		cout<<"Amount Recharged successfully: New Balance = Rs "<<balance<<endl;
	}
	else{
		cout<<"Recharge Not Possible "<<endl;
	}
}
void changeBillLimit() {
	double newLimit;
	cout<<"Your Current BillLimit: "<<billLimit<<endl;
	cout<<"You can Change your account Limit: as you want: \n";
	cin>>newLimit;
	if(newLimit>=0){
		billLimit=newLimit;
		cout<<"New Bill Limit: "<<newLimit<<endl;
	}
	else{
		cout<<"Cannot Increase the Bill Limit"<<endl;
	}
}
//method
void displayCustomerDetails(){
	cout<<"=====Displaying Customer class attributes====="<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"CustomerID: "<<customerID<<endl;
	cout<<"Balance: "<<balance<<endl;
	cout<<"BillLimit: "<<billLimit<<endl;
	cout<<"Operator: " << currentOperator->getName() << endl; 
}
};


int main(){
	Operator o1("Zong",23,2.4,4.6,3.4);
	Operator o2("Jazz",223,2.4,4.6,3.4);

     
    Customer c1("Faiz",34,23.5,56.2,&o1);
    Customer c2("Muneb",34,23.5,56.2,&o1);
    
	int choice;
do {
	 cout << "\n================= COMMUNICATION SIMULATION APP ================" << endl;
    cout << "\n========= CUSTOMER MENU =========" << endl;
    cout << "1. Make a Call" << endl;
    cout << "2. Send a Message" << endl;
    cout << "3. Connect to Internet" << endl;
    cout << "4. Pay Bill" << endl;
    cout << "5. Change Operator" << endl;
    cout << "6. Change Bill Limit" << endl;
    cout << "7. Show Customer Details" << endl;
    cout << "0. Exit" << endl;
    cout << "================================" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    string msg;
    double mb;
switch(choice){
	case 1:
		c1.talkTo(c2);
		break;
	case 2:
		cin.ignore(); // Clear input buffer
        cout << "Enter your message: ";
        getline(cin, msg);
		c1.sendMessage(c2,msg);
		break;
	case 3:
		c1.connectToInternet();
		break;
	case 4:
		c1.paybill();
		break;
	case 5:
		c1.changeOperator(&o1);
		break;
	case 6:
		c1.changeBillLimit();
		break;
	case 7:
		c1.displayCustomerDetails();
	    break;
	case 0: {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        
}
} while (choice != 0);
return 0;
}


	


