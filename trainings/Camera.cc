#include "Camera.hh"

#include <cmath>
#include <glm/gtc/matrix_transform.hpp>


Camera::Camera()
    : _position(0.0f, 0.0f, 0.0f)
    , _front(0.0f, 0.0f, -1.0f)
    , _world_up (0.0f, 1.0f, 0.0f)
    , _yaw(-90.0f)
    , _pitch(0.0f)
    , _movement_speed(2.5f)
    , _mouse_sensitivity(0.1f)
    , _zoom(45.0f)
{
    update_camera_vectors();
}

Camera::~Camera() = default;


glm::mat4 Camera::get_view_matrix()
{
    return glm::lookAt(_position, _position + _front, _up);
}

void Camera::process_keyboard(CAMERA_MOVEMENT direction, float delta_time)
{
    float velocity = _movement_speed * delta_time;
    switch(direction)
    {
        case CAMERA_MOVEMENT::FORWARD:
            _position += _front * velocity;
            break;
        case CAMERA_MOVEMENT::BACKWARD:
            _position -= _front * velocity;
            break;
        case CAMERA_MOVEMENT::LEFT:
            _position -= _right * velocity;
            break;
        case CAMERA_MOVEMENT::RIGHT:
            _position += _right * velocity;
    }
}

void Camera::process_mouse_movement(float x_offset, float y_offset)
{
    constexpr float default_pitch_limit = 89.0f;
    process_mouse_movement(x_offset, y_offset, default_pitch_limit);
}

void Camera::process_mouse_movement(float x_offset, float y_offset, float pitch_limit)
{
    _yaw += x_offset * _mouse_sensitivity;
    _pitch += y_offset * _mouse_sensitivity;

    if( _pitch > pitch_limit)
        _pitch = pitch_limit;
    else if( _pitch < (-1 * pitch_limit))
        _pitch = pitch_limit * (-1);
    
    update_camera_vectors();
}

void Camera::process_mouse_scroll(float offset)
{
    _zoom -= offset;
    if(_zoom < 1.0f)
        _zoom = 1.0f;
    else if( _zoom > 45.0f)
        _zoom = 45.0f;
}


void Camera::update_camera_vectors()
{
    glm::vec3 front;
    front.x = std::cos(glm::radians(_yaw)) * std::cos(glm::radians(_pitch));
    front.y = std::sin(glm::radians(_pitch));
    front.z = std::sin(glm::radians(_yaw)) * std::cos(glm::radians(_pitch));
    
    _front = glm::normalize(front);
    _right = glm::normalize(glm::cross(_front, _world_up));
    _up = glm::normalize(glm::cross(_right, _front));
}

