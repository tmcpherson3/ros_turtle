#include "Seeker.h"

Seeker::Seeker()
{	
	// Initialize ROS node	
	ros::init(argc, argv, "seek_turtle_node");
	
	// Get node handle
	// ros::NodeHandle n; <-- declared in header

	// Subscribe to first turtle pose
	poseSub = n.subscribe("turtle1/Pose", 10, &Seeker::computeAndPublishVelCmd, this);

	// Advertise cmd_vel topic for seeker turtle
	seekerCmdPub = n.advertise<geomerty_msgs::Twist>("turtle2/cmd_vel", 10);
	
	ROS_INFO("Seeker Turtle Initialized");
}

void Seeker::runSeekerLoop()
{
	ros::spin();
}

void computeAndPublishVelCmd(turtlesim::Pose p)
{
	// placeholder for real algorithm
	// just copy the other turtle for now
	
}