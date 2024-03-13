/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:39:20 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/10 17:08:15 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"

	void PhoneBook::printDetailedContact(int i)
	{
		arrayOfContacs[i].printDetails();
	}

	void PhoneBook::addContact(Contact contact)
	{
		if (numberOfContacts < 8)
			arrayOfContacs[numberOfContacts] = contact;

		else
			arrayOfContacs[numberOfContacts % 8] = contact;
		numberOfContacts++;
	}

	void PhoneBook::search()
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
		if (Utils::is_number(index) && Utils::stringToInt(index) < (indexmax % 8))
			printDetailedContact(Utils::stringToInt(index));
		else
			std::cout << std::string("INVALID OPTION") << std::endl;
	}
