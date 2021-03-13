/*
 * async_tcp_server_impl.h
 *
 *  Created on: Mar 5, 2020
 *      Author: Oleksandr Omelchuk
 */

#pragma once

#include <memory>
#include "async_tcp.h"

class AsyncServer;

namespace esphome {
namespace network {

class AsyncTcpServerImpl : public AsyncServer {
 public:
  AsyncTcpServerImpl(uint16_t port);
  ~AsyncTcpServerImpl() override;

  void onClient(AcConnectHandler cb, void* arg) override;
  void begin() override;
  void end() override;
  void setNoDelay(bool nodelay) override;
  bool getNoDelay() const override;

 protected:
  std::unique_ptr<::AsyncServer> impl_;
};

} /* namespace network */
} /* namespace esphome */
