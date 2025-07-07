#include "BouncingSprite.hpp"

#include "godot_cpp/classes/engine.hpp"

using namespace godot;

void BouncingSprite::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_speed", "new_speed"), &BouncingSprite::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &BouncingSprite::get_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("direction_changed", PropertyInfo(Variant::OBJECT, "node")));
}

BouncingSprite::BouncingSprite()
: left_Bounds(0), right_Bounds(1150), top_Bounds(0), bottom_Bounds(650), speed(10), velocity(speed, speed)
{
    if(Engine::get_singleton()->is_editor_hint())
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
}

BouncingSprite::~BouncingSprite()
{

}

void BouncingSprite::_process(double delta)
{
    Ref<Texture2D> texture = get_texture();
   if (!texture.is_valid()) {
        UtilityFunctions::print("BouncingSprite: Texture is not set!");
        return;
    }
    Vector2 pos = get_position();
    Vector2 size = texture->get_size();

    if(pos.x < left_Bounds + size.x / 2)
    {
        if(velocity.x < 0)
            emit_signal("direction_changed", this);
        velocity.x = speed;
    }
    else if(pos.x > right_Bounds - size.x / 2)
    {
        if(velocity.x > 0)
            emit_signal("direction_changed", this);
        velocity.x = -speed;
    }
    
    
    if(pos.y < top_Bounds + size.y / 2)
    {
        if(velocity.y < 0)
            emit_signal("direction_changed", this);
        velocity.y = speed;
    }
    else if(pos.y > bottom_Bounds - size.x / 2)
    {
        if(velocity.y > 0)
            emit_signal("direction_changed", this);
        velocity.y = -speed;
    }


    pos += velocity;
    set_position(pos);
}

void BouncingSprite::set_speed(double new_speed)
{
    speed = new_speed;
    velocity = velocity.normalized() * speed;
}

