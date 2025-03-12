/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IQueueEventListener.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:46:38 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IQueue.hpp"

IQueue::IEventListener::IEventListener(void)
	: _alive(true) {}


bool	IQueue::IEventListener::is_alive(bool alive)
{
	if (alive == false)
		_alive = false;
	return (_alive);
}

IQueue::IEventListener::~IEventListener() {}

