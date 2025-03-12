/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_BADCHANNELKEY.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:57:46 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_BADCHANNELKEY (475) //canJoin
<channel> :<reason>
Returned when attempting to join a key-locked
channel either without a key or with the wrong key
*/
std::string	ERR_BADCHANNELKEY(std::string user,std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 475";
	output << " " << user;
	output << " #" << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
