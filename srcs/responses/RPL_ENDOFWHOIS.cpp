/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_ENDOFWHOIS.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/01/31 06:16:37 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*[AJOUT]*/

/*
RPL_ENDOFWHOIS (318)

"<nick> <server name> :End of /WHOIS list."

Sent as a reply to the WHOIS command, this numeric indicates the end of a WHOIS 
response for the client with the nickname <nick>.

<nick> MUST be exactly the <nick> parameter sent by the client in its WHOIS message. 
This means the case MUST be preserved, and if the client sent multiple nicks, 
this MUST be the comma-separated list of nicks, even if some of them were dropped.

This numeric is sent after all other WHOIS response numerics have been sent to the client.
*/

std::string	RPL_ENDOFWHOIS(User * _user)
{
	std::stringstream	output;

	output << _user->nick_name;
	output << " :End of /WHOIS list.";
	output << "\r\n";
	return (output.str());
}
