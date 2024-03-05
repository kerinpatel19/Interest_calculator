#include <iostream>
#include <iterator>
#include <iomanip>
using namespace std;

// declare all goble variables needed 

double startDeposit = 0.0;
double MonthlyDeposit = 0.0;
double AnnualInterest = 0.0;
int numYears = 0;
int numMonths = 12;
double AccountBalance = 0.0;
double curr_month_interest = 0.0;



// print line after the header function 

void PrintLine (int current_year, double yearEnd, double earnedInterest){
    // set the output to 0.00
    cout << fixed << setprecision(2);
    // print line with all info and boders
    cout << "   |"<< current_year << "|\t\t\t  |$" << yearEnd << " |\t\t\t | $" << earnedInterest << " |"<<endl; 
    fill_n(ostream_iterator<char>(cout), 70, '-');
    cout << endl;
}

void Calculate_Interest(double startDeposit, double MonthlyDeposit, double AnnualInterest){
    // assine current month interest to the next months interes 
    // calcualte interest (current account + monthly deposit)*((interst rate/100/12))
    curr_month_interest = (startDeposit + MonthlyDeposit) * ((AnnualInterest/100)/12);
    // update account blance
    AccountBalance = AccountBalance + MonthlyDeposit + curr_month_interest;
    
}

void StartMenu() {
    // Print '*' 60 times in the same line
    fill_n(ostream_iterator<char>(cout), 70, '*');
    cout << endl;
    fill_n(ostream_iterator<char>(cout), 29, '*');
    cout << " Data Input ";
    fill_n(ostream_iterator<char>(cout), 29, '*');
    cout << endl;
    // get input for starting variables
    cout << "Initial Investment Amount :- $";
    cin >> startDeposit;
    cout << endl;
    cout << "Monthly deposit Amount :- $";
    cin >> MonthlyDeposit;
    cout << endl;
    cout << "Annual Interest :- %";
    cin >> AnnualInterest;
    cout << endl;
    cout << "Number of years :- ";
    cin >> numYears;
    cout << endl;
    // print choices so we can tell where the account started
    fill_n(ostream_iterator<char>(cout), 70, '*');
    cout << endl;
    cout << "Initial Investment Amount :- $" << startDeposit << endl;
    cout << "Monthly deposit Amount :- $" << MonthlyDeposit << endl;
    cout << "Annual Interest :- %" << AnnualInterest << endl;
    cout << "Number of years :- " << numYears << endl;

    // check if the monthly deposit is more than $0 and print screen based on it
    fill_n(ostream_iterator<char>(cout), 70, '*');
    cout << endl;
    cout << "\n\n\n\n\n";
    if (MonthlyDeposit > 0) {
        cout << "\t Balance and interest with Additional Monthly Deposit" << endl;
    }
    else{
        cout << "\t Balance and interest without Additional Monthly Deposit" << endl;
    }
    // print table header
    fill_n(ostream_iterator<char>(cout), 70, '=');
    cout << "\n\n" ;
    cout << "  Year\t\t Year End Balance\t Year End Earned Interest" << endl;
    fill_n(ostream_iterator<char>(cout), 70, '-');
    cout << "\n\n";
    AccountBalance = startDeposit;
    Calculate_Interest(startDeposit, MonthlyDeposit, AnnualInterest);
}

int main() {
    // i trackes of the current year
    int i = 1;
    // get all starting variables
    StartMenu();
    // year 1 balance printed prior to main loop
    PrintLine (i,AccountBalance,curr_month_interest);
    //main loop untill the current year == end year
    while (i != numYears){
        // 1 after each print line
        i = i +1;
        // calculate interest and print line
        Calculate_Interest(AccountBalance, MonthlyDeposit, AnnualInterest);
        PrintLine(i,AccountBalance,curr_month_interest);
    }
    return 0;
}