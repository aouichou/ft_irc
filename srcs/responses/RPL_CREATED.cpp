/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_CREATED.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:09:10 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_CREATED (003)
:This server was created <date>
*/
std::string	RPL_CREATED()
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 003 ";
	output << ": This server was created " << CREATION_DATE;
	output << "\r\n";
	return (output.str());
}
