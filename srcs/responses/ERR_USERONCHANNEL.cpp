/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_USERONCHANNEL.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:05:43 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_USERONCHANNEL (443)
<nick> <channel> [:<reason>]
Returned when a client tries to 
invite a user to a channel they're already on
*/
std::string	ERR_USERONCHANNEL(std::string nick, std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 443";
	output << " " << nick;
	output << " " << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
