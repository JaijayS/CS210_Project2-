#include <iostream>
#include <iomanip>

using namespace std;


// Function Declarations 
void ContinuationLoop();
void InitialDisplay(); 
void WithoutMonthlyDeposit(double amount, double interest, int years); 
void WithMonthlyDeposit(double amount, double deposit, double interest, int years);


// WithoutMonthly Deposit function 
void WithoutMonthlyDeposit(double amount, double interest, int years) {
    
    // Declared Variables 
    double monthlyInterest; 
    double months = years * 12; 
    double yearlyInterest = 0;
    int year = 1; 

    // Output Table Title 
    cout << endl << endl;
    cout << "      Balance and Interest Without Additional Monthly Deposits" << endl; 
    cout << "====================================================================" << endl;
    cout << right << setw(12) <<"Year" << right << setw(28) << "Year End Balance " << right << setw(27) << "Year End Earned Interest " << endl;
    cout << "--------------------------------------------------------------------" << endl;
        
    // For loop to calcuate/ cycle through each year 
    for (int i = 1; i <= months; i++) 
    {

        monthlyInterest = (amount) * ((interest / 100) / 12);
        amount =  amount  + monthlyInterest;
        yearlyInterest += monthlyInterest; 

        // If month divided by 12 = 0, then that is 1+ years. Output for each year. 
        if (i % 12 == 0) 
        {

            cout << '|' << right << setw(10) << year  << fixed << setprecision(2) << right << setw(12) << '|' << right << setw(10) << '$' << amount << right << setw(10) << '|' << right << setw(10) << '$' << yearlyInterest << right << setw(11) << '|' << endl;
            yearlyInterest = 0; 
            year++; 
            cout << "--------------------------------------------------------------------" << endl;
        }
    }

}


// WithMonthlyDeposit Function
void WithMonthlyDeposit(double amount, double deposit, double interest, int years) {


    // Delcared Variables 
    double monthlyInterest;
    double months = years * 12; 
    double yearlyInterest = 0; 
    int year = 1; 


    // Output Table Title
    cout << endl << endl;
    cout << "          Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "===========================================================================" << endl;
    cout << right << setw(12) << "Year" << right << setw(33) << "Year End Balance " << right << setw(31) << "Year End Earned Interest " << endl;
    cout << "---------------------------------------------------------------------------" << endl;


    // For loop to calcuate/ cycle through each year 
    for (int i = 1; i <= months; i++) 
    {

        monthlyInterest = (amount + deposit) * ((interest / 100) / 12);
        amount =  amount + deposit + monthlyInterest;
        yearlyInterest += monthlyInterest; 


        // If month divided by 12 = 0, then that is 1+ years. Output for each year. 
        if (i % 12 == 0) 
        {

            // Lots of if statements to align text as best as possible. 
            if (year < 10){

                cout << '|' << right << setw(10) << year << setw(13) << '|';

            }
            else {

                cout << '|' << right << setw(11) << year << setw(12) << '|';

            }
            if (amount < 10) {

                cout <<  fixed << setprecision(2)  << right << setw(13) << '$' << amount << right << setw(10) << '|'; 

            }
            else if (amount < 100) {

                cout << fixed << setprecision(2) << right << setw(12) << '$' << amount << right << setw(10) << '|'; 

            }
            else if (amount < 1000) {

                cout << fixed << setprecision(2) << right << setw(11) << '$' << amount << right << setw(10) << '|';

            }
            else if (amount < 10000){

                cout << fixed << setprecision(2) << right << setw(10) << '$' << amount << right << setw(10) << '|';

            }
            else if (amount < 100000) {

                cout << fixed << setprecision(2) << right << setw(9) << '$' << amount << right << setw(10) << '|';

            }
            else if (amount < 1000000) {

                cout << fixed << setprecision(2) << right << setw(8) << '$' << amount << right << setw(10) << '|';

            }

            if (yearlyInterest < 10) {

                cout << right << setw(12) << '$' << yearlyInterest << right << setw(10) <<'|' << endl;

            }
            else if (yearlyInterest < 100) {

                cout << right << setw(11) << '$' << yearlyInterest << right << setw(10) << '|' << endl;

            }
            else if (yearlyInterest < 1000) {

                cout << right << setw(10) << '$' << yearlyInterest << right << setw(10) << '|' << endl;

            }
            else if (yearlyInterest < 10000) {

                cout << right << setw(9) << '$' << yearlyInterest << right << setw(10) << '|' << endl;


            }
            else if (yearlyInterest < 100000) {

                cout << right << setw(8) << '$' << yearlyInterest << right << setw(10) << '|' << endl;

            }
            else if (yearlyInterest < 1000000) {

                cout << right << setw(7) << '$' << yearlyInterest << right << setw(10) << '|' << endl;

            }

            yearlyInterest = 0;
            year++;

            cout << "---------------------------------------------------------------------------" << endl;

        }
    }


    // Call on Continuation loop so that user can have multiple attempts on program if needed.
    ContinuationLoop();

}


// Function that controls the initial display screen
void InitialDisplay() {


    // Declaring variables
    double initialAmount;
    double monthlyDeposit;
    double interestRate;
    int years;


    // Formatting of output for user readability
    cout << "*********************************" << endl;
    cout << "********** Data Input ***********" << endl;
    cout << "Initial Investment Amount: ";
    cin >> initialAmount;
    cout << "Monthly Desposit: ";
    cin >> monthlyDeposit;
    cout << "Annual Interest: ";
    cin >> interestRate;
    cout << "Number of years: ";
    cin >> years;


    // Pause program until user input to continue 
    system("pause");


    // Call on the function to calcuate and display the interests. 
    WithoutMonthlyDeposit(initialAmount, interestRate, years);
    WithMonthlyDeposit(initialAmount, monthlyDeposit, interestRate, years);

}


// While loop function to continue program if user wants to. 
void ContinuationLoop() {
    
    char answer = 'n'; 

    cout << "Would you like to try again? Y/N " << endl;
    cin >> answer;
    while (answer != 'y' && answer != 'Y') {
        
        if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'Y') {

            cout << "Invalid response" << endl;
            ContinuationLoop(); 

        }
        else {

            system("cls");
            cout << "  Thank you for choosing AIRGEAD BANKING." << endl;
            cout << "   Where we are invested in YOUR future!" << endl << endl;
            exit(0);

        }
    }

    cout << endl << endl; 
    system("cls");
    InitialDisplay(); 

}   


int main()
{
    // Call on Initial Display function to begin program. 
        InitialDisplay();

}