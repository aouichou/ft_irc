/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_UNKNOWNMODE.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:05:20 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_UNKNOWNMODE (472)
<char> :<reason>
Returned when a given mode is unknown 
*/
std::string	ERR_UNKNOWNMODE(std::string user, std::string channel, char c, std::string reason)
{
	std::stringstream	output;
	(void)user;
	(void)channel;
	output << ":" << HOSTNAME;
	output << " 472";
	output << " #" << channel;
	//output << " " << user;
	output << " " << c;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
