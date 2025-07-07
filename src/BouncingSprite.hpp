#ifndef BOUNCING_SPRITE_H
#define BOUNCING_SPRITE_H

#include "godot_cpp/classes/sprite2d.hpp"
#include "godot_cpp/variant/vector2.hpp"

namespace godot 
{
    class BouncingSprite : public Sprite2D
    {
        GDCLASS(BouncingSprite, Sprite2D);

    public:
        double left_Bounds;
        double right_Bounds;
        double top_Bounds;
        double bottom_Bounds;
        double speed;
        Vector2 velocity;

    protected:
        static void _bind_methods();

    public:
        BouncingSprite();
        ~BouncingSprite();

        void set_speed(double new_speed);
        double get_speed() { return speed; }

        void _process(double delta) override;

    };
}

#endif
