/*

	Name : Ahmad Azam (100698308), Ryan Makund (100742692)

	Date : September 19, 2020

	Description : Lab One Review of Classes and Objects. Creating a programe that stores detial about work ticket. first it stores the input but before storing eac data the program will
	 runs it throgh validation and than stored into correct variable.


*/


#include<iostream>
#include <stdexcept>
#include<string>
#include <sstream> 

using namespace std;
// main class name
class WorkTicket
{
public:

	std::string ToString() const;

	
	//default constructor
	WorkTicket()
	{

		

		WorkTicketNumber = 0;
		Day = 1;
		Month = 1;
		Year = 2000;
		ClientID = "";
		IssueInformation = "";
	}
	int GetTicketNumber() const;

	int GetDay() const;
	int GetMonth() const;

	
	int GetYear() const;
	string GetClientID() const;
	string GetIssue() const;



	//parameterized constructor
	WorkTicket(int ticket, string clientID, int day, int month, int year, string desc)
	{
		WorkTicketNumber = ticket;
		ClientID = clientID;
		Day = day;
		Month = month;
		Year = year;
		IssueInformation = desc;
	}
	// function for getting input from user and validating all the integer inout for work ticket Info.
	void SetWorkTicket()
	{

		cout << endl << "Please enter the ticket number:";
		cin >> WorkTicketNumber;
		Validating_Work_Ticket_Number(WorkTicketNumber);

		cout << endl << "Please enter the client ID: ";
		getchar(); 		// for clearing the buffer 
		getline(cin, ClientID);

		cout << endl << "Enter the day for date: ";
		cin >> Day;
		int Validating_Day_for_date(Day);

		cout << endl << "Enter the month for the date: ";
		cin >> Month;
		Validating_Month_for_date(Month);

		cout << endl << "Enter the year for date: ";
		cin >> Year;
		Validating_Year_for_date(Year);

		cout << endl << "Enter your issue description:";
		getchar();
		getline(cin, IssueInformation);

	}
	
	//function for getting the output print on display
	void ShowWorkTicket()
	{
		

		cout << WorkTicket::ToString();
	}
	WorkTicket(const WorkTicket & wT):
			WorkTicketNumber(wT.WorkTicketNumber), Day(wT.Day), Month(wT.Month), Year(wT.Year), ClientID(wT.ClientID), IssueInformation(wT.IssueInformation)
		{
			cout << "WorkTicket Object was Copied.\n " << endl;
		}
	bool operator==(const WorkTicket& other_Pos) const;


private:
	// variable to store ticket number		
	int WorkTicketNumber;
	//variable to store Day for date
	int Day;
	//variable to store Month for date
	int Month;
	//variable to store year for date
	int Year;
	// variable to store client ID		
	string ClientID;
	//  variable to store Issue 
	string IssueInformation;

	//Function to do validation of all integer input
	int Validating_Work_Ticket_Number(int ticket_no);
	int Validating_Day_for_date(int day);
	int Validating_Month_for_date(int month);
	int Validating_Year_for_date(int year);
};
std::string WorkTicket::ToString() const
{
	// declare a stringstream object
	std::stringstream strOut;

	// build the string
	strOut << "(" <<"Ticket Number #"<< WorkTicketNumber<<" - "<<ClientID<<"  ("<<Day<<"/" <<Month<<"/"<<Year<<"): "<<IssueInformation<<")";

	// return the string
	return strOut.str();
}



int main()
{
	cout << "-----------------------------------------------------\n"
		<< "\t Lab One Review of Classes and Objects \n\t\t\tWorkTicket\n"
		<< "-------------------------------------------------------\n\n";
	//making array's of 4 
	WorkTicket tickets[4];

	//using for loop to keep the programme running until 4 times (collect data in 4 boxes of an array)
	for (int round = 0;round < 4;round++)
	{
		//exception handling
		try
		{
			//calling the function to get the ticket information
			tickets[round].SetWorkTicket();
			cout << "\n---------------------------------";
		}
		catch (invalid_argument& ex)
		{
			cin.clear();
			cin.sync();
			cout << endl
				<< ex.what();
			//displaying exceptions accordingly
			cerr << ex.what() << endl;
		}
	}

	//second for loop showing the info ass many times as we cteate array size

	cout << "\n---------------------\n\tOutPut\n";
	for (int output = 0;output < 4;output++)
	{
		tickets[output].ShowWorkTicket();
	}

	return 0;

}
//Function for validating the work ticket number
int WorkTicket::Validating_Work_Ticket_Number(int ticket_number)
{
	if (cin.fail()) // If the User Enter None numeric Value
	{
		throw  std::invalid_argument("\nTicket number can not be non numeric!!!");
	}
	else if (ticket_number < 0 || ticket_number == 0)
	{
		throw std::invalid_argument("\nTicket number can not be non numeric or zero or negative!!!");
	}
}
//Function Validating day for date
int WorkTicket::Validating_Day_for_date(int day)
{
	if (cin.fail())
	{
		throw  std::invalid_argument("\nDay Number must a numeric Value!!!");
	}
	else if (day < 1 || day > 31)
	{
		throw std::invalid_argument("\nThe entered input for date is out of range!!!");
	}
}
//Function Validating month for date
int WorkTicket::Validating_Month_for_date(int month)
{
	if (cin.fail())
	{
		throw  std::invalid_argument("\nDay Value must be numeric !!!");
	}
	else if (month < 1 || month > 12)
	{
		throw std::invalid_argument("\nThe entered input for month is out of range!!!");
	}
}
//Function Validating year for date
int WorkTicket::Validating_Year_for_date(int year)
{
	if (cin.fail())
	{
		throw  std::invalid_argument("\nYear Value must a numeric!!!");
	}
	else if (year < 2000 || year > 2099)
	{
		throw std::invalid_argument("\nThe entered input for the year  is out of range!!!");
	}
	
}
bool WorkTicket::operator==(const WorkTicket& other_Pos) const
{
	return ((GetTicketNumber() == other_Pos.GetTicketNumber()) && (GetDay() == other_Pos.GetDay()) && (GetMonth() ==other_Pos.GetMonth()) && (GetYear() == other_Pos.GetYear()) && (GetClientID() ==other_Pos.GetClientID())&& (GetIssue() == other_Pos.GetIssue()));
}

