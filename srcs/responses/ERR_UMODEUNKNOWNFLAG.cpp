/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_UMODEUNKNOWNFLAG.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:04:59 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_UMODEUNKNOWNFLAG (501)
:<reason> 
Returned by the server to indicate that a MODE 
message was sent with a nickname parameter 
and that the mode flag sent was not recognised
*/
std::string	ERR_UMODEUNKNOWNFLAG(std::string nickname, std::string reason)
{
	std::stringstream	output;

	(void)reason;
	output << ":" << HOSTNAME;
	output << " 501";
	output << " " << nickname;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
