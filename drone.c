#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct location
{
  float x;
  float y;
};

struct control
{
  float rotForward;
  float rotRight;
  float rotLeft;
  float rotBackward;
};

float calculateDirection(struct location p1, struct location p2);
float calculateDistance(struct location p1, struct location p2);

void user_readweight_spg(float weight_in, float *weight_out)
{
  //prinft("user_readweight_spg");

  *weight_out = weight_in;
}

void user_readheight_spg(float height_in, float *height_out)
{
  //prinft("user_readheight_spg");

  *height_out = height_in;
}

void user_rotorpower_spg(struct control rotor_power_in, struct control *rotor_power_out)
{
  //prinft("user_rotorpower_spg");

  (*rotor_power_out).rotForward = rotor_power_in.rotForward;
  (*rotor_power_out).rotRight = rotor_power_in.rotRight;
  (*rotor_power_out).rotLeft = rotor_power_in.rotLeft;
  (*rotor_power_out).rotBackward = rotor_power_in.rotBackward;
}

void user_scanarea_spg(bool blockade_in, bool *blockade_out)
{
  //prinft("user_scanarea_spg");

  *blockade_out = blockade_in;
}

void user_gpsdata_spg(struct location location_in, struct location *location_out)
{
  //prinft("user_gpsdata_spg");

  (*location_out).x = location_in.x;
  (*location_out).y = location_in.y;
}

void user_setnewtarget_spg(struct location new_target_in, struct location *new_target_out)
{
  //prinft("user_setnewtarget_spg");

  (*new_target_out).x = new_target_in.x;
  (*new_target_out).y = new_target_in.y;
}

void user_analysedata_spg(struct location location_in, float height_in, float weight_in, struct control *rotor_power_out, struct control rotor_power_in, struct location new_target, bool blockade_in, int *status_out)
{
  //prinft("user_analysedata_spg");

  if (blockade_in)
  {
    (*rotor_power_out).rotForward = 0;
    (*rotor_power_out).rotRight = 0;
    (*rotor_power_out).rotLeft = 0;
    (*rotor_power_out).rotBackward = 0;
  }

  if (location_in.x != new_target.x || location_in.y != new_target.y)
  {
    float direction = calculateDirection(location_in, new_target);

    (*rotor_power_out).rotForward = direction;
    (*rotor_power_out).rotRight = direction;
    (*rotor_power_out).rotLeft = direction;
    (*rotor_power_out).rotBackward = direction;
  }

  if (calculateDistance(location_in, new_target) < 1)
  {
    // landing
  }
}

float calculateDirection(struct location p1, struct location p2)
{
  float sin = p1.x * p2.y - p2.x * p1.y;
  float cos = p1.x * p2.x + p1.y * p2.y;

  float direction = atan2(sin, cos) * (180 / 3.14159265358979323846);
}

float calculateDistance(struct location p1, struct location p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
