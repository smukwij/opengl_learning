#pragma once

#include <string>

class Uniform
{
    public:
        Uniform();
        ~Uniform();
        void init(uint32_t program_id, const std::string& name);
        void set_value(const float* value) const;
    private:
        int32_t _location;
};
