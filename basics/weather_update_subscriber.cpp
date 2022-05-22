#include <zmq.hpp>

#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    zmq::context_t context(1);
    std::cout << "client online..." << std::endl;
    zmq::socket_t subsciber(context, zmq::socket_type::sub);
    subsciber.connect("tcp://localhost:5556");

    const char *filter = argc > 1 ? argv[1] : "10001";
    subsciber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

    int i = 0;
    long total = 0;
    for (i = 0; i < 100; i++) { // 100 means get filter message for 100 times, not just run 100 times
        zmq::message_t update;
        int zipcode, temperature, relhumidity;
        subsciber.recv(update, zmq::recv_flags::none);
        std::istringstream iss(static_cast<char*>(update.data()));
        iss >> zipcode >> temperature >> relhumidity;
        total += temperature;
    }

    std::cout << "Average temperature for zipcode '" << filter << "' was "
              << (int)(total/i) << "F" << std::endl;

    return 0;
}