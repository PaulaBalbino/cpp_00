/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:00:58 by pbalbino          #+#    #+#             */
/*   Updated: 2024/03/10 16:43:48 by pbalbino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

class Utils
{
public:
static bool is_number(const std::string &str);
static int stringToInt(const std::string &str);
static int containsOnlySpaces(const std::string str);
};



#endif