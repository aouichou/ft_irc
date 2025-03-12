/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_INVITEONLYCHAN.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:00:15 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_INVITEONLYCHAN (473) //canJoin
<channel> :<reason>
Returned when attempting to join a channel which is invite only without an invitation
*/
std::string	ERR_INVITEONLYCHAN(std::string nickname, std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 473";
	output << " " << nickname;
	output << " #" << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
