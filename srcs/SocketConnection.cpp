/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:49:47 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SocketConnection.hpp"

SocketConnection::SocketConnection(IQueue &queue, int fd_socketBind)
	: _queue(queue)
{
	_addr = (struct sockaddr){};
	_addr_len = sizeof(_addr);
	_fd = accept(fd_socketBind, &_addr, &_addr_len);
	if (_fd < 0)
		throw std::runtime_error("Fatal error when accepting a new connection");
	_queue.subscribe(_fd, this);
	DEBUG_CALL_SOCKET_CONNECTION_CONSTRUCTOR
}

SocketConnection::~SocketConnection()
{
	DEBUG_CALL_SOCKET_CONNECTION_DESTRUCTOR
	_queue.unsubscribe(_fd);
	close(_fd);
}

int		SocketConnection::getFD(void) const
{
	return (_fd);
}

void	SocketConnection::read(void)
{
	ssize_t bytes_read = ::recv(_fd, _buffer, BUFFER_LEN, 0);
	if (bytes_read <= 0)
		return ((void)is_alive(false));
	_read_cache.append(_buffer, bytes_read);
}

void	SocketConnection::setSendCache(std::string message)
{
	if (message.empty())
		return ;
	_write_cache.append(message);
}

std::string&	SocketConnection::getReadCache(void)
{
	return (_read_cache);
}

void	SocketConnection::write(void)
{
	ssize_t	bytes_send = ::send(_fd, _write_cache.c_str(), _write_cache.size(), 0);
	if (bytes_send < 0)
		return ((void)is_alive(false));
	_write_cache.erase(0, bytes_send);
}
