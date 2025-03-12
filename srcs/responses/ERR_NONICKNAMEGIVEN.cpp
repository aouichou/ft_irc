/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NONICKNAMEGIVEN.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:01:36 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NONICKNAMEGIVEN (431)
:<reason>
Returned when a nickname parameter expected for a command isn't found
*/
std::string	ERR_NONICKNAMEGIVEN(std::string reason)
{
	std::stringstream	output;
	output << ":" << HOSTNAME;
	output << " 431";
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
