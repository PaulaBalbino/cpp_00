/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:32:03 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/08 16:36:47 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName()
{
	if (firstName.length() > 9)
		return (firstName.substr(0, 9).append("."));
	else
		return (firstName);
}

std::string Contact::getLastName()
{
	if (lastName.length() > 9)
		return (lastName.substr(0, 9).append("."));
	else
		return (lastName);
}

std::string Contact::getNickname()
{
	if (nickname.length() > 9)
		return (nickname.substr(0, 9).append("."));
	else
		return (nickname);
};
