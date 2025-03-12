/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_TOOMANYTARGETS.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:04:32 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_TOOMANYTARGETS (407)
<target> :<reason> 
The given target(s) for a
command are ambiguous in that they relate to too many targets
*/
std::string	ERR_TOOMANYTARGETS(std::string target, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 407";
	output << " " << target;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
