/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:14:26 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"

void	Monitorer::cmd_user(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	size_t			size = request->params.size();
	std::string		params;

	if (user->isConnected())
		return(user->send_message(ERR_ALREADYREGISTRED(user->nick_name)));

	if (size == 0 || size < 4)
		return(user->send_message(ERR_NEEDMOREPARAMS("", "user")));
	else
	{
		for (size_t idx = 0; idx < size; idx++)
		{
			switch (idx)
			{
				case 0 : user->user_name.set(request->params[idx]);	break;
				case 1 : user->host_name.set(request->params[idx]);	break;
				case 2 : user->server_name.set(request->params[idx]);	break;
				case 3 : user->real_name.set(request->params[idx]);	break;
				default: break;
			}
		}
		user->connectionStep(_pass, 1);
	}
}
