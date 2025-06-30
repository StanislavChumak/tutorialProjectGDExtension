#include "PropertiesExport.hpp"

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void PropertiesExport::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_number", "new_number"), &PropertiesExport::set_number);
    ClassDB::bind_method(D_METHOD("get_number"), &PropertiesExport::get_number);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "number"), "set_number", "get_number");

    ClassDB::bind_method(D_METHOD("set_ranged_number", "new_ranged_number"), &PropertiesExport::set_ranged_number);
    ClassDB::bind_method(D_METHOD("get_ranged_number"), &PropertiesExport::get_ranged_number);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "ranged_number", PROPERTY_HINT_RANGE, "0, 256, 1"), "set_ranged_number", "get_ranged_number");

    ClassDB::bind_method(D_METHOD("set_string", "new_string"), &PropertiesExport::set_string);
    ClassDB::bind_method(D_METHOD("get_string"), &PropertiesExport::get_string);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "string"), "set_string", "get_string");

    ClassDB::bind_method(D_METHOD("set_node_path", "new_node_path"), &PropertiesExport::set_node_path);
    ClassDB::bind_method(D_METHOD("get_node_path"), &PropertiesExport::get_node_path);
    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "node path"), "set_node_path", "get_node_path");

    ClassDB::bind_method(D_METHOD("set_some_bool", "new_some_bool"), &PropertiesExport::set_some_bool);
    ClassDB::bind_method(D_METHOD("get_some_bool"), &PropertiesExport::get_some_bool);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "some bool"), "set_some_bool", "get_some_bool");

    ClassDB::bind_method(D_METHOD("set_dictionary", "new_dictionaryl"), &PropertiesExport::set_dictionary);
    ClassDB::bind_method(D_METHOD("get_dictionary"), &PropertiesExport::get_dictionary);
    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "dictionary"), "set_dictionary", "get_dictionary");

    ClassDB::bind_method(D_METHOD("set_resourse", "new_resourse"), &PropertiesExport::set_resourse);
    ClassDB::bind_method(D_METHOD("get_resourse"), &PropertiesExport::get_resourse);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "resourse", PROPERTY_HINT_RESOURCE_TYPE, "Resourse"), "set_resourse", "get_resourse");

    ClassDB::bind_method(D_METHOD("set_cus_res", "new_cus_res"), &PropertiesExport::set_cus_res);
    ClassDB::bind_method(D_METHOD("get_cus_res"), &PropertiesExport::get_cus_res);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "cus_res", PROPERTY_HINT_RESOURCE_TYPE, "CustomResource"), "set_cus_res", "get_cus_res");

    ClassDB::bind_method(D_METHOD("set_scene", "new_scene"), &PropertiesExport::set_scene);
    ClassDB::bind_method(D_METHOD("get_scene"), &PropertiesExport::get_scene);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "scene", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "set_scene", "get_scene");
}

PropertiesExport::PropertiesExport(){}
PropertiesExport::~PropertiesExport(){}

void PropertiesExport::_ready()
{
    if(scene == nullptr) return;
    Node* inst = scene->instantiate();
    if(typeid(*inst) == typeid(Sprite2D))
        UtilityFunctions::print("Node is a Sprite2D");
    else
        UtilityFunctions::print("Node is NOT a Sprite2D");
    add_child(inst);
    UtilityFunctions::print(inst->get_name());
    
}