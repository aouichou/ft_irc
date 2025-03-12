/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_KEYSET.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:00:36 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_KEYSET (467)
<channel> :<reason>
Returned when the channel key for a 
channel has already been set 
*/
std::string	ERR_KEYSET(std::string nickname, std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 467 #" << channel;
	output << " " << nickname;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
