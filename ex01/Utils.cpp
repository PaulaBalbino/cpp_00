/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:00:55 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/13 20:23:43 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <sstream>

bool Utils::is_number(const std::string &str)
{
	std::string::const_iterator it = str.begin();
	while (it != str.end() && std::isdigit(*it))
		++it;
	return !str.empty() && it == str.end();
}

int Utils::stringToInt(const std::string &str)
{
	std::istringstream iss(str);
	int result;
	iss >> result;
	return result;
}

int Utils::containsOnlySpaces(const std::string str)
{
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] != ' ') {
			return (0);
		}
	}
	return (1);
}

/*
#include <sstream> : iss
*/