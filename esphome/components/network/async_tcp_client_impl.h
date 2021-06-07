/*
 * async_tcp_client_impl.h
 *
 *  Created on: Mar 5, 2020
 *      Author: Oleksandr Omelchuk
 */

#pragma once

#include <memory>
#include "async_tcp.h"

class AsyncClient;

namespace esphome {
namespace network {

class AsyncTcpClientImpl : public AsyncClient {
 public:
  AsyncTcpClientImpl(::AsyncClient* wrapped);
  ~AsyncTcpClientImpl() override;

  bool connect(const char* host, uint16_t port) override;
  void close(bool now = false) override;
  void stop() override;
  int8_t abort() override;
  bool free() override;

  bool canSend() const override;
  size_t space() const override;                       // space available in the TCP window
  size_t add(const char* data, size_t size, bool wait_for_more = false) override;  // add for sending
  bool send() override;                                // send all data added with the method above

  size_t write(const char* data) override;
  size_t write(const char* data, size_t size) override;  // only when canSend() == true

  bool connecting() const override;
  bool connected() const override;
  bool disconnecting() const override;
  bool disconnected() const override;
  bool freeable() const override;  // disconnected or disconnecting

  void setNoDelay(bool nodelay) override;
  bool getNoDelay() const override;

  IPAddress remoteIP() override;

  // Set Callbacks
  void onConnect(AcConnectHandler cb, void* arg) override;     // on successful connect
  void onDisconnect(AcConnectHandler cb, void* arg) override;  // disconnected
  void onAck(AcAckHandler cb, void* arg) override;             // ack received
  void onError(AcErrorHandler cb, void* arg) override;         // unsuccessful connect or error
  void onData(AcDataHandler cb, void* arg) override;           // data received (called if onPacket is not
                                                                       // used)
  void onPacket(AcPacketHandler cb, void* arg) override;       // data received
  void onTimeout(AcTimeoutHandler cb, void* arg) override;     // ack timeout
  void onPoll(AcConnectHandler cb, void* arg) override;        // every 125ms when connected

 protected:
  std::unique_ptr<::AsyncClient> impl_;
};

} /* namespace network */
} /* namespace esphome */
