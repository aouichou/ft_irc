/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_ENDOFWHO.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:00:27 by aouichou          #+#    #+#             */
/*   Updated: 2024/02/02 05:56:32 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*RPL_ENDOFWHO
			  "<name> :End of WHO list"

		 - The RPL_WHOREPLY and RPL_ENDOFWHO pair are used
		   to answer a WHO message.  The RPL_WHOREPLY is only
		   sent if there is an appropriate match to the WHO
		   query.  If there is a list of parameters supplied
		   with a WHO message, a RPL_ENDOFWHO MUST be sent
		   after processing each list item with <name> being
		   the item.*/

std::string RPL_ENDOFWHO(std::string name)
{
    std::stringstream output;

    output << ":" << HOSTNAME;
    output << " 315 "; 
    output << name << " ";
    output << ":End of WHO list";
    output << "\r\n";

    return output.str();
}