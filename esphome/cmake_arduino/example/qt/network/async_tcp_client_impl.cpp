/*
 * async_tcp_client_impl.cpp
 *
 *  Created on: Mar 5, 2020
 *      Author: Oleksandr Omelchuk
 */

#include "async_tcp_client_impl.h"
#include "esphome/core/log.h"

namespace esphome {
namespace network {

AsyncTcpClientImpl::AsyncTcpClientImpl(::AsyncClient* wrapped) : AsyncClient() {}

AsyncTcpClientImpl::~AsyncTcpClientImpl() {}

bool AsyncTcpClientImpl::connect(const char* host, uint16_t port)
{
	return true;
}

void AsyncTcpClientImpl::close(bool now)
{
}

void AsyncTcpClientImpl::stop() {
}

int8_t AsyncTcpClientImpl::abort() { return true; }

bool AsyncTcpClientImpl::free() { return true; }

bool AsyncTcpClientImpl::canSend() const { return true; }

size_t AsyncTcpClientImpl::space() const { return 30000; }

size_t AsyncTcpClientImpl::add(const char* data, size_t size, bool wait_for_more) {

	return size;
}

bool AsyncTcpClientImpl::send() {
	return true;
}

size_t AsyncTcpClientImpl::write(const char* data) {
	return 0;
}

size_t AsyncTcpClientImpl::write(const char* data, size_t size) { return size; }

bool AsyncTcpClientImpl::connecting() const { return false; }

bool AsyncTcpClientImpl::connected() const { return true; }

bool AsyncTcpClientImpl::disconnecting() const { return false; }

bool AsyncTcpClientImpl::disconnected() const { return false; }

bool AsyncTcpClientImpl::freeable() const { return true; }
// disconnected or disconnecting

void AsyncTcpClientImpl::setNoDelay(bool nodelay) {

}

bool AsyncTcpClientImpl::getNoDelay() const {
	return true;
}

IPAddress AsyncTcpClientImpl::remoteIP() {
	return IPAddress();
}

// Set Callbacks

void AsyncTcpClientImpl::onConnect(AcConnectHandler cb, void* arg) {
//  impl_->onConnect([cb, this](void* arg, ::AsyncClient* client) { cb(arg, this); }, arg);
}

void AsyncTcpClientImpl::onDisconnect(AcConnectHandler cb, void* arg) {
//  impl_->onDisconnect([cb, this](void* arg, ::AsyncClient* client) { cb(arg, this); }, arg);
}

void AsyncTcpClientImpl::onAck(AcAckHandler cb, void* arg) {
//  impl_->onAck([cb, this](void* arg, ::AsyncClient* cli, size_t len, uint32_t time) { cb(arg, this, len, time); }, arg);
}

void AsyncTcpClientImpl::onError(AcErrorHandler cb, void* arg) {
//  impl_->onError([cb, this](void* arg, ::AsyncClient* client, int8_t error) { cb(arg, this, error); }, arg);
}

void AsyncTcpClientImpl::onData(AcDataHandler cb, void* arg) {
//  impl_->onData([cb, this](void* arg, ::AsyncClient* client, void* data, size_t len) { cb(arg, this, data, len); }, arg);
}

void AsyncTcpClientImpl::onPacket(AcPacketHandler cb, void* arg) {
//  impl_->onPacket([cb, this](void* arg, ::AsyncClient* client, struct pbuf* pb) { cb(arg, this, pb); }, arg);
}

void AsyncTcpClientImpl::onTimeout(AcTimeoutHandler cb, void* arg) {
//  impl_->onTimeout([cb, this](void* arg, ::AsyncClient* client, uint32_t time) { cb(arg, this, time); }, arg);
}

void AsyncTcpClientImpl::onPoll(AcConnectHandler cb, void* arg) {
//  impl_->onPoll([cb, this](void* arg, ::AsyncClient* client) { cb(arg, this); }, arg);
}

} /* namespace network */
} /* namespace esphome */
