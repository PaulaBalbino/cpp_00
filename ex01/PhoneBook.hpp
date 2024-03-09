/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:39:15 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/08 17:07:58 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	Contact arrayOfContacs[8];
	int numberOfContacts;

	void printDetailedContact(int i);

public:
	PhoneBook() : numberOfContacts(0) {}

	void addContact(Contact contact);
	void search();
};

#endif

/*
#include <iomanip> setw

*/