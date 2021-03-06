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
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include "Protocol.h"

using namespace Tins;
using std::string;

void test1_sniffer();
bool callback(const PDU &pdu);
void test2_sendpkt();
void test3_sendpkt();
string randomStr();
void sendPackets(std::string etherProtocol, std::string etherDst,
		std::string etherSrc, std::string netProtocol, std::string netSrc,
		std::string netDst, uint ttlNumber, std::string transportProtocol,
		uint portStc, uint portDst, uint npackets);
void test_sendPackets();
void test3_sendpkt();
void test4_sendpkt();
void test_sendPackets2();
void sendPackets2_1();
void sendPackets2_2();
void sendPackets2_3();
void sendPackets2_4();
void sendPackets2_5();
void sendPackets2_6();
void sendPackets2_7();

int main()
{

	bool t1 = false; // Sniffer
	bool t2 = false;	// send packet
	bool t3 = false; // send an arbitrary number of packets
	bool t4 = false;
	bool sendPackets_test = true;
	bool sendPackets2_test = true;

	if (t1)
		test1_sniffer();
	if (t2)
		test2_sendpkt();
	if (t3)
		test3_sendpkt();
	if (t4)
		test4_sendpkt();
	if (sendPackets_test)
		test_sendPackets();
	if (sendPackets2_test)
		test_sendPackets2();

}

void test1_sniffer()
{
	Sniffer("enp3s0").sniff_loop(callback);
}
string randomStr()
{
	string sRet =
			"FWvzqBro8ND379AQyZcfT14J8YWsooQrE5YuGlD4RCLXZW7ZRTygTG1cf50hkAEd9WgNPUob1ODGajJW4JyAaiIOFBqbp2XbHvr6mlll1JCmOMDByESFZ27vrhpYbHuDCIDvsiF6VfbZPkvbRChe5Z2NWTiIw28p96sUmw8cCmx7U0k3iIgmQTvS2a3jjyDlyCg6Qs6f mdaRI9UgEERUwVWZPJrK FE4RMONaVsR0FlaO1gk5 myNdOl6rVK8YwaAIHQlf 50Mbjq17Nd1y7ICY2mtP RfB9bjr1kGNwmGYWN7BD 1zSg2jDcGpRjr3mdw9LVdwNj9qWT9L97XZCOG5lK4V0L4uqaIloPfnwS1uevJa7gW8zrv21xMA6pFIS7M4zskGgNX7S2xS5OphBwimkW4gbCN5hD0vfehgMVRPPRVuHS9mooErXlZRs4uDfzuJQxW9o8LjVSPsTgRgTBiHwcWYlBScoGaNy JW7S1xTh6ZNpTYevkctq 20x4W37p0chHMIiy1v9r KZ8PmRl2e2iNtiJYTelE bj8hwpCmYdxj5KjGJJmX 8tQXbsSCSQJa6pS3Hkgi 8KqYXqu2gqriR349WAcN lM4o9an32ieUxEwCUURU nRH6Pni2ysC46Pz0eMin 4Y2NZ8Z0kR3ZKT35j8G0 6zbN7SyXUj0gj849vcMk EJv5qVlNUQ3wVNJNlDBc FY1BGJBuQTaxk7ifzlOI Eah91G3lnyOmizmsJnwv hWDK7badVMZD27vA9ipwPf7voUAlIaBbHr1DiFpTjnkk9KF6sU4teOWyACR3LExbPrfrE6QJ4UuFOVw3zGY1PIqUlw0iomvo1Nfi27Pc9iU7mf59ycXuvHjkLVlB1uzMkUoBue0r57GIcVGJzlxmDLzDJx9riQe5NDBjLSf3aNF6iiwNBEBfq5fPnJiCmv6TyNqoSRozzKFdj2JvEw7NAlAli3xECI7fy0ry1nLXPJsPSMNGhrWbLkPROVMldWZrOafK";
	return (sRet);
}

bool callback(const PDU &pdu)
{
	const IP &ip = pdu.rfind_pdu<IP>(); // Find the IP layer
	const TCP &tcp = pdu.rfind_pdu<TCP>(); // Find the TCP layer
	std::cout << ip.src_addr() << ':' << tcp.sport() << " -> " << ip.dst_addr()
			<< ':' << tcp.dport() << std::endl;
	return true;
}

void test2_sendpkt()
{
	PacketSender sender;
	IP pkt = IP("192.168.0.1") / TCP(22) / RawPDU(randomStr().c_str());
	std::cout << std::endl;
	for (;;)
	{
		sender.send(pkt);
		std::cout << ".";
	}
}

void test3_sendpkt()
{
	PacketSender sender;
	PDU* pkt;

	pkt = new IP("192.168.0.1");

	std::cout << std::endl;
	for (;;)
	{
		sender.send(*pkt, "enp3s0");
		std::cout << ".";
	}

	delete pkt;
}

void test4_sendpkt()
{
	PacketSender sender;

	IP flowPkt = IP();

	/// Packet crafter

	/// send packet
	std::cout << std::endl;
	for (;;)
	{
		sender.send(flowPkt);
		std::cout << ".";
	}

}

void sendPackets(protocol etherProtocol, protocol netProtocol,
		protocol transportProtocol, protocol application, std::string etherDst,
		std::string etherSrc, std::string netSrc, std::string netDst,
		uint ttlNumber, uint portStc, uint portDst, uint npackets, uint pktSize,
		std::string networkInterface)
{

	/// Packet crafter
	PDU* flowPkt;
	PacketSender::SocketType socket_type;
	if (etherProtocol == PROTOCOL__ETHERNET)
	{
		if (netProtocol == PROTOCOL__IPV4)
		{

			if (transportProtocol == PROTOCOL__TCP)
			{
				if (application == PROTOCOL__DHCP)
				{

					flowPkt = new EthernetII() / IP(netDst, netDst)
							/ TCP(portDst, portStc) / DHCP()
							/ RawPDU(std::string(pktSize, 'H'));

				}
				else if (application == PROTOCOL__DNS)
				{

					flowPkt = new EthernetII() / IP(netDst, netDst)
							/ TCP(portDst, portStc) / DNS()
							/ RawPDU(std::string(pktSize, 'D'));
				}
				else
				{
					flowPkt = new EthernetII() / IP(netDst, netDst)
							/ TCP(portDst, portStc)
							/ RawPDU(std::string(pktSize, 'T'));
				}
				socket_type = PacketSender::IP_TCP_SOCKET;

			}
			else if (transportProtocol == PROTOCOL__UDP)
			{

				if (application == PROTOCOL__DHCP)
				{

					flowPkt = new EthernetII() / IP(netDst, netDst)
							/ UDP(portDst, portStc) / DHCP()
							/ RawPDU(std::string(pktSize, 'H'));
				}
				else if (application == PROTOCOL__DNS)
				{

					flowPkt = new EthernetII() / IP(netDst, netDst)
							/ UDP(portDst, portStc) / DNS()
							/ RawPDU(std::string(pktSize, 'D'));
				}
				else
				{
					flowPkt = new EthernetII() / IP(netDst, netDst)
							/ UDP(portDst, portStc)
							/ RawPDU(std::string(pktSize, 'U'));
				}
				socket_type = PacketSender::IP_UDP_SOCKET;

			}
			else if (transportProtocol == PROTOCOL__ICMP)
			{

				flowPkt = new EthernetII() / IP(netDst, netDst) / ICMP()
						/ RawPDU(std::string(pktSize, 'I'));
				socket_type = PacketSender::ICMP_SOCKET;
			}

		}
		else if (netProtocol == PROTOCOL__IPV6)
		{

			//IPv6 ipv6_pkt(netDst, netDst);
			//ipv6_pkt.hop_limit(ttlNumber);

			if (transportProtocol == PROTOCOL__TCP)
			{
				if (application == PROTOCOL__DHCP)
				{

					flowPkt = new EthernetII() / IPv6(netDst, netDst)
							/ TCP(portDst, portStc) / DHCP()
							/ RawPDU(std::string(pktSize, 'H'));
				}
				else if (application == PROTOCOL__DNS)
				{

					flowPkt = new EthernetII() / IPv6(netDst, netDst)
							/ TCP(portDst, portStc) / DNS()
							/ RawPDU(std::string(pktSize, 'D'));
				}
				else
				{
					flowPkt = new EthernetII() / IPv6(netDst, netDst)
							/ TCP(portDst, portStc)
							/ RawPDU(std::string(pktSize, 'T'));
				}

			}
			else if (transportProtocol == PROTOCOL__UDP)
			{

				if (application == PROTOCOL__DHCP)
				{

					flowPkt = new EthernetII() / IPv6(netDst, netDst)
							/ UDP(portDst, portStc) / DHCP()
							/ RawPDU(std::string(pktSize, 'h'));
				}
				else if (application == PROTOCOL__DNS)
				{

					flowPkt = new EthernetII() / IPv6(netDst, netDst)
							/ UDP(portDst, portStc) / DNS()
							/ RawPDU(std::string(pktSize, 'd'));
				}
				else
				{
					flowPkt = new EthernetII() / IPv6(netDst, netDst)
							/ UDP(portDst, portStc)
							/ RawPDU(std::string(pktSize, 'u'));
				}
			}
			else if (transportProtocol == PROTOCOL__ICMP)
			{

				flowPkt = new EthernetII() / IPv6(netDst, netDst) / ICMPv6()
						/ RawPDU(std::string(pktSize, 'i'));
			}
			socket_type = PacketSender::IPV6_SOCKET;

		}
		else if (etherProtocol == PROTOCOL__ARP)
		{
			//flowPkt = new ARP() / RawPDU(std::string(pktSize, 'a'));
			flowPkt = new EthernetII() / ARP();
			socket_type = PacketSender::ARP_SOCKET;
		}
		else
		{
			flowPkt = new EthernetII() / RawPDU(std::string(pktSize, 'x'));
			socket_type = PacketSender::ETHER_SOCKET;
		}
	}

	/// Packet sender
	PacketSender sender;
	NetworkInterface iface(networkInterface);

	sender.open_l2_socket(networkInterface);
	sender.open_l3_socket(socket_type);
	std::cout << std::endl;
	for (uint i = 0; i < npackets; i++)
	{
		sender.send(*flowPkt, iface);
		std::cout << i << ", ";
	}
	std::cout << endl;
	sender.close_socket(socket_type, networkInterface);

	/// Free memory
	delete flowPkt;
}

void test_sendPackets()
{
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__UDP,
			PROTOCOL__DNS, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1", "10.0.0.1",
			"10.0.0.2", 64, 80, 2020, 60, 800, "enp3s0");

}

void test_sendPackets2()
{

	std::thread th1(sendPackets2_1);
	std::thread th2(sendPackets2_2);
	std::thread th3(sendPackets2_3);
	//std::thread th4(sendPackets2_4); // problema
	std::thread th5(sendPackets2_5);
	std::thread th6(sendPackets2_6);
	std::thread th7(sendPackets2_7);

	th1.join();
	th2.join();
	th3.join();
	//th4.join();
	th5.join();
	th6.join();
	th7.join();

}

void sendPackets2_1()
{
	printf("\nEthernet/IPv4/UDP/NULL 10.0.0.1 -> 10.0.0.11");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__UDP,
			PROTOCOL__NULL, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1",
			"10.0.0.1", "10.0.0.11", 64, 80, 2020, 60, 120, "enp3s0");
}
void sendPackets2_2()
{
	printf("\nEthernet/IPv4/TCP/DNS 10.0.0.2 -> 10.0.0.22");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__TCP,
			PROTOCOL__DNS, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1", "10.0.0.2",
			"10.0.0.22", 64, 80, 2020, 60, 555, "enp3s0");
}
void sendPackets2_3()
{
	printf("\nEthernet/IPv4/UDP/DHCP 10.0.0.3 -> 10.0.0.33");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__UDP,
			PROTOCOL__DHCP, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1",
			"10.0.0.3", "10.0.0.33", 64, 80, 2020, 60, 700, "enp3s0");
}
void sendPackets2_4()
{
	printf("\nEthernet/ARP 10.0.0.4 -> 10.0.0.44");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__ARP, PROTOCOL__NULL,
			PROTOCOL__NULL, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1",
			"10.0.0.4", "10.0.0.44", 0, 0, 0, 0, 1000, "enp3s0");
}
void sendPackets2_5()
{
	printf("\nEthernet/IPv4/TCP/DNS 10.0.0.5 -> 10.0.0.55");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__TCP,
			PROTOCOL__DNS, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1", "10.0.0.5",
			"10.0.0.55", 64, 80, 2020, 60, 500, "enp3s0");
}
void sendPackets2_6()
{
	printf("\nEthernet/IPv4/UDP/DNS 10.0.0.6 -> 10.0.0.66");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__UDP,
			PROTOCOL__DNS, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1", "10.0.0.6",
			"10.0.0.66", 64, 80, 2020, 60, 1240, "enp3s0");
}
void sendPackets2_7()
{
	printf("\nEthernet/IPv4/TCP/DNS 10.0.0.7 -> 10.0.0.77");
	sendPackets(PROTOCOL__ETHERNET, PROTOCOL__IPV4, PROTOCOL__TCP,
			PROTOCOL__DNS, "70:62:b8:9b:3e:d4", "70:62:b8:9b:3e:d1", "10.0.0.7",
			"10.0.0.77", 64, 80, 2020, 60, 80, "enp3s0");
}

