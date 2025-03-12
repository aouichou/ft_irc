/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NOTEXTTOSEND.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:03:35 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NOTEXTTOSEND (412)
:<reason>
Returned when NOTICE/PRIVMSG is used with no message given
*/
std::string	ERR_NOTEXTTOSEND(std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 412";
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
