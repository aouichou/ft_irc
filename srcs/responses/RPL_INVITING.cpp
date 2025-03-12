/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_INVITING.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:09:26 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_INVITING (341)
<nick> <channel>	
Returned by the server to indicate that the attempted INVITE
message was successful and is being passed onto the end client.
Note that RFC1459 documents the parameters in the reverse order. 
the format given here is the format used on production servers, 
and should be considered the standard reply above that given by RFC1459.
*/
std::string	RPL_INVITING(std::string userNick, std::string invitedNick, std::string channel)
{
	std::stringstream	output;

	(void)userNick;
	output << ":" << HOSTNAME;
	output << " 341";
	output << " " << userNick;
	output << " " << invitedNick;
	output << " #" << channel;
	output << "\r\n";
	return (output.str());
}
