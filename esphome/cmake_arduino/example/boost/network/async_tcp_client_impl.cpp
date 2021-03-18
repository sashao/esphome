/*
 * async_tcp_client_impl.cpp
 *
 *  Created on: Mar 5, 2020
 *      Author: Oleksandr Omelchuk
 */

#include "async_tcp_client_impl.h"
#include "esphome/core/log.h"

using boost::asio::ip::tcp;


namespace esphome {
namespace network {

AsyncTcpClientImpl::AsyncTcpClientImpl(boost::asio::ip::tcp::socket socket) :
		AsyncClient(),
		 socket_(std::move(socket))
{
}

AsyncTcpClientImpl::~AsyncTcpClientImpl()
{

}

void AsyncTcpClientImpl::do_read()
{
  auto self(shared_from_this());
  socket_.async_read_some(boost::asio::buffer(data_, max_length),
      [this, self](boost::system::error_code ec, std::size_t length)
      {
        if (!ec)
        {

            for(std::pair<AcDataHandler, void*> &observer: onData_)
            {
                observer.first(observer.second, this, data_, length);
            }

//        		do_write(length);
        }
      });
}

void AsyncTcpClientImpl::do_write(std::size_t length)
{
}


bool AsyncTcpClientImpl::connect(const char* host, uint16_t port)
{
	return true;
}

void AsyncTcpClientImpl::close(bool now)
{
}

void AsyncTcpClientImpl::stop()
{
}

int8_t AsyncTcpClientImpl::abort()
{
    return true;
}

bool AsyncTcpClientImpl::free()
{
    return true;
}

bool AsyncTcpClientImpl::canSend() const
{
    return true;
}

size_t AsyncTcpClientImpl::space() const
{
    return 30000;
}

size_t AsyncTcpClientImpl::add(const char* data, size_t size, bool /*wait_for_more*/) {

    return write(data, size);
}

bool AsyncTcpClientImpl::send() {
	return true;
}

size_t AsyncTcpClientImpl::write(const char* data)
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, strlen(data)),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {

          }
        });
    return 0;
}

size_t AsyncTcpClientImpl::write(const char* data, size_t size)
{



    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, size),
        [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
          if (!ec)
          {

          }
        });


    return size;
}

bool AsyncTcpClientImpl::connecting() const
{
    return false;
}

bool AsyncTcpClientImpl::connected() const
{
    return true;
}

bool AsyncTcpClientImpl::disconnecting() const
{
    return false;
}

bool AsyncTcpClientImpl::disconnected() const
{
    return false;
}

bool AsyncTcpClientImpl::freeable() const
{
    return true;
}
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
	onConnect_.push_back(std::pair<AcConnectHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onDisconnect(AcConnectHandler cb, void* arg) {
	onDisconnect_.push_back(std::pair<AcConnectHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onAck(AcAckHandler cb, void* arg) {
	onAck_.push_back(std::pair<AcAckHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onError(AcErrorHandler cb, void* arg) {
	onError_.push_back(std::pair<AcErrorHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onData(AcDataHandler cb, void* arg) {
	onData_.push_back(std::pair<AcDataHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onPacket(AcPacketHandler cb, void* arg) {
	onPacked_.push_back(std::pair<AcPacketHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onTimeout(AcTimeoutHandler cb, void* arg) {
	onTimeout_.push_back(std::pair<AcTimeoutHandler, void*>(cb, arg));
}

void AsyncTcpClientImpl::onPoll(AcConnectHandler cb, void* arg) {
	onPoll_.push_back(std::pair<AcConnectHandler, void*>(cb, arg));
}

} /* namespace network */
} /* namespace esphome */
