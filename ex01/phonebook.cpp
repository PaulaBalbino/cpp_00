/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:28:57 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/06 21:47:20 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

class Contact
{
public:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string getFirstName()
	{
		if (firstName.length() > 9)
			return (firstName.substr(0, 9).append("."));
		else
			return (firstName);
	}

	std::string getLastName()
	{
		if (lastName.length() > 9)
			return (lastName.substr(0, 9).append("."));
		else
			return (lastName);
	}

	std::string getNickname()
	{
		if (nickname.length() > 9)
			return (nickname.substr(0, 9).append("."));
		else
			return (nickname);
	}
};

bool is_number(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}
int stringToInt(const std::string &str)
{
	std::istringstream iss(str);
	int result;
	iss >> result;
	return result;
}
class PhoneBook
{
private:
	Contact arrayOfContacs[8];
	int numberOfContacts;

	void printDetailedContact(int i)
	{
		std::cout << "First Name: " << arrayOfContacs[i].firstName << std::endl
				  << "Last Name: " << arrayOfContacs[i].lastName << std::endl
				  << "Nickame: " << arrayOfContacs[i].nickname << std::endl
				  << "Phone: " << arrayOfContacs[i].phoneNumber << std::endl
				  << "Darkest Secret: " << arrayOfContacs[i].darkestSecret << std::endl;
	}

public:
	PhoneBook() : numberOfContacts(0) {}

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
		std::string index;
		if (numberOfContacts == 0)
		{
			std::cout << "No contact to display. Add at least one contact" << std::endl;
			return;
		}
		std::string column1 = "Index";
		std::string column2 = "First Name";
		std::string column3 = "Last Name";
		std::string column4 = "Nickname";

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
		int indexmax = 8; // para nao criar um else adicional

		if (numberOfContacts < 8)
			indexmax = numberOfContacts;

		while (i < indexmax)
		{
			std::cout << std::setw(10) << i << " | "
					  << std::setw(10) << arrayOfContacs[i].getFirstName() << " | "
					  << std::setw(10) << arrayOfContacs[i].getLastName() << " | "
					  << std::setw(10) << arrayOfContacs[i].getNickname() << std::endl;

			std::cout << std::string(10, '-') << " | "
					  << std::string(10, '-') << " | "
					  << std::string(10, '-') << " | "
					  << std::string(10, '-') << std::endl;
			i++;
		}
		std::cout << std::string("Type an index to display contact details: ");
		std::getline(std::cin, index);
		if (is_number(index) && stringToInt(index) < (indexmax % 8))
			printDetailedContact(stringToInt(index));
		else
			std::cout << std::string("INVALID OPTION") << std::endl;;
	}
};

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
		std::cout << "Please enter the phone number (only numbers): " << std::endl;
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
			return (0);

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

/*
Criar um PhoneBook com 8 contatos, ao criar o nono, o primeiro eh subscrito;
- alocacao dinamica nao e permitida;
- criar Contact cla

*/
