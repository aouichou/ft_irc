/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:31:24 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:49:09 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACTOR_HPP
# define EXTRACTOR_HPP

# include "Colors.hpp"
# include "available.hpp"
# include <sstream>
# include <deque>

typedef available<std::string>	t_available_string;

class Extractor
{
	public:
		Extractor();
		Extractor(const std::string& other);
		Extractor(const std::string& str, size_t pos, size_t len = std::string::npos);
		t_available_string	extract_to(std::string delimiter, bool or_end = false);
		t_available_string	extract_from(std::string delimiter, bool or_end = false);

		std::string	str(void) const {return (_data);}

		bool						is_digits(size_t len = 0);
		std::deque<std::string>		split(std::string delimiter = " ");
		Extractor& operator+= (const std::string &str);
		char	operator[] (size_t index);
		size_t	size(void) const;
		void	erase(const char *str);
		Extractor& erase (size_t pos = 0, size_t len = std::string::npos);
		std::string operator = (const Extractor &);
		friend std::ostream& operator<< (std::ostream& stream, Extractor& e);

	private:
		std::string	_data;
};

template <class InputIterator, class UnaryPredicate>
bool	all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
{
	while (first!=last)
	{
		if (!pred(*first))
			return false;
		++first;
	}
	return true;
}

#endif
