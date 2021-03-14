// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using namespace time;
using namespace binary_sensor;
using namespace climate;
using namespace switch_;
logger::Logger *logger_logger;
//web_server_base::WebServerBase *web_server_base_webserverbase;
//ethernet::EthernetComponent *ethernet_ethernetcomponent;
//ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace sensor;
using namespace api;

homeassistant::HomeassistantSensor *ha_hello_world;

//web_server::WebServer *web_server_webserver;
//using namespace i2c;
//i2c::I2CComponent *i2c_i2ccomponent;
//using namespace spi;
//spi::SPIComponent *spi_spicomponent;
//using namespace json;
//using namespace uart;
//uart::UARTComponent *uart_uartcomponent;
//sntp::SNTPComponent *sntp_time;
//tuya::Tuya *tuya_tuya;
//homeassistant::HomeassistantSensor *ha_hello_world;
//tuya::TuyaSensor *tuya_sensor;
//tuya::TuyaBinarySensor *tuya_binary_sensor;
//tuya::TuyaClimate *tuya_climate;
//tuya::TuyaSwitch *tuya_switch;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: test-4
  //   platform: ESP32
  //   board: nodemcu-32s
  //   build_path: build/test4
  //   arduino_version: espressif32@1.12.4
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  App.pre_setup("test-x86", __DATE__ ", " __TIME__);
  // time:
  // binary_sensor:
  // climate:
  // switch:
  // logger:
  //   level: DEBUG
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   hardware_uart: UART0
  //   logs: {}
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
//  web_server_base_webserverbase = new web_server_base::WebServerBase();
//  App.register_component(web_server_base_webserverbase);
  // ethernet:
  //   type: LAN8720
  //   mdc_pin: 23
  //   mdio_pin: 25
  //   clk_mode: GPIO0_IN
  //   phy_addr: 0
  //   power_pin:
  //     number: 25
  //     mode: OUTPUT
  //     inverted: false
  //   manual_ip:
  //     static_ip: 192.168.178.56
  //     gateway: 192.168.178.1
  //     subnet: 255.255.255.0
  //     dns1: 0.0.0.0
  //     dns2: 0.0.0.0
  //   domain: .local
  //   id: ethernet_ethernetcomponent
  //   use_address: 192.168.178.56
//  ethernet_ethernetcomponent = new ethernet::EthernetComponent();
//  App.register_component(ethernet_ethernetcomponent);
//  ethernet_ethernetcomponent->set_phy_addr(0);
//  ethernet_ethernetcomponent->set_mdc_pin(23);
//  ethernet_ethernetcomponent->set_mdio_pin(25);
//  ethernet_ethernetcomponent->set_type(ethernet::ETHERNET_TYPE_LAN8720);
//  ethernet_ethernetcomponent->set_clk_mode(ETH_CLOCK_GPIO0_IN);
//  ethernet_ethernetcomponent->set_use_address("192.168.178.56");
//  ethernet_ethernetcomponent->set_power_pin(new GPIOPin(25, OUTPUT, false));
//  ethernet_ethernetcomponent->set_manual_ip(ethernet::ManualIP{
//      .static_ip = IPAddress(192, 168, 178, 56),
//      .gateway = IPAddress(192, 168, 178, 1),
//      .subnet = IPAddress(255, 255, 255, 0),
//      .dns1 = IPAddress(0, 0, 0, 0),
//      .dns2 = IPAddress(0, 0, 0, 0),
//  });
  // ota:
  //   safe_mode: true
  //   port: 3286
  //   id: ota_otacomponent
  //   password: ''
  //   reboot_timeout: 5min
  //   num_attempts: 10
//  ota_otacomponent = new ota::OTAComponent();
//  ota_otacomponent->set_port(3286);
//  ota_otacomponent->set_auth_password("");
//  App.register_component(ota_otacomponent);
//  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  App.register_component(api_apiserver);
  // web_server:
  //   auth:
  //     username: admin
  //     password: admin
  //   id: web_server_webserver
  //   port: 80
  //   css_url: https:esphome.io/_static/webserver-v1.min.css
  //   js_url: https:esphome.io/_static/webserver-v1.min.js
  //   web_server_base_id: web_server_base_webserverbase
  // sensor:
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
//  web_server_webserver = new web_server::WebServer(web_server_base_webserverbase);
//  App.register_component(web_server_webserver);
//  web_server_base_webserverbase->set_port(80);
//  web_server_webserver->set_css_url("https://esphome.io/_static/webserver-v1.min.css");
//  web_server_webserver->set_js_url("https://esphome.io/_static/webserver-v1.min.js");
//  web_server_webserver->set_username("admin");
//  web_server_webserver->set_password("admin");
  // i2c:
  //   sda: 21
  //   scl: 22
  //   scan: false
  //   id: i2c_i2ccomponent
  //   frequency: 50000.0
//  i2c_i2ccomponent = new i2c::I2CComponent();
//  App.register_component(i2c_i2ccomponent);
  // spi:
  //   clk_pin:
  //     number: 21
  //     mode: OUTPUT
  //     inverted: false
  //   mosi_pin:
  //     number: 22
  //     mode: OUTPUT
  //     inverted: false
  //   miso_pin:
  //     number: 23
  //     mode: INPUT
  //     inverted: false
  //   id: spi_spicomponent
//  spi_spicomponent = new spi::SPIComponent();
//  App.register_component(spi_spicomponent);
  // json:
  // substitutions:
  //   devicename: test-4
  // uart:
  //   tx_pin: 22
  //   rx_pin: 23
  //   baud_rate: 115200
  //   id: uart_uartcomponent
  //   rx_buffer_size: 256
  //   invert: false
  //   stop_bits: 1
  //   data_bits: 8
  //   parity: NONE
//  uart_uartcomponent = new uart::UARTComponent();
//  App.register_component(uart_uartcomponent);
  // time.sntp:
  //   platform: sntp
  //   id: sntp_time
  //   timezone: UTC0
  //   update_interval: 15min
  //   servers:
  //   - 0.pool.ntp.org
  //   - 1.pool.ntp.org
  //   - 2.pool.ntp.org
//  sntp_time = new sntp::SNTPComponent();
//  sntp_time->set_servers("0.pool.ntp.org", "1.pool.ntp.org", "2.pool.ntp.org");
//  sntp_time->set_update_interval(900000);
//  App.register_component(sntp_time);
  // tuya:
  //   time_id: sntp_time
  //   id: tuya_tuya
  //   uart_id: uart_uartcomponent
//  tuya_tuya = new tuya::Tuya();
//  App.register_component(tuya_tuya);
  // sensor.homeassistant:
  //   platform: homeassistant
  //   entity_id: sensor.hello_world
  //   id: ha_hello_world
  //   force_update: false
  //   accuracy_decimals: 1
  //   name: ha_hello_world
  //   internal: true
  ha_hello_world = new homeassistant::HomeassistantSensor();
  App.register_component(ha_hello_world);
  // sensor.tuya:
  //   platform: tuya
  //   id: tuya_sensor
  //   sensor_datapoint: 1
  //   force_update: false
  //   tuya_id: tuya_tuya
  //   name: tuya_sensor
  //   internal: true

  App.register_sensor(ha_hello_world);
  ha_hello_world->set_name("ha_hello_world");
  ha_hello_world->set_internal(true);
  ha_hello_world->set_accuracy_decimals(1);
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
}



