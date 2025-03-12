/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NICKNAMEINUSE.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:01:13 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NICKNAMEINUSE (433)
<nick> :<reason>
Returned by the NICK command when the given nickname is already in use
*/
std::string	ERR_NICKNAMEINUSE(std::string nick, std::string reason)
{
	std::stringstream	output;
	(void)nick;
	output << ":" << HOSTNAME;
	output << " 433";
	output << " * " << nick;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
