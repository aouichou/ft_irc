/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_CANNOTSENDTOCHAN.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:58:31 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_CANNOTSENDTOCHAN (404)
<channel> :<reason>	
Sent to a user who does not have the rights
to send a message to a channel
*/
std::string	ERR_CANNOTSENDTOCHAN(std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 404";
	output << " " << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
