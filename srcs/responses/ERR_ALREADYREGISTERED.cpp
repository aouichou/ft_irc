/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_ALREADYREGISTERED.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:57:29 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_ALREADYREGISTERED (462)
:<reason>
Returned by the server to any link which attempts to register again
*/
std::string	ERR_ALREADYREGISTRED(std::string nick, std::string reason)
{
	std::stringstream	output;
	output << ":" << HOSTNAME;
	output << " 462";
	output << " " << nick;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
