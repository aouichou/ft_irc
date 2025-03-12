/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:14:26 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"

void	Monitorer::cmd_unknown	(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	user->send_message(RPL_TRYAGAIN(request->command.name));
}
