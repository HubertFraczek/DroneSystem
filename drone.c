#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float ROTOR_MAX_POWER = 1000;

struct location {
  float x;
  float y;
};

struct control {
  float rotUpperLeft;
  float rotUpperRight;
  float rotLowerRight;
  float rotLowerLeft;
};

float calculateDirection(struct location p1, struct location p2);
float calculateDistance(struct location p1, struct location p2);

void user_readweight_spg(float weight_in, float *weight_out) {
  //prinft("user_readweight_spg");

  *weight_out = weight_in;
}

void user_readheight_spg(float height_in, float *height_out) {
  //prinft("user_readheight_spg");

  *height_out = height_in;
}

void user_rotorpower_spg(struct control rotor_power_in, struct control *rotor_power_out) {
  //prinft("user_rotorpower_spg");

  (*rotor_power_out).rotUpperLeft = rotor_power_in.rotUpperLeft;
  (*rotor_power_out).rotUpperRight = rotor_power_in.rotUpperRight;
  (*rotor_power_out).rotLowerRight = rotor_power_in.rotLowerRight;
  (*rotor_power_out).rotLowerLeft = rotor_power_in.rotLowerLeft;
}

void user_scanarea_spg(bool blockade_in, bool *blockade_out) {
  //prinft("user_scanarea_spg");

  *blockade_out = blockade_in;
}

void user_gpsdata_spg(struct location location_in, struct location *location_out) {
  //prinft("user_gpsdata_spg");

  (*location_out).x = location_in.x;
  (*location_out).y = location_in.y;
}

void user_setnewtarget_spg(struct location new_target_in, struct location *new_target_out) {
  //prinft("user_setnewtarget_spg");

  (*new_target_out).x = new_target_in.x;
  (*new_target_out).y = new_target_in.y;
}

void user_analysedata_spg(struct location location_in, float height_in, float weight_in, struct control *rotor_power_out, struct control rotor_power_in, struct location new_target, bool blockade_in, int *status_out) {
  //prinft("user_analysedata_spg");

  if (blockade_in) {
    (*rotor_power_out).rotUpperLeft = ROTOR_MAX_POWER;
    (*rotor_power_out).rotUpperRight = ROTOR_MAX_POWER;
    (*rotor_power_out).rotLowerRight = ROTOR_MAX_POWER;
    (*rotor_power_out).rotLowerLeft = ROTOR_MAX_POWER;
  } else {
    if (calculateDistance(location_in, new_target) < 1) {
      // landing
    } else {
      float direction = calculateDirection(location_in, new_target);

      if (direction == 0) {
        // go straight forward
        (*rotor_power_out).rotUpperLeft = ROTOR_MAX_POWER;
        (*rotor_power_out).rotUpperRight = ROTOR_MAX_POWER;
        (*rotor_power_out).rotLowerRight = rotor_power_in.rotLowerRight;
        (*rotor_power_out).rotLowerLeft = rotor_power_in.rotLowerLeft;
      } else if (direction > 0 && direction <= 180) {
        // turn left
        (*rotor_power_out).rotUpperLeft = ROTOR_MAX_POWER;
        (*rotor_power_out).rotUpperRight = rotor_power_in.rotUpperRight;
        (*rotor_power_out).rotLowerRight = ROTOR_MAX_POWER;
        (*rotor_power_out).rotLowerLeft = rotor_power_in.rotLowerLeft;
      } else {
        // turn right
        (*rotor_power_out).rotUpperLeft = rotor_power_in.rotUpperLeft;
        (*rotor_power_out).rotUpperRight = ROTOR_MAX_POWER;
        (*rotor_power_out).rotLowerRight = rotor_power_in.rotLowerRight;
        (*rotor_power_out).rotLowerLeft = ROTOR_MAX_POWER;
      }
    }
  }
}

float calculateDirection(struct location p1, struct location p2) {
  float sin = p1.x * p2.y - p2.x * p1.y;
  float cos = p1.x * p2.x + p1.y * p2.y;

  float direction = atan2(sin, cos) * (180 / 3.14159265358979323846);
}

float calculateDistance(struct location p1, struct location p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


void set_new_target_operator_spg(struct location current_location, int status_change, stuct location* new_target) {

}
