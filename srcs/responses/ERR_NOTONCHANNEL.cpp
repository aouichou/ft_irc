/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NOTONCHANNEL.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:03:54 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NOTONCHANNEL (442)
<channel> :<reason>   Returned by the server 
whenever a client tries to perform a channel 
effecting command for which the client is not a member
*/
std::string	ERR_NOTONCHANNEL(std::string nickname, std::string channel, std::string reason)
{
	std::stringstream	output;

	(void)reason;
	output << ":" << HOSTNAME;
	output << " 442 #" << channel;
	output << " " << nickname;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
