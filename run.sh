#!/bin/bash

sed -i 's/the_aerial_global_location_out/thread_gps_global_location_out/g' drone_impl/the_controller/activity.c &

sed -i 's/the_drone_rotor_global_rotor_power_in/thread_rotor_global_rotor_power_in/g' drone_impl/the_controller/activity.c &

(cd drone_impl/ ; make)
