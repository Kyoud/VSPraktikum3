#include <cstdlib>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <sys/time.h>


#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "gen-cpp/timeserver.h"// service

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace std::chrono;
/*
 * 
 */
int main(int argc, char** argv) {
    int n1 = 2, n2 = 3;
    boost::shared_ptr<TSocket> socket(new TSocket("127.0.0.1", 9090));
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    
    timeserverClient client(protocol);
    try {
	struct timeval t0;
	struct timeval t3;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	std::time (&rawtime);
	timeinfo = localtime(&rawtime);
	
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
	std::string str(buffer);
        cout << "Request sent: " << str << endl;

        transport->open();

        string result = "test";
	valuesStruct resultStruct;
        // Request Time
	gettimeofday(&t0, NULL); // client receive time
	
        client.time(resultStruct);// Request time

        transport->close();

	resultStruct.t0 = t0.tv_sec*(int)1e6 + t0.tv_usec; // caculate microseconds
	gettimeofday(&t3, NULL); // client receive time
	resultStruct.t3 = t3.tv_sec*(int)1e6 + t3.tv_usec; // caculate microseconds


        // Output response
	cout << "t0: " << resultStruct.t0 << endl;
	cout << "t1: " << resultStruct.t1 << endl;
	cout << "t2: " << resultStruct.t2 << endl;
	cout << "t3: " << resultStruct.t3 << endl;
	cout << "Nachrichtenlaufzeit: " << (resultStruct.t3-resultStruct.t0-(resultStruct.t2-resultStruct.t1))/2 << " μs" << endl;
        cout << "Response received: " << resultStruct.unixtime << endl;
    } catch (TException &tx) {
        cout << "error calling server: " << tx.what() << endl;
    }
    return 0;
}

