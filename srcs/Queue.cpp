/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:21:51 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Queue.hpp"

Queue::Queue(size_t max_events)
	: _max_events(max_events)
{
	_epoll_instance = epoll_create(_max_events);	/* for backward compatibility */
	if (_epoll_instance < 0)
		throw std::runtime_error("Fatal error when creating the monitoring socket instance");
	_events_list = new struct epoll_event [_max_events];
}

void	Queue::subscribe(int fd, IQueue::IEventListener* listener)
{
	DEBUG_CALL_QUEUE_UNSUBSCRIBE

	struct epoll_event ev;

	ev.events	=	EPOLLIN | EPOLLOUT;
	ev.data.ptr	=	listener;
	epoll_ctl(_epoll_instance, EPOLL_CTL_ADD, fd, &ev);
}

void	Queue::unsubscribe(int fd)
{
	DEBUG_CALL_QUEUE
	epoll_ctl(_epoll_instance, EPOLL_CTL_DEL, fd, NULL);
}

bool	Queue::event_loop(ICrud& crud)
{
	int	num_events;

	num_events = epoll_wait(_epoll_instance, _events_list, _max_events, 0);
	if (num_events < 0)
		throw std::runtime_error("The event loop abort");
	for (int i = 0; i < num_events; i++)
	{
		IQueue::IEventListener* listener = (IQueue::IEventListener*)_events_list[i].data.ptr;
		if (listener->is_alive() == false)
		{
			listener->write();
			crud.removeEventListener(listener);
			continue ;
		}
		if (_events_list[i].events & EPOLLIN)
			listener->read();
		if (_events_list[i].events & EPOLLOUT)
		{
			crud.treatEventListener(listener);
			listener->write();
		}
	}
	return (true);
}

Queue::~Queue()
{
	DEBUG_CALL_QUEUE
	close(_epoll_instance);
	delete [] _events_list;
}
