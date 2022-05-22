#include <zmq.hpp>

#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);

    std::cout << "connect to hello world server..." << std::endl;
    socket.connect("tcp://localhost:5555");

    for (int i = 0; i < 10; i++) {
        zmq::message_t request(5);
        memcpy(request.data(), "Hello", 5);
        std::cout << "sending " << request.to_string() << " " << i << "..." << std::endl;
        socket.send(request, zmq::send_flags::none);

        zmq::message_t reply;
        socket.recv(reply, zmq::recv_flags::none);
        std::cout << "recv "<< reply.to_string() << " " << i << std::endl;
    }

    return 0;
}