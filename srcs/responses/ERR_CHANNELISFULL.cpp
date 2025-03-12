/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_CHANNELISFULL.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:58:49 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_CHANNELISFULL (471) // canJoin
<channel> :<reason>
Returned when attempting to join
a channel which is set +l and is already full
*/
std::string	ERR_CHANNELISFULL(std::string user, std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 471";
	output << " " << user;
	output << " #" << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
