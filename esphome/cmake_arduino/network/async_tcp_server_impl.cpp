/*
 * async_tcp_server_impl.cpp
 *
 *  Created on: Mar 5, 2020
 *      Author: Oleksandr Omelchuk
 */

#include "async_tcp_server_impl.h"
#include "async_tcp_client_impl.h"
#include "esphome/core/log.h"

namespace esphome {
namespace network {

AsyncServer *create_async_server(uint16_t port) {
  // Here it would be possible to return any transport implementation.
  // default is Arduino AsyncTCP
  return new AsyncTcpServerImpl(port);
}


AsyncTcpServerImpl::AsyncTcpServerImpl(uint16_t port) {}

AsyncTcpServerImpl::~AsyncTcpServerImpl() {
//	impl_->end();
}

void AsyncTcpServerImpl::onClient(AcConnectHandler cb, void* arg) {
//  impl_->onClient(
//      [cb](void* arg, ::AsyncClient* connection) {
//        AsyncTcpClientImpl* client_wrapper = new AsyncTcpClientImpl(connection);
//        cb(arg, client_wrapper);
//      },
//      arg);
}

void AsyncTcpServerImpl::begin() {
//	impl_->begin();
}

void AsyncTcpServerImpl::end() {
//	impl_->end();
}

void AsyncTcpServerImpl::setNoDelay(bool nodelay) {
//	impl_->setNoDelay(nodelay);
}

bool AsyncTcpServerImpl::getNoDelay() const {
    return true;
//	return impl_->getNoDelay();
}

} /* namespace network */
} /* namespace esphome */
