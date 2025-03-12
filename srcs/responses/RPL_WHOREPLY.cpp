/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WHOREPLY.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:38:38 by aouichou          #+#    #+#             */
/*   Updated: 2024/02/02 01:03:13 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

std::string	RPL_WHOREPLY(std::string channel, std::string users_list)
{
    std::stringstream	output;

    output << channel << " ";
    output << users_list << " ";
    output << "\r\n";
    return (output.str());
}