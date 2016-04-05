#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

/*
void print_ip(int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;	
    printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);        
    printf("%d.%d.%d.%d\n", bytes[0], bytes[1], bytes[2], bytes[3]);        
}
*/

int main (int argc, char** argv)
{
	/*
	print_ip(215853248);

	char ip[] = "192.168.221.12";
        long long_address = inet_addr (ip) ;
        struct in_addr addr;
        addr.s_addr = long_address;
        char *dot_ip = inet_ntoa(addr);

        printf("%s",dot_ip);
	*/

	long ipFromEim = 215853248;

	struct in_addr myAddress;

	myAddress.s_addr = ipFromEim;

	char *myDotIp = inet_ntoa(myAddress);

	cout << "conversion from int to IP: " << myDotIp << endl;
	
	cout << "conversion from IP to int: " << inet_addr(myDotIp) << endl;

	return 0;
}

