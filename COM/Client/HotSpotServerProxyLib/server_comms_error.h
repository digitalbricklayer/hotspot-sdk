#pragma once

class service_comms_error : public std::exception
{
public:
	virtual const char* what() const throw() { return "unable to talk with the service"; }

};
