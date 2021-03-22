#include "esphome_hhc_n8i8op.h"
#include "iostream"

using boost::asio::ip::tcp;
using boost::asio::ip::make_address_v4;

extern boost::asio::io_service *network_io_service;

const bool max_length = 16;


esphome_hhc_n8i8op::esphome_hhc_n8i8op(std::map<int, std::string> switch_names, std::string host, std::string port)
    : switch_names_(std::move(switch_names))
    , socket_(*network_io_service)
    , host_(host)
    , port_(port)
{


}

void esphome_hhc_n8i8op::setup()
{
    Component::setup();

    tcp::resolver resolver(*network_io_service);

    auto endpoints = resolver.resolve(tcp::v4(), host_, port_);
    boost::asio::connect(socket_, endpoints);

//    {
//        std::string command("name");
//        auto buf = boost::asio::buffer(command);
//        boost::asio::write(socket_, buf);
//    }


//    {
//        std::string command("input");
//        auto buf = boost::asio::buffer(command);
//        boost::asio::write(socket_, buf);
//        loop();
//    }
    {
        std::string command("read");
        auto buf = boost::asio::buffer(command);
        boost::asio::write(socket_, buf);
    }

    while (true) {
    char reply[max_length];
    boost::asio::read(socket_,
        boost::asio::buffer(reply, max_length));

    if (reply[0] == 'y') // relay000000
    {
        break;
    }
    }

    bool states[8];
    for (int i = 0; i!=8; ++i) {
    char reply[max_length];
    boost::asio::read(socket_,
        boost::asio::buffer(reply, max_length));
    states[i] = (reply[0] == '0') ? false : true ;
}


    for (auto it = switch_names_.cbegin(); it != switch_names_.cend(); ++it)
    {
        const auto index = it->first;
        auto sw = std::make_shared<HHCSwitch>(it->second, [this, index](bool set_state)
        {
            std::string command(set_state ? "on" : "off");
            command.append(std::to_string(index));
            auto buf = boost::asio::buffer(command);
            boost::asio::write(this->socket_, buf);

            std::cout<< "HHC: written command: "<< command << std::endl ;

        });
        sw->publish_state(states[index]);
        switches_.push_back(sw);
        App.register_switch(sw.get());
    }
}

void esphome_hhc_n8i8op::loop()
{
    assert(socket_.connected());

    std::string s;

    while (socket_.available() > 0) {
    char reply[max_length];
    const size_t reply_length = boost::asio::read(socket_,
        boost::asio::buffer(reply, max_length));
    s.append(reply, reply_length);
    }
    if (s.size() > 0)    {

        std::cout << "HHC: Reply is: '" << s <<"'\n";
        const auto pos = s.find("relay");
        if (pos < s.size())
        {

        }
    }
}
