#include "PlayerTest.hpp"

#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

void PlayerTest::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_speed", "new_speed"), &PlayerTest::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &PlayerTest::get_speed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("set_jump_force", "new_jump_force"), &PlayerTest::set_jump_force);
    ClassDB::bind_method(D_METHOD("get_jump_force"), &PlayerTest::get_jump_force);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "jump_force"), "set_jump_force", "get_jump_force");

    ClassDB::bind_method(D_METHOD("set_gravity", "new_gravity"), &PlayerTest::set_gravity);
    ClassDB::bind_method(D_METHOD("get_gravity"), &PlayerTest::get_gravity);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "gravity"), "set_gravity", "get_gravity");
}

void PlayerTest::_ready()
{
    input = Input::get_singleton();
    anim = get_node<AnimatedSprite2D>("AnimatedSprite");
}

void PlayerTest::_physics_process(double delta)
{
    // get
    Vector2 velocity = get_velocity();

    // move left-right and flip
    velocity.x = (input->get_action_strength("ui_right") - input->get_action_strength("ui_left")) * speed;
    if (velocity.x > 0)
    {
        anim->play("run");
        anim->set_flip_h(true);
    }
    else if (velocity.x < 0)
    {
        anim->play("run");
        anim->set_flip_h(false);
    }
    else
        anim->play("idle");

    
    // gravity and jump
    if (!is_on_floor())
    {
        velocity.y += gravity * delta;
        velocity.x *= 0.7;
        anim->play("jump");
    }
    else
    {
        velocity.y = 0;
        // jump
        if (input->is_action_just_pressed("jump"))
        {
            velocity.y = -jump_force;
        }
    }

    // set
    set_velocity(velocity);
    move_and_slide();
}

PlayerTest::PlayerTest()
    : speed(300), jump_force(500), gravity(900)
{
    if (Engine::get_singleton()->is_editor_hint())
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
}

PlayerTest::~PlayerTest()
{
}