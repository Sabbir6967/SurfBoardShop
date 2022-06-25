#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Declaring the constants

double const smallSurfCost = 175.00;

double const mediumSurfCost = 190.00;

double const largeSurfCost = 200.00;

double const XXXSCost = 120.00;

void ShowUsage() { // Created a function which shows the all the messages written inside it
	cout << "To show program usage 'S' " << endl;
	cout << "To purchase a surfboard press 'P' " << endl;
	cout << "To display current purchases press 'C' " << endl;
	cout << "To display total amount due press 'T' " << endl;
	cout << "To quit the program press 'Q' " << endl;

}

//This function prompts user for quantity and size and uses if else if statements to determine user purchase
//The function has 3 parameters for sizes inside the paranthesis
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) {

	//Declare and initialize the required variables.
	int quantity = 0;

	char size = '\0';

	//Prompt the user to enter the quantity and size of the surfboard.

	cout << "Please enter the quantity and type (S=small, M=medium, L=large, X=XXXS) of surfboard you would like to purchase: ";
	cin >> quantity >> size;
	cout << endl;

	//small size purchase which uses the mathematical expression to calculate total small quantity purchased

	if (tolower(size) == 's')

	{

		iTotalSmall = iTotalSmall + quantity;

	}

	//medium size purchase which uses the mathematical expression to calculate total medium quantity purchased

	else if (tolower(size) == 'm')

	{

		iTotalMedium = iTotalMedium + quantity;

	}

	//large size purchase which uses the mathematical expression to calculate total large quantity purchased

	else if (tolower(size) == 'l')

	{

		iTotalLarge = iTotalLarge + quantity;

	}
	else if (tolower(size) == 'x')

	{

		iTotalXXXS = iTotalXXXS + quantity;

	}

	else { // if the char value is other than mentioned letter, then the system output invalid results
		cout << "Invalid choice!" << endl;
	}

}

//This function displays all the purchased made when called in the main function
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {

	if (iTotalSmall > 0)

	{

		cout << "The total number of small surfboards is " << iTotalSmall << endl;

	}

	if (iTotalMedium > 0)

	{
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;

	}

	if (iTotalLarge > 0)

	{
		cout << "The total number of large surfboards is " << iTotalLarge << endl;

	}
	if (iTotalXXXS > 0)

	{
		cout << "The total number of XXXS surfboards is " << iTotalXXXS << endl;

	}


}

//This function calculates the total spent on  all the purchase
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) {

	//Declaring and initializing the required variable for calculation
	double smallTotalAmount = 0;
	double mediumTotalAmount = 0;
	double largeTotalAmount = 0;
	double XXXSTotalAmount = 0;
	double totalAmountDue = 0;


	cout << fixed << setprecision(2); //sets the decimal places to 2.


	if (iTotalSmall > 0)

	{

		smallTotalAmount = iTotalSmall * smallSurfCost;

		cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $ " << smallTotalAmount << endl;

		totalAmountDue = totalAmountDue + smallTotalAmount;

	}

	if (iTotalMedium > 0)

	{
		mediumTotalAmount = iTotalMedium * mediumSurfCost;

		cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $ " << mediumTotalAmount << endl;

		totalAmountDue = totalAmountDue + mediumTotalAmount;


	}

	if (iTotalLarge > 0)

	{
		largeTotalAmount = iTotalLarge * largeSurfCost;

		cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $ " << largeTotalAmount << endl;

		totalAmountDue = totalAmountDue + largeTotalAmount;

	}

	if (iTotalXXXS > 0)

	{
		XXXSTotalAmount = iTotalXXXS * XXXSCost;

		cout << "The total number of XXXS surfboards is " << iTotalXXXS << " at a total of $ " << XXXSTotalAmount << endl;

		totalAmountDue = totalAmountDue + XXXSTotalAmount;

	}

	//Displaying the total amount altogether

	cout << "Amount due: $" << totalAmountDue << endl;
}

// This is the main function where we call all the other functions that are created
int main() {

	cout << setfill('*');  //setfill() fills character based on the specified character
	cout << setw(60) << "*" << endl; //setw() helps set the field width used for output operations
	cout << setfill('*');
	cout << setw(5) << "*" << " Welcome to My Johnny Utah's PointBreak Surf Shop " << setw(5) << "*" << endl;
	cout << setfill('*');
	cout << setw(60) << "*" << endl;
	cout << endl;

	ShowUsage();

	//Declaring and initializing the variables
	char userChoice, size;
	int quantity = 0;
	int quantitySmall = 0;
	int quantityMedium = 0;
	int quantityLarge = 0;
	int quantityXXXS = 0;


	//Prompt the user to enter the selection.
	cout << "\nPlease enter selection: ";
	cin >> userChoice;

	//Using a while loop to keep looping until q is typed.
	while (tolower(userChoice) != 'q') {
		if (tolower(userChoice) == 's') {
			ShowUsage();
		}
		else if (tolower(userChoice) == 'p') {
			MakePurchase(quantitySmall, quantityMedium, quantityLarge, quantityXXXS);
			cout << endl;
		}

		else if (tolower(userChoice) == 'c') {
			if (quantitySmall == 0 &&
				quantityMedium == 0 &&
				quantityLarge == 0 &&
				quantityXXXS == 0) {
				cout << "No purchase made yet." << endl;
			}
			else {
				DisplayPurchase(quantitySmall, quantityMedium, quantityLarge,quantityXXXS);
			}
		}

		else if (tolower(userChoice) == 't') {
			if (quantitySmall == 0 &&
				quantityMedium == 0 &&
				quantityLarge == 0 &&
				quantityXXXS == 0) {
				cout << "No purchase made yet." << endl;
			}
			else {
				DisplayTotal(quantitySmall, quantityMedium, quantityLarge, quantityXXXS);
			}
		}
		else {
			cout << "Invalid choice!" << endl;
		}
		cout << "\nPlease enter selection: ";
		cin >> userChoice;
	}

	cout << "Thank You" << endl;

}
