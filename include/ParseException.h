#pragma once

#include <stdexcept>

class ParseException : public std::runtime_error {
public:
	ParseException(std::string msg = "") : std::runtime_error(msg) {}
};