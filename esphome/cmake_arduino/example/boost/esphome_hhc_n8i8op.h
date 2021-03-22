#ifndef ESPHOME_HHC_N8I8OP_H
#define ESPHOME_HHC_N8I8OP_H

#include "esphome.h"
#include <boost/asio.hpp>

using namespace esphome;
//using namespace time;
using namespace binary_sensor;
//using namespace switch_;
//using namespace sensor;
//using namespace api;


typedef std::function<void(bool)> HHCStateChangeCB;

class HHCSwitch: public switch_::Switch
{
public:
    HHCSwitch(std::string s, HHCStateChangeCB observer): switch_::Switch(s), observer_(std::move(observer))
    {

    }

    virtual void write_state(bool state) {
        this->state = state;
        observer_(state);
        publish_state(state);
    };
protected:
    HHCStateChangeCB observer_;
};

class esphome_hhc_n8i8op: public esphome::Component
{
public:
    esphome_hhc_n8i8op(std::map<int, std::string> switch_names, std::string host, std::string port);

    void loop() override;
    void setup() override;
private:
    const std::map<int, std::string> switch_names_;
    boost::asio::ip::tcp::socket socket_;
    const std::string host_;
    const std::string port_;

    std::vector<std::shared_ptr<HHCSwitch>> switches_;
};

#endif // ESPHOME_HHC_N8I8OP_H
