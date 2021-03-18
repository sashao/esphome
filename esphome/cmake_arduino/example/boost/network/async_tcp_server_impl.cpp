/*
 * async_tcp_server_impl.cpp
 *
 *  Created on: Mar 5, 2020
 *      Author: Oleksandr Omelchuk
 */

#include "async_tcp_server_impl.h"
#include "async_tcp_client_impl.h"
#include "esphome/core/log.h"

#include <boost/bind.hpp>
#include <boost/asio.hpp>

extern boost::asio::io_service *network_io_service;

using boost::asio::ip::tcp;


namespace esphome {
namespace network {

AsyncServer *create_async_server(uint16_t port) {
    // Here it would be possible to return any transport implementation.
    // default is Arduino AsyncTCP
    return new AsyncTcpServerImpl(port);
}

AsyncTcpServerImpl::AsyncTcpServerImpl(uint16_t port)
    : acceptor_(*network_io_service, tcp::endpoint(tcp::v4(), port))
{
}

AsyncTcpServerImpl::~AsyncTcpServerImpl() {
    //	acceptor_.stop();
}

static std::vector<std::shared_ptr<AsyncTcpClientImpl>> clients;

void AsyncTcpServerImpl::accept()
{
    using boost::asio::ip::tcp;
    acceptor_.async_accept(
                [this](boost::system::error_code ec, tcp::socket socket)
    {
        if (!ec)
        {
            auto client = std::make_shared<AsyncTcpClientImpl>(std::move(socket));

            for(std::pair<AcConnectHandler, void*> &observer: onClient_)
            {
                observer.first(observer.second, client.get());
            }

            client->do_read();
            clients.push_back(client);
        }

        accept();
    }
    );
}

void AsyncTcpServerImpl::onClient(AcConnectHandler cb, void* arg) {
    onClient_.push_back(std::pair<AcConnectHandler, void*>(cb, arg));
}

void AsyncTcpServerImpl::begin() {
    accept();
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
