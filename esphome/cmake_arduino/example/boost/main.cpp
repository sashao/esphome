

// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using namespace time;
using namespace binary_sensor;
using namespace climate;
using namespace switch_;
logger::Logger *logger_logger;

api::APIServer *api_apiserver;
using namespace sensor;
using namespace api;

binary_sensor::BinarySensor *sensr;

class Switch2: public switch_::Switch
{
public:
    Switch2(std::string s): switch_::Switch(s) {}

    virtual void write_state(bool state) {
        this->state = state;
        publish_state(state);
    };
};

Switch2 *swtch;

homeassistant::HomeassistantSensor *ha_hello_world;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <iostream>

#include "esphome_hhc_n8i8op.h"



void setup() {
  App.pre_setup("test-x86", __DATE__ ", " __TIME__);

  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_log_level("api", ESPHOME_LOG_LEVEL_VERY_VERBOSE);
  App.register_component(logger_logger);


  api_apiserver = new api::APIServer();
  App.register_component(api_apiserver);

  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);


  ha_hello_world = new homeassistant::HomeassistantSensor();
  App.register_component(ha_hello_world);


  App.register_sensor(ha_hello_world);
  ha_hello_world->set_name("ha_hello_world");
  ha_hello_world->set_internal(true);
  ha_hello_world->set_accuracy_decimals(10);
  ha_hello_world->set_force_update(false);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========

  sensr = new BinarySensor("x86binarysensor");
  App.register_binary_sensor(sensr);

  swtch = new Switch2("x86switch");
  App.register_switch(swtch);

  std::map<int, std::string> switch_names;
  switch_names[1] = "turn on 12 v";
  switch_names[2] = "Boys light 2";
  switch_names[3] = "Boys light 3";
  switch_names[4] = "Boys light 4";
  switch_names[5] = "Boys light 5";
  switch_names[6] = "Boys light 6";
  switch_names[7] = "Boys light 7";
  switch_names[8] = "Boys light 8";

  App.setup();
}

void loop() {
	App.loop();
}

const int one_tick = 10;
long iteration = 0;

void timer_timeout(const boost::system::error_code& /*e*/,
boost::asio::steady_timer* t)
{
    loop();
    t->expires_at(t->expires_at() + std::chrono::milliseconds(one_tick));
    t->async_wait(boost::bind(timer_timeout,
              boost::asio::placeholders::error, t));
    ++iteration;
    if (iteration %1000 == iteration/1000 && swtch->state)
    sensr->publish_state(!sensr->state);

//    std::cout << "c";
}

boost::asio::io_service *network_io_service;


int main()
{

    try
    {
      using namespace boost::asio;
        boost::asio::io_service io_service;
      network_io_service = &io_service;

      steady_timer timer{io_service, std::chrono::milliseconds{one_tick}};
      timer.async_wait(boost::bind(timer_timeout,
                                   boost::asio::placeholders::error, &timer));


//      boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
//      signals.async_wait([&](auto, auto){ io_context.stop(); });

  	 setup();
      io_service.run();
    }
    catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }

    return 0;
}



