/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_ERRONEUSNICKNAME.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:59:50 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_ERRONEUSNICKNAME (432)
<nick> :<reason>
Returned after receiving a NICK message which contains a nickname
which is considered invalid, such as it's reserved ('anonymous')
or contains characters considered invalid for nicknames.
*/
std::string	ERR_ERRONEUSNICKNAME(std::string nick, std::string reason)
{
	std::stringstream	output;
	output << ":" << HOSTNAME;
	output << " 432";
	output << " " << nick;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
