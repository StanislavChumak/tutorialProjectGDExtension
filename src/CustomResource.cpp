#include "CustomResource.hpp"

using namespace godot;

void CustomResource::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_cus_res_num", "new_cus_res_num"), &CustomResource::set_cus_res_num);
    ClassDB::bind_method(D_METHOD("get_cus_res_num"), &CustomResource::get_cus_res_num);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "cus_res_num"), "set_cus_res_num", "get_cus_res_num");
}

CustomResource::CustomResource(){}

CustomResource::~CustomResource(){}
