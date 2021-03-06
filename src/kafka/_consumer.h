#pragma once
#include "../vendor.h"
#include "../coroutine.h"

namespace flame {
    template <class T>
    class coroutine_queue;
}

namespace flame::kafka {
    // 消费者
    // 目前的实现方式无需 shared_from_this 管理
    class _consumer/*: public std::enable_shared_from_this<_consumer> */{
    public:
        _consumer(php::array& config, php::array& topics);
        ~_consumer();
        void subscribe(coroutine_handler& ch);
        void consume(coroutine_queue<php::object>& q, coroutine_handler& ch);
        void commit(const php::object& msg, coroutine_handler& ch);
        void close(coroutine_handler& ch);
    private:
        rd_kafka_t* conn_;
        rd_kafka_topic_partition_list_t* tops_;
        bool       close_;
        static void on_error(rd_kafka_t* conn, int error, const char* reason, void* data);
    };
} // namespace flame::kafka
