#include <iostream>
using namespace std;

int main()
{
	unsigned card_id;

	cout << "Card ID: ";
	cin >> card_id;

	int card_version = card_id / 100000000;
	int owner_spec = (card_id % 10000000) / 1000000;
	int owner_id = (card_id % 1000000) / 10;


	if (card_id < 0 || card_version > 9 || card_version < 1 || owner_spec > 8 || owner_spec == 7 || owner_id == 0)
	{
		cout << "Invalid card number!" << endl;

		return 1;
	}


	cout << "Card Version: " << card_version << endl;


	switch (owner_spec)
	{
	case 0:
		cout << "Specialty: Informatics";
		break;
	case 1:
		cout << "Specialty: Computer Sciences";
		break;
	case 2:
		cout << "Specialty: IT Systems";
		break;
	case 3:
		cout << "Specialty: Software Engeneering";
		break;
	case 4:
		cout << "Specialty: Applied Mathematics";
		break;
	case 5:
		cout << "Specialty: Mathematics";
		break;
	case 6:
		cout << "Specialty: Statistics";
		break;
	case 8:
		cout << "Specialty: Maths and IT";
		break;
	}
	cout << endl;


	cout << "Owner ID: " << owner_id << endl;

	return 0;
}