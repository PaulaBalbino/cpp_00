
#include <iostream>
#include <iomanip>
#include <string>


class Contact
{
public:
	std::string firstName;
	std::string lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

class PhoneBook
{
private:
	Contact arrayOfContacs[8];
	int numberOfContacts;

public:

void addContact(Contact contact)
{
	if (numberOfContacts < 8)
		arrayOfContacs[numberOfContacts] = contact;

	else
		arrayOfContacs[numberOfContacts % 8] = contact;
	numberOfContacts++;
}

void search()
{
	if (numberOfContacts == 0)
	{
		std::cout << "No contact to display. Add at least one contact" << std::endl;
		return;
	}
	std::string column1 = "index";
	std::string column2 = "first name";
	std::string column3 = "last name";
	std::string column4 = "nickname";

	// Print header
	std::cout << std::setw(10) << column1 << " | "
			  << std::setw(10) << column2 << " | "
			  << std::setw(10) << column3 << " | "
			  << std::setw(10) << column4 << std::endl;

	// Print separator
	std::cout << std::string(10, '-') << " | "
			  << std::string(10, '-') << " | "
			  << std::string(10, '-') << " | "
			  << std::string(10, '-') << std::endl;

	// Print data
	int i = 0;
	int indexmax = 0;

	if (this->numberOfContacts < 8)
		indexmax = this->numberOfContacts;
	else
		indexmax = this->numberOfContacts % 8;

	while (i < indexmax)
	{
		std::cout << std::setw(10) << i << " | "
				  << std::setw(10) << arrayOfContacs[i].firstName << " | "
				  << std::setw(10) << arrayOfContacs[i].lastName << " | "
				  << std::setw(10) << arrayOfContacs[i].nickname << std::endl;

		std::cout << std::string(10, '-') << " | "
				  << std::string(10, '-') << " | "
				  << std::string(10, '-') << " | "
				  << std::string(10, '-') << std::endl;
		i++;
	}
}


};

bool is_number(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

Contact ft_add(void)
{

	Contact person;

		while (person.firstName.empty())
		{
			std::cout << "Please enter the first name: " << std::endl;
			std::getline(std::cin, person.firstName);
		}

		std::string lastName;
		while (person.lastName.empty())
		{
			std::cout << "Please enter the last name: " << std::endl;
			std::getline(std::cin, person.lastName);
		}

		std::string nickname;
		while (person.nickname.empty())
		{
			std::cout << "Please enter the nickname: " << std::endl;
			std::getline(std::cin, person.nickname);
		}

		while (person.phoneNumber.empty() || is_number(person.phoneNumber) == false)
		{
			std::cout << "Please enter the phone number (only numbers): " << std::endl;;
			std::getline(std::cin, person.phoneNumber);

			if (is_number(person.phoneNumber) == false)
				std::cout << "Phone Number contains non digit numbers" << std::endl;
		}

		std::string darkestSecret;
		while (person.darkestSecret.empty())
		{
			std::cout << "Write the darkest secret of the contact:" << std::endl;
			std::getline(std::cin, person.darkestSecret);
		}

	return (person);
}


void ft_exit()
{
	return;
}

int main()
{
	PhoneBook phoneBook;
	std::string input;
	while (1)
	{
	std::cout << "Please enter ADD to save a new contact" << std::endl;
	std::cout << "Please enter SEARCH to display a specific contact" << std::endl;
	std::cout << "Please enter EXIT to display a specific contact" << std::endl;
	std::getline(std::cin, input);

	if (input == "ADD")
		phoneBook.addContact(ft_add());

	else if (input == "SEARCH")
		phoneBook.search();

	else if (input == "EXIT")
		ft_exit();

	else
		std::cout << "INVALID INPUT" << std::endl;
	}
	return (0);
}

/*
SEARCH:

A função std::setw() é uma função de manipulação de fluxo em C++ que faz parte da biblioteca <iomanip>.
Ela é usada para definir a largura do campo para a próxima saída formatada no fluxo de saída.

Por exemplo, ao usar std::setw(10), você está especificando que o próximo item que será enviado para o
fluxo de saída deve ter uma largura de campo de 10 caracteres.

Isso é comumente usado para alinhar colunas ao imprimir tabelas ou formatar saída de dados de maneira
organizada.



SHOULD I USE std::cin.ignore(); // Ignore the newline character left in the input buffer ???

*/