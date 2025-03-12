/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_PASSWDMISMATCH.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:04:10 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_PASSWDMISMATCH (464)
:<reason>
Returned by the PASS command to indicate the given password
was required and was either not given or was incorrect
*/
std::string	ERR_PASSWDMISMATCH(std::string nick, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 464";
	output << " " << nick;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
