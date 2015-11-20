#include "Logger.h"

std::string to_string(Level& level);


Logger::Logger(Level l, LogSink& ls)
	:_sink(ls)
{

}

void Logger::operator()(std::string const& message,
	char const* function,
	char const* file,
	int line)
{
	std::cout << to_string(_level) << " " << file << " " << line << " " << function << " " << message << std::endl;
}

std::string to_string(Level& level)
{
	if (level == Level::Debug)
	{
		return "DEBUG";
	}
	else if (level == Level::Info)
	{
		return "INFO";
	}
	else if (level == Level::Warn)
	{
		return "WARN";
	}
	else if (level == Level::Error)
	{
		return "ERROR";
	}
	else if (level == Level::Fatal)
	{
		return "FATAL";
	}
	return "UNKNOWN";
}

