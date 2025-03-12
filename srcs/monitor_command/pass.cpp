/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:58:08 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"

void	Monitorer::cmd_pass(void)
{
	DEBUG_CALL_MONITORER_COMMAND

	if (user->isConnected())
		return(user->send_message(ERR_ALREADYREGISTRED(user->nick_name)));
	if (request->params.empty())
		return(user->send_message(ERR_NEEDMOREPARAMS("", "PASS", "please type a password" )));

	std::string password = request->params.front();
	request->params.pop_front();
	user->connection_password.set(password);

	if (user->connection_password.get() != _pass)
	{
		user->send_message(ERR_PASSWDMISMATCH(user->nick_name, "Password mismatch"));
		return ;
	}
	else
	{
		user->connectionStep(_pass, 1);
	}
	
}
