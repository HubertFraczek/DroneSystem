#include <stdio.h>
#include <stdbool.h>

struct location {
	float x;
	float y;
};

void user_readweight_spg(float weight_in, float* weight_out){
    //prinft("user_readweight_spg");
    
    *weight_out = weight_in;
}

void user_readheight_spg(float height_in, float* height_out){
    //prinft("user_readheight_spg");
    
    *height_out = height_in;
}

void user_rotorpower_spg(float rotor_power_in, float* rotor_power_out){
    //prinft("user_rotorpower_spg");
    
    *rotor_power_out = rotor_power_in;
}

void user_scanarea_spg(bool blockade_in, bool* blockade_out){
    //prinft("user_scanarea_spg");
    
    *blockade_out = blockade_in;
}

void user_gpsdata_spg(struct location location_in, struct location* location_out){
    //prinft("user_gpsdata_spg");
    
    (*location_out).x = location_in.x;
    (*location_out).y = location_in.y;
}

void user_setnewtarget_spg(struct location new_target_in, struct location* new_target_out){
    //prinft("user_setnewtarget_spg");
    
    (*new_target_out).x = new_target_in.x;
    (*new_target_out).y = new_target_in.y;
}

void user_analysedata_spg(struct location location_in, float height_in, float weight_in, float* rotor_power_out, float rotor_power_in, struct location new_target, bool blockade_in, int* status_out){
    //prinft("user_analysedata_spg");
}
