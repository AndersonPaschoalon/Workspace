//============================================================================
// Name        : Tutorial_libtins.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <tins/tins.h>
#include <string>

using namespace Tins;
using std::string;
void test1_sniffer();
bool callback(const PDU &pdu);
void test2_sendpkt();
string randomStr();

int main() {

	bool t1 = false;
	bool t2 = true;

	//if (t1)
	//	test1_sniffer();
	if (t2)
		test2_sendpkt();

}

void test1_sniffer() {
	Sniffer("enp3s0").sniff_loop(callback);
}
string randomStr(){
	string sRet =
			"FWvzqBro8ND379AQyZcfT14J8YWsooQrE5YuGlD4RCLXZW7ZRTygTG1cf50hkAEd9WgNPUob1ODGajJW4JyAaiIOFBqbp2XbHvr6mlll1JCmOMDByESFZ27vrhpYbHuDCIDvsiF6VfbZPkvbRChe5Z2NWTiIw28p96sUmw8cCmx7U0k3iIgmQTvS2a3jjyDlyCg6Qs6f mdaRI9UgEERUwVWZPJrK FE4RMONaVsR0FlaO1gk5 myNdOl6rVK8YwaAIHQlf 50Mbjq17Nd1y7ICY2mtP RfB9bjr1kGNwmGYWN7BD 1zSg2jDcGpRjr3mdw9LVdwNj9qWT9L97XZCOG5lK4V0L4uqaIloPfnwS1uevJa7gW8zrv21xMA6pFIS7M4zskGgNX7S2xS5OphBwimkW4gbCN5hD0vfehgMVRPPRVuHS9mooErXlZRs4uDfzuJQxW9o8LjVSPsTgRgTBiHwcWYlBScoGaNy JW7S1xTh6ZNpTYevkctq 20x4W37p0chHMIiy1v9r KZ8PmRl2e2iNtiJYTelE bj8hwpCmYdxj5KjGJJmX 8tQXbsSCSQJa6pS3Hkgi 8KqYXqu2gqriR349WAcN lM4o9an32ieUxEwCUURU nRH6Pni2ysC46Pz0eMin 4Y2NZ8Z0kR3ZKT35j8G0 6zbN7SyXUj0gj849vcMk EJv5qVlNUQ3wVNJNlDBc FY1BGJBuQTaxk7ifzlOI Eah91G3lnyOmizmsJnwv hWDK7badVMZD27vA9ipwPf7voUAlIaBbHr1DiFpTjnkk9KF6sU4teOWyACR3LExbPrfrE6QJ4UuFOVw3zGY1PIqUlw0iomvo1Nfi27Pc9iU7mf59ycXuvHjkLVlB1uzMkUoBue0r57GIcVGJzlxmDLzDJx9riQe5NDBjLSf3aNF6iiwNBEBfq5fPnJiCmv6TyNqoSRozzKFdj2JvEw7NAlAli3xECI7fy0ry1nLXPJsPSMNGhrWbLkPROVMldWZrOafK";
	return (sRet);
}

void test2_sendpkt() {
	PacketSender sender;
	IP
	pkt = IP("192.168.0.1") / TCP(22) / RawPDU(randomStr().c_str());
	std::cout << std::endl;
	for (;;) {
		sender.send(pkt);
		std::cout << ".";
	}
}

bool callback(const PDU &pdu) {
	const IP &ip = pdu.rfind_pdu<IP>(); // Find the IP layer
	const TCP &tcp = pdu.rfind_pdu<TCP>(); // Find the TCP layer
	std::cout << ip.src_addr() << ':' << tcp.sport() << " -> " << ip.dst_addr()
			<< ':' << tcp.dport() << std::endl;
	return true;
}