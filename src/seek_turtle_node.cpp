#include "Seeker.h"

/*
	This node spawns new turtle to seek out the original turtle
*/

int main(int argc, char **argv)
{
	/* 
	Create seeker object
	Constructor will initialize ROS node, subscribe to target pose, and advertise the seeker's cmd_vel topic
	*/
	ros::init(argc, argv, "seek_turtle_node");
	Seeker seeker;
	seeker.runSeekerLoop();
	return 0;
}
	
