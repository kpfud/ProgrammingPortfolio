#include "UnitedReliefProject.h"

int main()
{
    Donations donations;
    vector<Donations> records;
    
    int choice = 0;
    string filename;

    do{
        cout << "United Cause Relief Agency Daily Donations Reports Menu \n";       // Output the menu
        cout << "======================================================= \n";
        cout << "\n      1: All by Natural Order of Input File \n";
        cout << "      2. All by Company name, Ascending \n";
        cout << "      3. All by Company name, Descending \n";
        cout << "      4. All by Category, Ascending \n";
        cout << "      5. All by Gift ID, Ascending \n";
        cout << "      6. One Donor only by Value, Descending \n";
        cout << "      0: Exit the program \n";
        cout << "\nPlease select the report you wish to be run from the menu above (1-6): \n";
        cin >> choice;

        if (choice >= 1 && choice <= 6)
        {
            cout << "Please enter the name of the file you wish to save to: \n";
            cin >> filename;
        }

        switch (choice)
        {
        case 1:
            donations.naturalOrder(filename, records);
            break;
        case 2:
            donations.sortByCompanyA(filename, records);
            break;
        case 3:
            donations.sortByCompanyD(filename, records);
            break;
        case 4:
            donations.sortByCategory(filename, records);
            break;
        case 5:
            donations.sortByGiftID(filename, records);
            break;
        case 6:
            donations.oneDonorByVal(filename, records);
            break;
        case 0:
            cout << "Exiting the program. \n";
            break;
        default:
            cout << "Invalid choice. Please try again. \n";
        }
    } while (choice != 0);
    return 0;
}


