#pragma once

#include <vector>
#include <cstdint>

class Program
{
    public:
        Program();
        ~Program() = default;
        void add_shader_id(const uint32_t id);
        void create();

        uint32_t get_id() const;

    private:
        uint32_t _id;
        std::vector<uint32_t> _shader_ids;
};
