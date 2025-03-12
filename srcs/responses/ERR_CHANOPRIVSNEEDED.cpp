/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_CHANOPRIVSNEEDED.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:59:09 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_CHANOPRIVSNEEDED : 
Returned by any command requiring special channel 
privileges (eg. channel operator) to indicate 
the operation was unsuccessfull
*/
std::string	ERR_CHANOPRIVSNEEDED(std::string nickname, std::string channel, std::string reason)
{
	std::stringstream	output;

	(void)reason;
	output << ":" << HOSTNAME;
	output << " 482 #" << channel;
	output << " " << nickname;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
