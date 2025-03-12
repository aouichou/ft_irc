/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KICK.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:06:28 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
KICK
*/
std::string	KICK(std::string user, std::string channel, std::string kickedUser, std::string reason)
{
	std::stringstream	output;

	output << ":" <<  user;
	output << " KICK ";
	output << "#" << channel;
	output << " " << kickedUser;
	output << " " << reason;
	output << "\r\n";
	return (output.str());
}
