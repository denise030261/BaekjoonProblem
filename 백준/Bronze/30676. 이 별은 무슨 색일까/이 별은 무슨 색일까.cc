#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int wavelength;
	cin >> wavelength;

	if (wavelength >= 380 && wavelength < 425)
		cout << "Violet";
	else if (wavelength >= 425 && wavelength < 450)
		cout << "Indigo";
	else if (wavelength >= 450 && wavelength < 495)
		cout << "Blue";
	else if (wavelength >= 495 && wavelength < 570)
		cout << "Green";
	else if (wavelength >= 570 && wavelength < 590)
		cout << "Yellow";
	else if (wavelength >= 590 && wavelength < 620)
		cout << "Orange";
	else if (wavelength >= 620 && wavelength <= 780)
		cout << "Red";

		
}