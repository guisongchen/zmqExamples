#include <zmq.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define within(num) (int) ((float) num * random () / (RAND_MAX + 1.0))

int main() {
    zmq::context_t context(1);
    zmq::socket_t publisher(context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5556");
    publisher.bind("ipc://weather.ipc");

    srandom((unsigned)time(NULL));
    while (1) {
        int zipcode, temperature, relhumidity;
        zipcode = within(100000);
        temperature = within(215) - 80;
        relhumidity = within(50) + 10;

        zmq::message_t message(20);
        snprintf((char*)message.data(),20, "%05d %d %d", zipcode, temperature, relhumidity);
        publisher.send(message, zmq::send_flags::none);
    }

    return 0;
}