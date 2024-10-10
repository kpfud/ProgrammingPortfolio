#include "Donations.h"

class Donations
{
public:
	string giftID,					// define class member variables
		donorName,
		phone,
		POC,
		itemDonated,
		itemCategory,
		value;

	/******************************************
	*			Donations(const string x7)	  *
	* This constructor will create the		  *
	* donations object.						  *
	* *****************************************/
	Donations() : giftID(""), donorName(""), phone(""), POC(""), itemDonated(""),
		itemCategory(""), value("")
	{
		readFileIntoVector();
	}

	/******************************************
	*		readFileIntoVector				  *
	* This function will read the file into a *
	* vector of Donations objects.			  *
	* *****************************************/
	vector<Donations> readFileIntoVector()
	{
		vector<Donations> records;
		ifstream file("donations.csv");

		if (!file.is_open())
		{
			cout << "Error: Unable to open file" << endl;
			return records;
		}

		string line;
		while (getline(file, line))
		{
			istringstream iss(line);
			string id, name, ph, poc, item, category, val;

			if (iss >> id >> name >> ph >> poc >> item >> category >> val)
			{
				records.emplace_back(id, name, ph, poc, item, category, val);
			}
			else {
				cout << "Invalid record format" << line << endl;
			}
		}

		file.close();
		return records;
	}

	/******************************************
	*			naturalOrder				  *
	* This function will write the donation	  *
	* records in the natural order contained  *
	* within the input file into a new file.  *
	* *****************************************/
	void naturalOrder(const string filename, const vector<Donations>& records)
	{
		ofstream file;
		file.open(filename);

		if (!file.is_open())
		{
			cout << "Error: Unable to open file for writing: " << filename << endl;
			return;
		}

		file << "                       United Cause Relief Agency Daily Donations \n";
		file << "                     ______________________________________________ \n";
		file << "Gift ID     Company          Phone           POC           Item Donated       Category          Value \n";
		file << "========================================================================================================== \n";

		for (int count = 0; count < records.size(); count++)
		{
			file << records[count].giftID << "   " << records[count].donorName << "   " << records[count].phone << "   "
				<< records[count].POC << "   " << records[count].itemDonated << "   " << records[count].itemCategory << "   "
				<< records[count].value << "\n";
		}

		cout << "Records written to file successfully. \n";
		file.close();
	}

	/*********************************************
	*				sortByCompanyA				 *
	* This function will sort the donations by   *
	* company name in ascending order and write  *
	* them to a file.							 *
	* ********************************************/
	void sortByCompanyA(const string filename, const vector<Donations>& records)
	{
		bool swapped;

		do
		{
			swapped = false;
			for (int count = 0; count < records.size() - 1; count++)
			{
				if (records[count].donorName < records[count + 1].donorName)
				{
					swap(records[count].giftID, records[count + 1].giftID);
					swap(records[count].donorName, records[count + 1].donorName);
					swap(records[count].phone, records[count + 1].phone);
					swap(records[count].POC, records[count + 1].POC);
					swap(records[count].itemDonated, records[count + 1].itemDonated);
					swap(records[count].itemCategory, records[count + 1].itemCategory);
					swap(records[count].value, records[count + 1].value);

					swapped = true;
				}
			}
		} while (swapped);

		ofstream file;
		file.open(filename);

		if (!file.is_open())
		{
			cout << "Error: Unable to open file for writing: " << filename << endl;
			return;
		}

		file << "                       United Cause Relief Agency Daily Donations \n";
		file << "                     ______________________________________________ \n";
		file << "Gift ID     Company          Phone           POC           Item Donated       Category          Value \n";
		file << "========================================================================================================== \n";

		for (int count = 0; count < records.size(); count++)
		{
			file << records[count].giftID << "   " << records[count].donorName << "   " << records[count].phone << "   "
				<< records[count].POC << "   " << records[count].itemDonated << "   " << records[count].itemCategory << "   "
				<< records[count].value << "\n";
		}

		cout << "Records written to file successfully. \n";
		file.close();
	}

	/*********************************************
	*				sortByCompanyD				 *
	* This function will sort the donations by   *
	* company name in descending order and write *
	* them to a file.							 *
	* ********************************************/
	void sortByCompanyD(const string filename, const vector<Donations> records)
	{
		bool swapped;

		do
		{
			swapped = false;
			for (int count = 0; count < records.size() - 1; count++)
			{
				if (records[count].donorName > records[count + 1].donorName)
				{
					swap(records[count].giftID, records[count + 1].giftID);
					swap(records[count].donorName, records[count + 1].donorName);
					swap(records[count].phone, records[count + 1].phone);
					swap(records[count].POC, records[count + 1].POC);
					swap(records[count].itemDonated, records[count + 1].itemDonated);
					swap(records[count].itemCategory, records[count + 1].itemCategory);
					swap(records[count].value, records[count + 1].value);

					swapped = true;
				}
			}
		} while (swapped);

		ofstream file;
		file.open(filename);

		if (!file.is_open())
		{
			cout << "Error: Unable to open file for writing: " << filename << endl;
			return;
		}

		file << "                       United Cause Relief Agency Daily Donations \n";
		file << "                     ______________________________________________ \n";
		file << "Gift ID     Company          Phone           POC           Item Donated       Category          Value \n";
		file << "========================================================================================================== \n";

		for (int count = 0; count < records.size(); count++)
		{
			file << records[count].giftID << "   " << records[count].donorName << "   " << records[count].phone << "   "
				<< records[count].POC << "   " << records[count].itemDonated << "   " << records[count].itemCategory << "   "
				<< records[count].value << "\n";
		}

		cout << "Records written to file successfully. \n";
		file.close();
	}

	/*********************************************
	*				sortByCategory				 *
	* This function will sort the donations by   *
	* company name in ascending order and write  *
	* them to a file.							 *
	* ********************************************/
	void sortByCategory(const string filename, const vector<Donations> records)
	{
		bool swapped;

		do
		{
			swapped = false;
			for (int count = 0; count < records.size() - 1; count++)
			{
				if (records[count].itemCategory < records[count + 1].itemCategory)
				{
					swap(records[count].giftID, records[count + 1].giftID);
					swap(records[count].donorName, records[count + 1].donorName);
					swap(records[count].phone, records[count + 1].phone);
					swap(records[count].POC, records[count + 1].POC);
					swap(records[count].itemDonated, records[count + 1].itemDonated);
					swap(records[count].itemCategory, records[count + 1].itemCategory);
					swap(records[count].value, records[count + 1].value);

					swapped = true;
				}
			}
		} while (swapped);

		ofstream file;
		file.open(filename);

		if (!file.is_open())
		{
			cout << "Error: Unable to open file for writing: " << filename << endl;
			return;
		}

		file << "                       United Cause Relief Agency Daily Donations \n";
		file << "                     ______________________________________________ \n";
		file << "Gift ID     Company          Phone           POC           Item Donated       Category          Value \n";
		file << "========================================================================================================== \n";

		for (int count = 0; count < records.size(); count++)
		{
			file << records[count].giftID << "   " << records[count].donorName << "   " << records[count].phone << "   "
				<< records[count].POC << "   " << records[count].itemDonated << "   " << records[count].itemCategory << "   "
				<< records[count].value << "\n";
		}

		cout << "Records written to file successfully. \n";
		file.close();
	}

	/*********************************************
	*				sortByGiftID				 *
	* This function will sort the donations by   *
	* company name in ascending order and write  *
	* them to a file.							 *
	* ********************************************/
	void sortByGiftID(const string filename, const vector<Donations> records)
	{
		bool swapped;

		do
		{
			swapped = false;
			for (int count = 0; count < records.size() - 1; count++)
			{
				if (records[count].giftID < records[count + 1].giftID)
				{
					swap(records[count].giftID, records[count + 1].giftID);
					swap(records[count].donorName, records[count + 1].donorName);
					swap(records[count].phone, records[count + 1].phone);
					swap(records[count].POC, records[count + 1].POC);
					swap(records[count].itemDonated, records[count + 1].itemDonated);
					swap(records[count].itemCategory, records[count + 1].itemCategory);
					swap(records[count].value, records[count + 1].value);

					swapped = true;
				}
			}
		} while (swapped);

		ofstream file;
		file.open(filename);

		if (!file.is_open())
		{
			cout << "Error: Unable to open file for writing: " << filename << endl;
			return;
		}

		file << "                       United Cause Relief Agency Daily Donations \n";
		file << "                     ______________________________________________ \n";
		file << "Gift ID     Company          Phone           POC           Item Donated       Category          Value \n";
		file << "========================================================================================================== \n";

		for (int count = 0; count < records.size(); count++)
		{
			file << records[count].giftID << "   " << records[count].donorName << "   " << records[count].phone << "   "
				<< records[count].POC << "   " << records[count].itemDonated << "   " << records[count].itemCategory << "   "
				<< records[count].value << "\n";
		}

		cout << "Records written to file successfully. \n";
		file.close();
	}

	/*********************************************
	*					oneDonorByVal			 *
	* This function will sort the donations by   *
	* company name in ascending order and write  *
	* them to a file.							 *
	* ********************************************/
	void oneDonorByVal(const string filename, const vector<Donations> records)
	{
		vector<string> uniqueDonorNames;
		for (int count = 0; count < records.size(); count++)
		{
			bool isUnique = true;

			for (int index = 0; index < uniqueDonorNames.size(); index++)
			{
				if (records[count].donorName == uniqueDonorNames[count])
				{
					isUnique = false;
					break;
				}
			}

			if (isUnique)
				uniqueDonorNames.push_back(records[count].donorName);
		}

		int menuNumber = 1;
		for (int count = 0; count < records.size(); count++)
		{
			cout << menuNumber << ". " << donorName[count] << "\n";
			menuNumber++;
		}
		int choice;
		cout << "Choose a donor: ";
		cin >> choice;
		string donorChoice = uniqueDonorNames[choice - 1];

		ofstream file;
		file.open(filename);

		if (!file.is_open())
		{
			cout << "Error: Unable to open file for writing: " << filename << endl;
			return;
		}

		file << "                       United Cause Relief Agency Daily Donations \n";
		file << "                     ______________________________________________ \n";
		file << "Gift ID     Company          Phone           POC           Item Donated       Category          Value \n";
		file << "========================================================================================================== \n";

		for (int count = 0; count < records.size(); count++)
		{
			if (records[count].donorName == donorChoice)
			{
				file << records[count].giftID << "   " << records[count].donorName << "   " << records[count].phone << "   "
					<< records[count].POC << "   " << records[count].itemDonated << "   " << records[count].itemCategory << "   "
					<< records[count].value << "\n";
			}
		}

		cout << "Records written to file successfully. \n";
		file.close();
	}
};

