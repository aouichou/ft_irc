/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketBind.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:21:51 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SocketBind.hpp"

SocketBind::SocketBind(ICrud& crud, IQueue &queue, int port, int backlog)
	: _queue(queue)
	, _crud(crud)
{
	_fd = ::socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0)
		throw std::runtime_error("unable to create a new binding socket");
	const int enable = 1;
	if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
	{
		close(_fd);
		throw std::runtime_error("unable to make reusable socket");
	}
	_sin.sin_family			= AF_INET;
	_sin.sin_port			= htons(port);
	_sin.sin_addr.s_addr	= htonl(INADDR_ANY);
	if (::bind(_fd, (struct sockaddr *)&_sin, sizeof (_sin)) < 0)
	{
		close(_fd);
		throw std::runtime_error("unable to bind the new socket");
	}
	if (::listen(_fd, backlog) < 0){
		close(_fd);
		throw std::runtime_error("unable to listen the new socket");
	}

	_queue.subscribe(_fd, this);
	DEBUG_CALL_SOCKET_BIND_CONSTRUCTOR
}

SocketBind::~SocketBind()
{
	DEBUG_CALL_SOCKET_BIND_DESTRUCTOR
	_queue.unsubscribe(_fd);
	close(_fd);
}

void	SocketBind::read(void)
{
	_crud.addEventListener(_queue, _fd);
}

void	SocketBind::write(void) {}
