#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>

namespace godot
{
    class PlayerTest : public CharacterBody2D
    {
        GDCLASS(PlayerTest, CharacterBody2D);
        
    public:
        int speed;
        int jump_force;
        int gravity;
        Input *input;

    protected:
        static void _bind_methods();
        
    public:
    
        PlayerTest();
        ~PlayerTest();

        void _ready() override;
        void _physics_process(double delta) override;

        void set_speed(double new_speed) { speed = new_speed; }
        double get_speed() { return speed; }

        void set_jump_force(int new_jump_force) { jump_force = new_jump_force; }
        int get_jump_force() { return jump_force; }

        void set_gravity(double new_gravity) { gravity = new_gravity; }
        double get_gravity() { return gravity; }
    };
}

#endif
