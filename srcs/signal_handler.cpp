/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:49:05 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.hpp"
#include <stdexcept>

bool	SignalHandler::_stop = false;

SignalHandler::SignalHandler(void)
{
	_signals[0] = (struct sigaction) { };
	_signals[1] = (struct sigaction) { };
	_signals[0].sa_handler = _stop_loop_handler;
	_signals[1].sa_handler = _stop_loop_handler;

	if (0
		|| sigaction(SIGINT, &_signals[0], NULL)
		|| sigaction(SIGQUIT, &_signals[1], NULL)
		)
		throw std::runtime_error("Unable to set sigaction handler");
}

SignalHandler::~SignalHandler()
{
}

void	SignalHandler::_stop_loop_handler(int sig_value)
{
	(void)sig_value;
	_stop = true;
}

bool	SignalHandler::keep_running(void)
{
	return (!_stop);
}
