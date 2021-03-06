//============================================================================
// Name        : Tutorial_time.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sys/time.h>
#include <unistd.h>

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define _POSIX_C_SOURCE 200809L

using namespace std;

unsigned long int std_time() {

	//#include <iostream>
	//using namespace std;

	unsigned long int sec = time(NULL);
	cout << sec << endl;
	return (sec);

}

void print_current_time_with_ms(void) {
	long ms; // Milliseconds
	time_t s;  // Seconds
	struct timespec spec;

	clock_gettime(CLOCK_REALTIME, &spec);

	s = spec.tv_sec;
	ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds

	printf("Current time: %"PRIdMAX".%03ld seconds since the Epoch\n",
			(intmax_t) s, ms);
}

void exemplo1() {
	unsigned long int delta;
	unsigned long int time0;
	time0 = std_time();
	sleep(5);
	delta = std_time() - time0;
	cout << "Delta/Expected:" << delta << "/5\n";
}

void exemplo2() {
	print_current_time_with_ms();

	cout << "Not working... \n" << endl;
	long double time0; // microseconds
	//time_t          s;  // Seconds

	time_t sleeptime = 0;
	double in_sleeptime = 5.55555555;

	long double delta = 0;

	sleeptime = time_t(in_sleeptime * 1.0e6);

	struct timespec spec1;
	time0 = round(spec1.tv_nsec / 1.0e3); // Convert nanoseconds to milliseconds

	usleep(sleeptime);

	struct timespec spec2;
	delta = round(spec2.tv_nsec / 1.0e3); // - time0;

	cout << "Delta/Expected:" << delta << "/" << time0 << "\n";
}

uint64_t calcDeltaTime(struct timespec* start, struct timespec* end) {
	return uint64_t(
			(end->tv_sec - start->tv_sec) * 1000000
					+ (end->tv_nsec - start->tv_nsec) / 1000);
}

inline void exemplo3() {
	struct timespec start, end;
	time_t sleeptime = 0;
	double in_sleeptime = 1.55555555;
	sleeptime = time_t(in_sleeptime * 1.0e6);
	uint64_t delta_us;
	double delta_s = 0;

	cout << "Using usleep()\n";
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	usleep(sleeptime);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);

	delta_us = (end.tv_sec - start.tv_sec) * 1000000
			+ (end.tv_nsec - start.tv_nsec) / 1000;

	cout << "delta/expected: " << delta_us << "/" << sleeptime << endl;

	sleeptime = 0;
	in_sleeptime = 1.55555555;
	sleeptime = time_t(in_sleeptime * 1.0e6);

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	usleep(sleeptime);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);

	delta_us = (end.tv_sec - start.tv_sec) * 1000000
			+ (end.tv_nsec - start.tv_nsec) / 1000;

	cout << "delta/expected: " << delta_us << "us/" << sleeptime << "us"
			<< endl;
	delta_s = (delta_us / 1.0e6);
	cout << "delta/expected: " << delta_s << "s/" << (sleeptime / 1.0e6) << "s"
			<< endl;

	//pooling
	cout << "Using pooling\n";
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	uint64_t wait_us = 1000000;
	for (;;) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		delta_us = (end.tv_sec - start.tv_sec) * 1000000
				+ (end.tv_nsec - start.tv_nsec) / 1000;
		if (delta_us < wait_us) {
			continue;
		} else {
			break;
		}
	}
	cout << "delta/expected: " << delta_us << "/" << (5000000) << endl;

	//pooling
	cout << "Using select()\n";

	double sleep_double = 1.5;
	struct timeval tv;
	tv.tv_sec = int(sleep_double);
	tv.tv_usec = int( (sleep_double - floor(sleep_double)) * 1e6);
	std::cout << ":::<" << (sleep_double - floor(sleep_double)) << ">\n";
	std::cout << ":::<" << int( (sleep_double - floor(sleep_double)) * 1e6) << ">\n";
	int ret;

	//sleeptime = 0;
	//in_sleeptime = 7.55555555;
	//sleeptime = time_t(in_sleeptime * 1.0e6);

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	//usleep(sleeptime);
	do {
		ret = select(1, NULL, NULL, NULL, &tv);
	} while ((ret == -1) && (errno == EINTR)); //select is interruped too
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);

	delta_us = (end.tv_sec - start.tv_sec) * 1000000
			+ (end.tv_nsec - start.tv_nsec) / 1000;

	cout << "delta/expected: " << delta_us << "us/" << sleeptime << "us"
			<< endl;
	delta_s = (delta_us / 1.0e6);
	cout << "delta/expected: " << delta_s << "s/" << (sleeptime / 1.0e6) << "s"
			<< endl;

}

int main() {
	bool t1 = false;
	bool t2 = false;
	bool t3 = true;

	if (t1)
		exemplo1();
	if (t2)
		exemplo2();
	if (t3)
		exemplo3();

	return 0;
}
