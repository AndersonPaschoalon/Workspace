/*
 * PlogMacros.h
 *
 *  Created on: 24 de jul de 2017
 *      Author: anderson
 */

#ifndef PLOGMACROS_H_
#define PLOGMACROS_H_

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <plog/Init.h>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>


#define PLOG_LOG_ENV_VAR "TEST_ENV"

#define PLOG_INIT_DEFAULT(logLevel)\
		char* _plog_logfile_env = std::getenv(PLOG_LOG_ENV_VAR);\
		if(!_plog_logfile_env)\
		{ \
			plog::RollingFileAppender<plog::CsvFormatter> fileAppender("defaultLocation_traceAnalyzer.log",\
					800000, 2);\
			plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;\
			plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); \
			LOG_ERROR  << "[" << __FILE__ << "] " << "Can't find env variable SIMITAR_LOGFILE_TRACE_ANALYZER\n"\
			<< "Using default logfile ./defaultLocation_traceAnalyzer.log\n";\
		}\
		else\
		{\
			plog::RollingFileAppender<plog::CsvFormatter> fileAppender(_plog_logfile_env,\
					800000, 1);\
			plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender; \
			plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); \
		}\



#define PLOG_INIT() plog::RollingFileAppender<plog::CsvFormatter> fileAppender("MultiAppender.csv", 8000, 3); \
		plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoleAppender; \
		plog::init(plog::debug, &colorConsoleAppender).addAppender(&fileAppender);

#define PLOG_CONF(LogFileName, LogFileMaxSize, NLogFiles) plog::RollingFileAppender<plog::CsvFormatter> fileAppender(LogFileName, LogFileMaxSize, NLogFiles); \
		plog::ColorConsoleAppender<plog::TxtFormatter> colorConsoleAppender; \
		plog::init(plog::debug, &colorConsoleAppender).addAppender(&fileAppender);

#define PLOG_NONE LOG_NONE  << "[" << __FILE__ << "] "
#define PLOG_FATAL LOG_FATAL  << "[" << __FILE__ << "] "
#define PLOG_ERROR LOG_ERROR  << "[" << __FILE__ << "] "
#define PLOG_WARN LOG_WARNING  << "[" << __FILE__ << "] "
#define PLOG_INFO LOG_INFO  << "[" << __FILE__ << "] "
#define PLOG_DEBUG LOG_DEBUG  << "[" << __FILE__ << "] "
#define PLOG_VERBOSE LOG_VERBOSE  << "[" << __FILE__ << "] "

#endif /* PLOGMACROS_H_ */