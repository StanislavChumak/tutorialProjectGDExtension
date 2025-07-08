#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

#include "godot_cpp/classes/character_body2d.hpp"
#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/area2d.hpp"

#include "PlayerTest.hpp"

namespace godot
{
    class EnemyTest : public CharacterBody2D
    {
        GDCLASS(EnemyTest, CharacterBody2D);

        int speed;
        int damage;
        int health;
        int gravity;

        AnimatedSprite2D *anim;
        Area2D *angry_area;
        PlayerTest *player;

    private:
        static void _bind_methods();

    public:
        EnemyTest();
        ~EnemyTest();

        void _ready() override;
        void _physics_process(double delta) override;

        void _body_entered(Node *body);
        void _body_exited(Node *body);

        void set_speed(int new_speed) { speed = new_speed; }
        int get_speed() { return speed; }

        void set_damage(int new_damage) { damage = new_damage; }
        int get_damage() { return damage; }

        void set_health(int new_health) { health = new_health; }
        int get_health() { return health; }
    };
}

#endif
