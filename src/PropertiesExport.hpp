#ifndef PROPERTIES_EXPORT_H
#define PROPERTIES_EXPORT_H

#include <godot_cpp/classes/node.hpp>

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

#include "CustomResource.hpp"

namespace godot
{
    class PropertiesExport : public Node
    {
        GDCLASS(PropertiesExport, Node);

    protected:
        static void _bind_methods();

    public:
        int number;
        int ranged_number;
        String string;
        NodePath node_path;
        bool some_bool;
        Dictionary dictionary;
        Ref<Resource> resourse;
        Ref<CustomResource> cus_res;
        Ref<PackedScene> scene;

        PropertiesExport();
        ~PropertiesExport();

        void _ready() override;

        void set_number(int _number) { number = _number; }
        int get_number() { return number; }

        void set_ranged_number(int _ranged_number) { ranged_number = _ranged_number; }
        int get_ranged_number() { return ranged_number; }

        void set_string(String _string) { string = _string; }
        String get_string() { return string; }

        void set_node_path(NodePath _node_path) { node_path = _node_path; }
        NodePath get_node_path() { return node_path; }

        void set_some_bool(bool _some_bool) { some_bool = _some_bool; }
        bool get_some_bool() { return some_bool; }

        void set_dictionary(Dictionary _dictionary) { dictionary = _dictionary; }
        Dictionary get_dictionary() { return dictionary; }

        void set_resourse(Ref<Resource> _resourse) { resourse = _resourse; }
        Ref<Resource> get_resourse() { return resourse; }

        void set_cus_res(Ref<CustomResource> _cus_res) { cus_res = _cus_res; }
        Ref<CustomResource> get_cus_res() { return cus_res; }

        void set_scene(Ref<PackedScene> _scene) { scene = _scene; }
        Ref<PackedScene> get_scene() { return scene; }
    };
}

#endif
