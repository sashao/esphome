

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

homeassistant::HomeassistantSensor *ha_hello_world;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="


#include <iostream>

void setup() {
  App.pre_setup("test-x86", __DATE__ ", " __TIME__, true);

  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
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
  App.setup();
}

void loop() {
	App.loop();
}


int main()
{
	setup();

	while (true) {
		loop();
	}

    return 0;
}



