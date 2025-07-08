#include "EnemyTest.hpp"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/vector2.hpp>


using namespace godot;

void EnemyTest::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_speed", "new_speed"), &EnemyTest::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &EnemyTest::get_speed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("set_damage", "new_damage"), &EnemyTest::set_damage);
    ClassDB::bind_method(D_METHOD("get_damage"), &EnemyTest::get_damage);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "damage"), "set_damage", "get_damage");

    ClassDB::bind_method(D_METHOD("set_health", "new_health"), &EnemyTest::set_health);
    ClassDB::bind_method(D_METHOD("get_health"), &EnemyTest::get_health);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "health"), "set_health", "get_health");

    ClassDB::bind_method(D_METHOD("_body_entered", "body"), &EnemyTest::_body_entered);
    ClassDB::bind_method(D_METHOD("_body_exited", "body"), &EnemyTest::_body_exited);
}

EnemyTest::EnemyTest()
: speed(100), damage(10), health(50), gravity(900), player(nullptr)
{
    if (Engine::get_singleton()->is_editor_hint())
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
}

EnemyTest::~EnemyTest()
{}

void EnemyTest::_ready()
{
    anim = get_node<AnimatedSprite2D>("AnimSpr");
    angry_area = get_node<Area2D>("AngryArea");
    if(angry_area)
    {
        angry_area->connect("body_entered", Callable(this, "_body_entered"));
        angry_area->connect("body_exited", Callable(this, "_body_exited"));
    }
}

void EnemyTest::_physics_process(double delta)
{
    // get
    Vector2 velocity = get_velocity();

    if(player)
    {
        velocity.x = (player->get_position() - get_position()).normalized().x * speed;
        anim->play("run");
        if(velocity.x > 0)
            anim->set_flip_h(true);
        else if(velocity.x < 0)
            anim->set_flip_h(false);
    }
    else
    {
        anim->play("idle");
        velocity.x = 0;
    }

    // gravity
    if(!is_on_floor())
    {
        velocity.y += gravity * delta;
    }

    // set
    set_velocity(velocity);
    move_and_slide();
}

void EnemyTest::_body_entered(Node *body)
{
    player = Object::cast_to<PlayerTest>(body);
}

void EnemyTest::_body_exited(Node *body)
{
    if(body->is_class("PlayerTest"))
        player = nullptr;
    
}