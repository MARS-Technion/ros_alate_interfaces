# ros_alate_interfaces

ROS2 interfaces for the [ros_alate](https://github.com/MARS-Technion/ros_alate) adapter.

## Usage

### input

```console
ros2 topic pub /alate_input_operator_command ros_alate_interfaces/msg/OpCom "{op_com_enum : 1}"
```

```console
ros2 topic pub /alate_input_velocity geometry_msgs/msg/Twist "{linear : {x : 1, y : 2, z : 3}, angular: {x : 4, y : 5, z : 6}}" --once
```
