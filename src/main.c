#include <pebble.h>
/*this is an example of how you can use a loop to get all of the variables from an array in C. */
    
Window *my_window;
BitmapLayer *bitmap_layer;

//Here is where most of our attention is going to be directed for this exercise--------------

//here we are telling our program to set aside enough room in memory to accomodate an array of 
//bit maps that is 4 elements long.
GBitmap *robit[4];
//This is the placeholder, that we will use to drop our image into
//after our code makes a decision below.
GBitmap *selected_robit_image;

//This is our boolean variable, that we will use to determine if it is robot time, or not.
//which will in turn determine which picture is shown
bool its_robot_time;


static void main_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  bitmap_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  
  
//arrays start counting at zero, and therefore, so do we.  
  robit[0] = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_LEFT);
  robit[1] = gbitmap_create_with_resource(RESOURCE_ID_BLANK);
  robit[2] = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_LEFT2);
  robit[3] = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_WHISTLE);
  
  
//now we are going to indicate whether or not it is robot time, by which I mean
//should we show a robot picutre when the following code runs, or not.
  its_robot_time = true;
  
  
//we are now going to loop through our array using the "i" variable to advance through
// the elements in the array.
//since arrays count starting at zero, that is where our counter is going to start as well.
  for(int i = 0; i < 4 ; i++){

    //so every time this loop runs, we are going to check to see if the its_robot_time variable
    //contains a "true" value.
    
    //if its_robot_time is true, we will store the current item in the "selected_robit_image" variable
    //which we will later assign to the bitmap layer so that it appears when we run the program.
    if(its_robot_time == true){
      selected_robit_image = robit[i];
    }
    //if its_robot_time is false, we will always assign the 2nd element in the array, which is our blank
    //image.  No robot time.  No robot picture.
    else{
      selected_robit_image = robit[1];
    }
    
    
    //What is one way that you could change which robot picture is being displayed?
    
    //why is the robot whistle image being displayed instead of robot left or right?
    
  }
  
  
  //------------------------------------------------------------------------------------------
  
  
  bitmap_layer_set_bitmap(bitmap_layer, selected_robit_image);
  
  layer_add_child(window_layer, bitmap_layer_get_layer(bitmap_layer));

}

static void main_window_unload(){
   bitmap_layer_destroy(bitmap_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
