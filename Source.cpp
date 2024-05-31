#include<iostream>
#include<string>

std::string XOR_calculator(std::string str1, std::string str2)
{
	std::string result = "";
	for (int i = 0; i < str1.length(); ++i)
	{
		result.append(1, (str1[i] - '0') ^ (str2[i] - '0') + 48);
	}
	return result;
}

std::string CRC(std::string mesaj_Initial, std::string polinom)
{
	if (mesaj_Initial.length() <= polinom.length())
		return "Mesajul este prea scurt";

	for (int i = 0; i < mesaj_Initial.length(); ++i)
	{
		if (mesaj_Initial[i] != '0' && mesaj_Initial[i] != '1')
			return "Mesajul nu este binar";
	}

	for (int i = 0; i < polinom.length(); ++i)
	{
		if (polinom[i] != '0' && polinom[i] != '1')
			return "Coeficientii polinomului nu sunt binare";
	}

	std::string mesaj_de_trimis = "";
	std::string mesaj_Extins = mesaj_Initial.append(polinom.length() - 1, '0');

	std::cout << "Rezultatele intermediare: \n";

	while (mesaj_Initial.length() >= polinom.length())
	{
		if (mesaj_Initial[0] == '0')
		{
			mesaj_Initial.erase(0, 1);
			continue;
		}
		std::cout << mesaj_Initial.replace(0, polinom.length(), XOR_calculator(polinom, mesaj_Initial.substr(0, polinom.length()))) << "\n";
	}
	
	std::cout << mesaj_Initial << "\n";
	std::cout << "-----------------------------------\n";
	std::string mesaj_Initial_toShow = mesaj_Initial;
	std::cout << mesaj_Extins << "\n" << mesaj_Initial_toShow.insert(0, mesaj_Extins.length() - polinom.length() + 1, ' ') << "\n";
	std::cout << "-----------------------------------\n";
	
	mesaj_de_trimis = mesaj_Extins.replace(mesaj_Extins.length() - polinom.length() + 1, polinom.length() - 1, 
										    XOR_calculator(mesaj_Extins.substr(mesaj_Extins.length() - polinom.length() + 1, polinom.length() - 1), mesaj_Initial));

	return mesaj_de_trimis;
}

void main()
{
	std::cout << "Mesaj de trimis: \n" << CRC("1100010110011", "1011") << "\n\n";
	std::cout << "Verificare: \n" << CRC("1100010110011110", "1011");
}