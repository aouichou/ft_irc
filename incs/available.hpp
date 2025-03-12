/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   available.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:29:34 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:29:35 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVAILABLE_HPP
# define AVAILABLE_HPP

# include <ostream>
template <typename Type>
class available
{
	public:
	available()
		: _ok(false)
	{}

	available(Type value)
		: _ok(true)
		, _value(value)
	{}

	operator bool() const {
		return _ok;
	}

	available& operator = (available other) {
		_value = other._value;
		_ok = other._ok;
		return (*this);
	}

	void operator ()(Type v) {
		_value = v;
		_ok = true;
	}

	Type& operator ()(void)  {
		return (_value);
	}

	Type operator ()(void) const {
		return (_value);
	}

	std::ostream& operator<< (std::ostream& stream) const {
		if (_ok)
			stream << _value;
		return (stream);
	}

	private:
		bool	_ok;
		Type	_value;
};

#endif
