#pragma once

class bad_argument_error : public std::exception
{
public:
	bad_argument_error(const char* msg): std::exception(msg) { }
	virtual const char* what() const throw() { return "bad argument"; }

};
