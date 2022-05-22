#include <zmq.hpp>

#include <string>
#include <iostream>
#include <unistd.h>

int main() {
    zmq::context_t context(2);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");

    while (true) {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "recv " <<  request.to_string() << std::endl;

        sleep(1);

        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply, zmq::send_flags::none);
    } 

    return 0;
}