#ifndef CUSTOM_RESOURSE_H
#define CUSTOM_RESOURSE_H

#include <godot_cpp/classes/resource.hpp>

namespace godot
{
    class CustomResource : public Resource
    {
        GDCLASS(CustomResource, Resource)
    protected:
        static void _bind_methods();

    public:
        int cus_res_num = 0;

        CustomResource();
        ~CustomResource();

        void set_cus_res_num(int new_cus_res_num) { cus_res_num = new_cus_res_num; }
        int get_cus_res_num() { return cus_res_num; }
    };
}

#endif
