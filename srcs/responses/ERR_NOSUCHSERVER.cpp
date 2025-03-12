/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NOSUCHSERVER.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:34:21 by juchene           #+#    #+#             */
/*   Updated: 2024/01/31 05:49:12 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*[AJOUT]*/

/*
ERR_NOSUCHSERVER (402) 

"<client> <server name> :No such server"
Indicates that the given server name does not exist. The text used in the last param of this message may vary.

*/

std::string	ERR_NOSUCHSERVER(std::string server, std::string reason)
{
	std::stringstream	output;
	output << server;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}