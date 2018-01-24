#pragma once

#include <glm/glm.hpp>

enum class CAMERA_MOVEMENT 
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera 
{
    public:
        Camera();
        ~Camera();
    
        glm::mat4 get_view_matrix();
        void process_keyboard(CAMERA_MOVEMENT direction, float delta_time);
        void process_mouse_movement(float x_offset, float y_offset);
        void process_mouse_movement(float x_offset, float y_offset, float pitch_limit);
        void process_mouse_scroll(float offset);

    private:
        void update_camera_vectors();
        
        glm::vec3   _position;
        glm::vec3   _front;
        glm::vec3   _up;
        glm::vec3   _right;
        glm::vec3   _world_up;

        float       _yaw;
        float       _pitch;
        float       _movement_speed;
        float       _mouse_sensitivity;
        float       _zoom;
};

