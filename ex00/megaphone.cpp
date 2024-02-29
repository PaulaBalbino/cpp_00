/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:11:40 by pbalbino          #+#    #+#             */
/*   Updated: 2024/02/29 15:18:15 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main (int ac, char **av)
{
	int	i = 1;
	int	j = 0;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (ac > 1)
	{
		while (ac > 1)
		{
			std::string word = av[i];
				while (word[j] != 0)
				{
					std::cout << char(std::toupper(word[j]));
					j++;
				}
			i++;
			ac--;
			j = 0;
		}

	}
	std::cout << std::endl;
	return (0);
}



/*

Just to make sure that everybody is awake, write a program that behaves as follows:

$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>

#include <string> std::string.
#include <cctype> std::toupper.

*/
