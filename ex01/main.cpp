/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:28:57 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/08 17:15:16 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Utils.hpp"
#include <iostream>

Contact ft_add(void)
{
	Contact person;

	while (person.firstName.empty() ||
			Utils::containsOnlySpaces(person.firstName.c_str()) == 1)
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

	while (person.phoneNumber.empty() ||
		Utils::is_number(person.phoneNumber) == false)
	{
		std::cout << "Please enter the phone number (only numbers): " << std::endl;
		std::getline(std::cin, person.phoneNumber);

		if (Utils::is_number(person.phoneNumber) == false)
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

		if (!std::getline(std::cin, input))
		{
			// handle control-d
			std::cout << "Exiting program..." << std::endl;
			break;
		}

		if (input == "ADD")
			phoneBook.addContact(ft_add());

		else if (input == "SEARCH")
			phoneBook.search();

		else if (input == "EXIT")
			break;

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
