#pragma once

#include <vector>
#include <cstdint>
#include <memory>

class Program
{
    public:
        Program();
        ~Program() = default;
        void add_shader_id(const uint32_t id);
        void create();
        void use() const;

        uint32_t get_id() const;

        void use_uniform();
        bool is_uniform() const;

    private:
        uint32_t _id;
        bool _use_uniform;
        std::vector<uint32_t> _shader_ids;
};


using ProgramUPtr = std::unique_ptr<Program>;

inline ProgramUPtr create_program(uint32_t vs_id, uint32_t fs_id)
{
    ProgramUPtr pr (new Program);
    pr->add_shader_id(vs_id);
    pr->add_shader_id(fs_id);
    pr->create();

    return pr;
}

