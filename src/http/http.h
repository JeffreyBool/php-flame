#pragma once
#include "../vendor.h"

namespace flame::http {
    
    class _connection_pool;
    class client;
    extern client* client_;
    extern std::int64_t body_max_size;

    void declare(php::extension_entry& ext);
    php::value get(php::parameters& params);
    php::value post(php::parameters& params);
    php::value put(php::parameters& params);
    php::value delete_(php::parameters& params);
    php::value exec(php::parameters& params);

    php::string ctype_encode(std::string_view ctype, const php::value& v);
    php::value ctype_decode(std::string_view ctype, const php::string& v, php::array* file = nullptr);
}
