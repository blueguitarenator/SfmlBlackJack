#pragma once
#include <iostream>
#include <sstream>
#include <string>

enum class Level
{
	Debug,
	Info,
	Warn,
	Error,
	Fatal
};


class LogSink
{

};

class Console : public LogSink
{

};

class Logger {
public:
	Logger(Level l, LogSink& ls);

	void operator()(std::string const& message,
		char const* function,
		char const* file,
		int line);

	
private:
	Level _level;
	LogSink& _sink;
};

#define LOG(Logger_, Message_)                  \
  Logger_(                                      \
    static_cast<std::ostringstream&>(           \
      std::ostringstream().flush() << Message_  \
    ).str(),                                    \
    __FUNCTION__,                               \
    __FILE__,                                   \
    __LINE__                                    \
  );


#ifdef NDEBUG
#  define LOG_DEBUG(_) do {} while(0);
#  define LOG_INFO(_) do {} while(0);
#  define LOG_WARN(_) do {} while(0);
#  define LOG_ERROR(_) do {} while(0);
#  define LOG_FATAL(_) do {} while(0);
#else
#  define LOG_DEBUG(Message_) LOG(Debug(), Message_)
#  define LOG_INFO(Message_) LOG(Info(), Message_)
#  define LOG_WARN(Message_) LOG(Info(), Message_)
#  define LOG_ERROR(Message_) LOG(Info(), Message_)
#  define LOG_FATAL(Message_) LOG(Info(), Message_)
#endif

namespace
{
	Logger& Debug() {
		Console console;
		static Logger logger(Level::Debug, console);
		return logger;
	}

	Logger& Info() {
		Console console;
		static Logger logger(Level::Info, console);
		return logger;
	}

	Logger& Warn() {
		Console console;
		static Logger logger(Level::Warn, console);
		return logger;
	}

	Logger& Error() {
		Console console;
		static Logger logger(Level::Error, console);
		return logger;
	}

	Logger& Fatal() {
		Console console;
		static Logger logger(Level::Fatal, console);
		return logger;
	}
}