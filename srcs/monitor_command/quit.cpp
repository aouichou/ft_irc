/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:14:26 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"

/*
Command: QUIT
Parameters: [<Quit message>]
A client session is ended with a quit message.  The server must close
the connection to a client which sends a QUIT message. If a "Quit
Message" is given, this will be sent instead of the default message,
the nickname.
When netsplits (disconnecting of two servers) occur, the quit message 
is composed of the names of two servers involved, separated by a
space.  The first name is that of the server which is still connected
and the second name is that of the server that has become
disconnected.
If, for some other reason, a client connection is closed without  the
client  issuing  a  QUIT  command  (e.g.  client  dies and EOF occurs
on socket), the server is required to fill in the quit  message  with
some sort  of  message  reflecting the nature of the event which
caused it to happen.

Numeric Replies: None.
*/

void	Monitorer::cmd_quit(void)
{
	DEBUG_CALL_MONITORER_COMMAND

	std::string	message = "left the server";
	if (request->params.empty() == false)
	{
		message = request->params.back();
		request->params.pop_back();
	}
	user->sendToAllChannels(message);
	user->quitAllChannels();

	t_channel_map::iterator	it;
	Channel * channel;
	it = _channel_map.begin();
	for ( ; it != _channel_map.end() ; it++)
	{
		channel = it->second;
		channel->remove(user);
	}
	
	user->is_alive(false);
}

